#include "pch.h"
#include "CalculatorWrapper.h"
#include <vcclr.h>

class CalculatorPimpl
{
   gcroot<CsLibrary::Calculator^> _calculator;
public:
   CalculatorPimpl(double fpNum1, double fpNum2)
      :_calculator(gcnew CsLibrary::Calculator(fpNum1, fpNum2))
   {
   }

   int Add(int arg1, int arg2)
   {
      return _calculator->Add(arg1, arg2);
   }

   double Add(double arg1, double arg2)
   {
       return _calculator->Add(arg1, arg2);
   }

   double NonStaticAdd()
   {
       return _calculator->NonStaticAdd();
   }
};

CalculatorWrapper::CalculatorWrapper(double fpNum1, double fpNum2)
   :pimpl(new CalculatorPimpl(fpNum1, fpNum2))
{
}

CalculatorWrapper::~CalculatorWrapper()
{
   delete pimpl;
}

int CalculatorWrapper::Add(int arg1, int arg2)
{
   return pimpl->Add(arg1, arg2);
}

double CalculatorWrapper::Add(double arg1, double arg2)
{
    return pimpl->Add(arg1, arg2);
}

double CalculatorWrapper::NonStaticAdd()
{
    return pimpl->NonStaticAdd();
}
