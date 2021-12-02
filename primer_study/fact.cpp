//
//  fact.cpp
//  primer_study
//
//  Created by 申皓方 on 2021/12/1.
//

#include "fact.hpp"
#include "stdexcept"

int fact(int n){
    if (n < 0){
        char s[200];
        sprintf(s, "negative num(%d) can not fact", n);
        throw std::runtime_error(s);
        return 0;
    }
    int res = 1;
    for (; n > 0;  --n){
        res *= n;
    }
    return res;
}
