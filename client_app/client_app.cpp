// client_app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CalculatorWrapper.h"
#include <iostream>

int main()
{
    CalculatorWrapper calculatorWrapper(13.45, 4675.3);
    std::cout << "14 + 39 = " << calculatorWrapper.Add(14,39) << std::endl;
    std::cout << "45.6 + 467.64 = " << calculatorWrapper.Add(45.6, 467.64) << std::endl;
    std::cout << "NonStaticAdd = " << calculatorWrapper.NonStaticAdd() << std::endl;
    std::cout << "ConcatStrings = " << calculatorWrapper.Concat("String1", "string2");
}
