using System;

namespace RouteHelperTester
{
    public class RouteHelperTester
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("Best Interface: {0}", NativeMethods.GetBestInterface("114.114.114.114"));

            Environment.Exit(0);
        }
    }
}
