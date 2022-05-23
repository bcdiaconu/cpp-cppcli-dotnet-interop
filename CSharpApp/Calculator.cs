using System;

namespace CsLibrary
{
    public class Calculator
    {
        private readonly double _fpNum1;
        private readonly double _fpNum2;

        public Calculator(double fpNum1, double fpNum2)
        {
            _fpNum1 = fpNum1;
            _fpNum2 = fpNum2;
        }

        public static int Add(int arg1, int arg2)
            => arg1 + arg2;

        public static double Add(double arg1, double arg2)
            => arg1 + arg2;

        public static string Concat(string arg1, string arg2)
            => arg1 + arg2;

        public double NonStaticAdd()
            => _fpNum1 + _fpNum2;
    }
}
