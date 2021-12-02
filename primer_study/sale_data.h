//
//  sale_data.h
//  primer_study
//
//  Created by 申皓方 on 2021/10/21.
//

#ifndef sale_data_h
#define sale_data_h

struct SalesData {
    std::string bookNo;
    unsigned unitsSold = 0;
    double revenue = 0.0;
    double price = 0.0;
};

#endif /* sale_data_h */
