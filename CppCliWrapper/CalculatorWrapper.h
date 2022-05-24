#pragma once
#include <string>

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
   CalculatorWrapper(const double& fpNum1, const double& fpNum2);
   ~CalculatorWrapper();

   int Add(const int& arg1, const int& arg2) const;
   double Add(const double& arg1, const double& arg2) const;
   double NonStaticAdd() const;
   std::string Concat(const std::string& arg1, const std::string& arg2) const;
};

