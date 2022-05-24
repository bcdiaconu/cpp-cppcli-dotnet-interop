#include "pch.h"
#include "CalculatorWrapper.h"
#include <vcclr.h>

class CalculatorPimpl
{
private:
    gcroot<CsLibrary::Calculator^> _calculator;

    static System::String^ mapStdToSystemString(const std::string& std_string)
    {
        return gcnew System::String(std_string.c_str());
    }

    static std::string mapSystemToStdString(System::String^ sys_string)
    {
        using namespace System::Runtime::InteropServices;
        auto chars = (const char*) (Marshal::StringToHGlobalAnsi(sys_string)).ToPointer();
        std::string os = chars;
        Marshal::FreeHGlobal(System::IntPtr((void*) chars));

        return os;
    }

    static std::wstring mapSystemToWstring(System::String^ sys_string)
    {

        using namespace System::Runtime::InteropServices;
        auto chars = (const wchar_t*) (Marshal::StringToHGlobalUni(sys_string)).ToPointer();
        std::wstring os = chars;
        Marshal::FreeHGlobal(System::IntPtr((void*) chars));

        return os;
    }

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
