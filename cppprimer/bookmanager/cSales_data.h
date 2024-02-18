#ifndef CSALES_DATA_H
#define CSALES_DATA_H
#include<string>
struct Sales_data{
    std::string bookNo;
    int units_sold = 0;
    double revenue = 0.0;
};
#endif