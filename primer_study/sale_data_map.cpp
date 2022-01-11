//
//  sale_data_map.cpp
//  primer_study
//
//  Created by 申皓方 on 2022/1/10.
//

#include <stdio.h>
#include <vector>
#include <string>

#include "sale_data.h"
#include "sale_data_map.h"

extern const int maxWidth;

void setSalesDataMapKV(SalesDataMap * const saleDataMap, const SalesDataKV &kv){
    size_t fullIdx = calKeyFullIdx(kv.key);
    size_t idx = calKeyIdx(fullIdx, saleDataMap->keyWidth);
    
    if ((saleDataMap->valArr+idx) == nullptr || (saleDataMap->valArr+idx)->key.empty()){
        saleDataMap->valIdx.push_back(idx);
        saleDataMap->length++;
    }
    // 这里暂不考虑idx碰撞问题，因为keyWidth是有限的所以肯定可能有碰撞（即不同key按最大keyWidth算出的idx相同）
    // 理论上要更好的解决碰撞 可以在碰撞处idx下再做下级SalesDataMap，然后将两key截掉后半截（当前最大keyWidth能mask到的长度），将各自剩余的字符串当作key继续分配，直到递归的找到最终归宿（只要key不同一定可以在某一层SalesDataMap找到一个不同的idx）
    // 这里简单做一下就不搞那么复杂了，毕竟往后学肯定会学到c++的hash结构，这里是还没学到的时候自己造个小轮子
    *(saleDataMap->valArr+idx) = kv;
}

void FreeSaleDataMapVal(SalesDataMap * const saleDataMap){
    delete [] saleDataMap->valArr;
    saleDataMap->valArr = nullptr;
}

void refreshSalesDataMap(SalesDataMap * const saleDataMap){
    if (saleDataMap->keyWidth == 0){
        saleDataMap->keyWidth = 10;
    }
    if (saleDataMap->keyWidth > maxWidth){
        saleDataMap->keyWidth = maxWidth;
    }
    
    SalesDataKV *valArr = saleDataMap->valArr;
    std::vector<size_t> valIdx(saleDataMap->valIdx);
    size_t arrLen = (1 << saleDataMap->keyWidth) - 1;
    
//    c++里结构体别malloc，用new，不然就容易悲剧：EXC_BAD_ACCESS
//    saleDataMap.valArr = (SalesDataKV *)malloc(arrLen*sizeof(SalesDataKV));
    saleDataMap->valArr = new SalesDataKV[arrLen];
    saleDataMap->length = 0;
    saleDataMap->valIdx.clear();
    
    for (auto bitr = valIdx.cbegin(); bitr != valIdx.cend(); ++bitr) {
        setSalesDataMapKV(saleDataMap, *(valArr+(*bitr)));
    }
    if (saleDataMap->length > 0){
        // free(valArr)
        delete [] valArr;
        valArr = nullptr;
    }
}

void SalesDataMapStore(SalesDataMap * const saleDataMap, const std::string &key, const SalesData &saleData){
    if (key.empty()){
        return;
    }
    if (saleDataMap->valArr == nullptr){
        refreshSalesDataMap(saleDataMap);
    }
    
    size_t fullIdx = calKeyFullIdx(key);
    size_t idx = calKeyIdx(fullIdx, saleDataMap->keyWidth);
    
    if (saleDataMap->valArr+idx != nullptr && (!(saleDataMap->valArr+idx)->key.empty()) && (saleDataMap->valArr+idx)->key != key){
        std::string conflictKey = (saleDataMap->valArr+idx)->key;
        size_t conflictFullIdx = calKeyFullIdx(conflictKey);
        for (++(saleDataMap->keyWidth), idx = calKeyIdx(fullIdx, saleDataMap->keyWidth); calKeyIdx(conflictFullIdx, saleDataMap->keyWidth) == idx; ++(saleDataMap->keyWidth), idx = calKeyIdx(fullIdx, saleDataMap->keyWidth)){
            if (saleDataMap->keyWidth >= maxWidth || idx >= SIZE_T_MAX - 1){
                break;
            }
        }
        
        refreshSalesDataMap(saleDataMap);
    }
    
    SalesDataKV kv = SalesDataKV{
        .key = std::string(key),
        .val = SalesData(saleData)
    };
    setSalesDataMapKV(saleDataMap, kv);
}

SalesDataGet SalesDataMapGet(SalesDataMap * const saleDataMap, const std::string &key){
    SalesDataGet res = SalesDataGet{
        .Exist = false,
        .Val = SalesData{}
    };
    if (key == "" || saleDataMap->keyWidth == 0){
        return res;
    }
    
    size_t fullIdx = calKeyFullIdx(key);
    size_t idx = calKeyIdx(fullIdx, saleDataMap->keyWidth);
    if (saleDataMap->valArr+idx != nullptr && (saleDataMap->valArr+idx)->key == key){
        res.Exist = true;
        res.Val = (saleDataMap->valArr+idx)->val;
    }
    return res;
}

void SalesDataMapDelByKey(SalesDataMap * const saleDataMap, const std::string &key){
    auto getRes = SalesDataMapGet(saleDataMap, key);
    if (!getRes.Exist) {
        return;
    }
    size_t fullIdx = calKeyFullIdx(key);
    size_t idx = calKeyIdx(fullIdx, saleDataMap->keyWidth);
    (saleDataMap->valArr+idx)->key = "";
    for (std::vector<size_t>::const_iterator itr = saleDataMap->valIdx.cbegin(); itr != saleDataMap->valIdx.cend(); ++itr){
        if (*itr == idx){
            saleDataMap->valIdx.erase(itr);
        }
    }
    -- saleDataMap->length;
}

bool ForeachSalesDataMap(SalesDataMap * const saleDataMap, bool (* eachFunc)(const std::string &key, const SalesData &item)){
    for (auto bitr = saleDataMap->valIdx.cbegin(); bitr != saleDataMap->valIdx.cend(); ++bitr) {
        if (!eachFunc((saleDataMap->valArr+(*bitr))->key, (saleDataMap->valArr+(*bitr))->val)){
            return false;
        }
    }
    return true;
}
