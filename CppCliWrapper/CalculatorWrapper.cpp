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
        auto chars = (const char*)(Marshal::StringToHGlobalAnsi(sys_string)).ToPointer();
        std::string os = chars;
        Marshal::FreeHGlobal(System::IntPtr((void*)chars));

        return os;
    }

    static std::wstring mapSystemToWstring(System::String^ sys_string)
    {
        using namespace System::Runtime::InteropServices;
        auto chars = (const wchar_t*)(Marshal::StringToHGlobalUni(sys_string)).ToPointer();
        std::wstring os = chars;
        Marshal::FreeHGlobal(System::IntPtr((void*)chars));

        return os;
    }

public:
    CalculatorPimpl(const double& fpNum1, const double& fpNum2)
        :_calculator(gcnew CsLibrary::Calculator(fpNum1, fpNum2))
    {
    }

    int Add(const int& arg1, const int& arg2) const
    {
        return _calculator->Add(arg1, arg2);
    }

    double Add(const double& arg1, const double& arg2) const
    {
        return _calculator->Add(arg1, arg2);
    }

    double NonStaticAdd() const
    {
        return _calculator->NonStaticAdd();
    }

    std::string Concat(const std::string& arg1, const std::string& arg2) const
    {
        auto managedArg1 = mapStdToSystemString(arg1);
        auto managedArg2 = mapStdToSystemString(arg2);

        auto managedResultString = _calculator->Concat(managedArg1, managedArg2);

        return mapSystemToStdString(managedResultString);
    }
};

CalculatorWrapper::CalculatorWrapper(const double& fpNum1, const double& fpNum2)
    :pimpl(std::make_unique<CalculatorPimpl>(fpNum1, fpNum2))
{
}

CalculatorWrapper::~CalculatorWrapper()
{ }

int CalculatorWrapper::Add(const int& arg1, const int& arg2) const
{
    return pimpl->Add(arg1, arg2);
}

double CalculatorWrapper::Add(const double& arg1, const double& arg2) const
{
    return pimpl->Add(arg1, arg2);
}

double CalculatorWrapper::NonStaticAdd() const
{
    return pimpl->NonStaticAdd();
}

std::string CalculatorWrapper::Concat(const std::string& arg1, const std::string& arg2) const
{
    return pimpl->Concat(arg1, arg2);
}
