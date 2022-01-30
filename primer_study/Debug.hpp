//
//  Debug.hpp
//  primer_study
//
//  Created by 申皓方 on 2022/1/26.
//

#ifndef Debug_hpp
#define Debug_hpp

#include <stdio.h>

class Debug {
private:
    int hw;
    int io;
    int other;
public:
    constexpr Debug(int hwLevel, int ioLevel, int otherLevel): hw(hwLevel), io(ioLevel), other(otherLevel){}
    constexpr Debug(int level = 0): Debug(level, level, level){}
    void SetHW(int level){hw = level;}
    void SetIO(int level){io = level;}
    void SetOther(int level){other = level;}
};

#endif /* Debug_hpp */
