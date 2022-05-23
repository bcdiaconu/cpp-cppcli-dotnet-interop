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
   CalculatorWrapper();
   ~CalculatorWrapper();

   int Add(int arg1, int arg2);
};

