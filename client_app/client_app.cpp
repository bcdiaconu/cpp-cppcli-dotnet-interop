// client_app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CalculatorWrapper.h"
#include <iostream>

int main()
{
    CalculatorWrapper widget;
    std::cout << "14+39=" << widget.Add(14,39);

}
