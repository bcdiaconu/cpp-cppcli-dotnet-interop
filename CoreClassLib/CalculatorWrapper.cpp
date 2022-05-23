#include "pch.h"
#include "CalculatorWrapper.h"
#include <vcclr.h>

class CalculatorPimpl
{
   gcroot<CsLibrary::Calculator^> _calculator;
public:
   CalculatorPimpl()
      :_calculator(gcnew CsLibrary::Calculator(13.45,4675.3))
   {
   }

   int Add(int arg1, int arg2)
   {
      return _calculator->Add(arg1, arg2);
   }
};

CalculatorWrapper::CalculatorWrapper()
   :pimpl(new CalculatorPimpl())
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