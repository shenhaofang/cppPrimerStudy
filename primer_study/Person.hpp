//
//  Person.hpp
//  primer_study
//
//  Created by 申皓方 on 2022/1/12.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <string>
#include <iostream>

struct Person {
    std::string Name;
    std::string Addr;
    std::string getName() const {
        return Name;
    };
    std::string getAddr() const{
        return Addr;
    };
};

std::istream &ReadPerson(std::istream &is, Person &p);
std::ostream &PrintPerson(std::ostream &os, const Person &p);

#endif /* Person_hpp */
