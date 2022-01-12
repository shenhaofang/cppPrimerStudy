//
//  sale_data.h
//  primer_study
//
//  Created by 申皓方 on 2021/10/21.
//

#ifndef sale_data_h
#define sale_data_h

#include <iostream>
#include <string>

struct SalesData {
    std::string BookNo;
    unsigned UnitsSold = 0;
    double Revenue = 0.0;
    double AvgPrice = 0.0;
    std::string Isbin(){
        return BookNo;
    };
    SalesData &Combine(const SalesData &item);
};

bool ReadSalesData(std::istream &inputStream,  SalesData &data);

void printSaleData(std::ostream &outStream, const SalesData &item);

SalesData CombineSaleData(const SalesData &item, const SalesData &itemToAdd);

std::istream &readSalesData(std::istream &is, SalesData &data);

std::ostream &printSalesData(std::ostream &os, const SalesData &item);

SalesData SaleDataAdd (const SalesData &item, const SalesData &itemToAdd);

#endif /* sale_data_h */
