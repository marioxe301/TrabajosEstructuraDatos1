using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace DLLTest
{
    class Program
    {

        [DllImport("C:\\Users\\Mario Flores JR\\source\\repos\\MetodosPrueba\\Debug\\MetodosPrueba.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern double SumaNormal(double a, double b);


   

        static void Main(string[] args)
        {
            double num1 = 5;
            double num2 = 4;

            double a = SumaNormal(num1, num2);
            Console.Write(a);
        }
    }
}
