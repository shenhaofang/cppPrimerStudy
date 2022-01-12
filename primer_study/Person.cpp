//
//  Person.cpp
//  primer_study
//
//  Created by 申皓方 on 2022/1/12.
//

#include "Person.hpp"

std::istream &ReadPerson(std::istream &is, Person &p){
    return is >> p.Name >> p.Addr;
}

std::ostream &PrintPerson(std::ostream &os, const Person &p){
    return os << "Person name: " << p.Name << ", address: " << p.Addr;
}
