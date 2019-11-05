using System;
using System.Text;

namespace RouteHelperTester
{
    public class RouteHelperTester
    {
        public static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.GetEncoding(936);

            Console.WriteLine("最佳适配器：{0}", NativeMethods.GetBestInterface("114.114.114.114"));
            Console.ReadLine();
        }
    }
}
