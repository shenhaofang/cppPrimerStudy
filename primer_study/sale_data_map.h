    //
    //  shf_string_map.h
    //  primer_study
    //
    //  Created by 申皓方 on 2021/12/29.
    //

#ifndef sale_data_map_h
#define sale_data_map_h

#include <vector>
#include "sale_data.h"

struct SalesDataKV {
    SalesData val;
    std::string key;
};

struct SalesDataMap {
    int keyWidth = 0;
    size_t length = 0;
    SalesDataKV *valArr = nullptr;
    std::vector<size_t> valIdx = {};
};

struct SalesDataGet {
    bool Exist;
    SalesData Val;
};

inline int BitWidth(size_t c) {
    int length = 1;
    for (size_t cl = c >> 1; cl > 0; cl >>= 1){
        ++ length;
    }
    return length;
}

const int maxWidth = BitWidth(SIZE_T_MAX) - 1;

inline size_t calKeyFullIdx(const std::string &key){
    size_t res = 0;
    for (char kv : key) {
        size_t cWidth = BitWidth(kv);
        if (res >= (SIZE_T_MAX >> cWidth) - 1){
            break;
        }
        res <<= cWidth;
        res |= kv;
    }
    return res;
}

inline size_t calKeyIdx(size_t keyFullIdx, int keyWidth) {
    return keyFullIdx & ((1 << keyWidth) - 1);
}

void setSalesDataMapKV(SalesDataMap &saleDataMap, SalesDataKV * kv);

void FreeSaleDataMapVal(SalesDataMap * const saleDataMap);

void refreshSalesDataMap(SalesDataMap * const saleDataMap);

void setSalesDataMapKV(SalesDataMap * const saleDataMap, SalesDataKV * kv);

void SalesDataMapStore(SalesDataMap * const saleDataMap, const std::string &key, const SalesData &saleData);

SalesDataGet SalesDataMapGet(SalesDataMap * const saleDataMap, const std::string &key);

bool ForeachSalesDataMap(SalesDataMap * const saleDataMap, bool (* eachFunc)(const std::string &key, const SalesData &item));
#endif /* sale_data_map_h */
