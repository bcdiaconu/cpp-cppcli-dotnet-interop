#pragma once

#ifdef DLL_EXPORT
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

class CalculatorPimpl;

class DLL_API CalculatorWrapper
{
   CalculatorPimpl* pimpl;   

public:
   CalculatorWrapper(double fpNum1, double fpNum2);
   ~CalculatorWrapper();

   int Add(int arg1, int arg2);
   double Add(double arg1, double arg2);
   double NonStaticAdd();
   //std::string Concat(string arg1, string arg2)
};

