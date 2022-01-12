//
//  sale_data.cpp
//  primer_study
//
//  Created by 申皓方 on 2022/1/10.
//

#include <stdio.h>
#include <iostream>

#include "sale_data.h"

bool ReadSalesData(std::istream &inputStream, SalesData &data){
    if (inputStream >> data.BookNo >> data.UnitsSold >> data.Revenue){
        data.AvgPrice = data.Revenue/data.UnitsSold;
        return true;
    }
    return false;
}

void printSaleData(std::ostream &outStream, const SalesData &item){
    outStream << "BookNO: " << item.BookNo << ", Revenue: " << item.Revenue << "( " << item.AvgPrice << " x " << item.UnitsSold << ")" << std::endl;
}

std::istream &readSalesData(std::istream &is, SalesData &data){
    if (is >> data.BookNo >> data.UnitsSold >> data.Revenue){
        data.AvgPrice = data.Revenue/data.UnitsSold;
    }
    return is;
}

std::ostream &printSalesData(std::ostream &os, const SalesData &item){
    return os << "BookNO: " << item.BookNo << ", Revenue: " << item.Revenue << "( " << item.AvgPrice << " x " << item.UnitsSold << ")";
}

SalesData SaleDataAdd (const SalesData &item, const SalesData &itemToAdd){
    SalesData res = item;
    res.Combine(itemToAdd);
    return res;
}

SalesData CombineSaleData(const SalesData &item, const SalesData &itemToAdd){
    if (item.BookNo == "" || itemToAdd.BookNo != item.BookNo){
        return item;
    }
    SalesData res = SalesData{
        .BookNo = item.BookNo
    };
    res.UnitsSold = item.UnitsSold + itemToAdd.UnitsSold;
    res.Revenue = item.Revenue + itemToAdd.Revenue;
    res.AvgPrice = res.Revenue/res.UnitsSold;
    return res;
}

SalesData &SalesData::Combine(const SalesData &item){
    if (BookNo == "" || BookNo == item.BookNo){
        UnitsSold += item.UnitsSold;
        Revenue += item.Revenue;
        AvgPrice = Revenue/UnitsSold;
    }
    return *this;
}
