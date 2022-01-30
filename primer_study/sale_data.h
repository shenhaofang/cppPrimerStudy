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
    friend bool ReadSalesData(std::istream &inputStream,  SalesData &data);
    friend void printSaleData(std::ostream &outStream, const SalesData &item);
    friend SalesData CombineSaleData(const SalesData &item, const SalesData &itemToAdd);
    friend std::istream &readSalesData(std::istream &is, SalesData &data);
    friend std::ostream &printSalesData(std::ostream &os, const SalesData &item);
    friend SalesData SaleDataAdd (const SalesData &item, const SalesData &itemToAdd);
private:
    std::string BookNo;
    unsigned UnitsSold = 0;
    double Revenue = 0.0;
    double AvgPrice = 0.0;
public:
    std::string Isbin(){
        return BookNo;
    }
    unsigned GetUnitsSold(){
        return UnitsSold;
    }
    double GetRevenue(){
        return Revenue;
    }
    SalesData &Combine(const SalesData &item);
    double GetAvgPrice(){
        AvgPrice = Revenue/UnitsSold;
        return AvgPrice;
    }
    SalesData(const std::string &bookNo, double price, unsigned num): BookNo(bookNo), AvgPrice(price), UnitsSold(num), Revenue(price * num) {
        std::cout << "construct with 3 params" << std::endl;
    }
    SalesData(const std::string &bookNo): SalesData(bookNo, 0, 0){
        std::cout << "construct with 1 param" << std::endl;
    }
    SalesData():SalesData(""){
        std::cout << "default construction" << std::endl;
    }
    SalesData(std::istream &is): SalesData(){
        std::cout << "construct with input stream" << std::endl;
        if (!(is >> BookNo)){
            return;
        }
        if (BookNo == "-") {
            is.clear();
            is.sync();
            return;
        }
        is >> AvgPrice >> UnitsSold;
        Revenue = AvgPrice * UnitsSold;
    };
};

bool ReadSalesData(std::istream &inputStream,  SalesData &data);

void printSaleData(std::ostream &outStream, const SalesData &item);

SalesData CombineSaleData(const SalesData &item, const SalesData &itemToAdd);

std::istream &readSalesData(std::istream &is, SalesData &data);

std::ostream &printSalesData(std::ostream &os, const SalesData &item);

SalesData SaleDataAdd (const SalesData &item, const SalesData &itemToAdd);

#endif /* sale_data_h */
