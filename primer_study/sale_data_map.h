    //
    //  shf_string_map.h
    //  primer_study
    //
    //  Created by 申皓方 on 2021/12/29.
    //

#ifndef shf_string_map_h
#define shf_string_map_h

struct ShfStrMap {
    int charUnitLen;
    int length;
    int arrLen;
    int *valArr;
};

int CharLen(char c) {
    int len = 1;
    if (c == 0) {
        return len;
    }
    for (c >>= 1; c > 0; c >>= 1, ++len)
        ;
    return len;
}

int maxUnitLen(const std::string &key) {
    int charUnitLen = 1;
    for (char kv : key) {
        int charLen = CharLen(kv);
        if (charUnitLen < charLen) {
            charUnitLen = charLen;
        }
    }
    return charUnitLen;
}

int calKeyIdx(const std::string &key, int charUnitLen) {
    int res = 0;
    for (char kv : key) {
        res |= kv;
        res <<= charUnitLen;
    }
    return res;
}

void store(ShfStrMap &strMap, const std::string &key, 

#endif /* shf_string_map_h */
