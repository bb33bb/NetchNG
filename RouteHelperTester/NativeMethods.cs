using System.Runtime.InteropServices;

namespace RouteHelperTester
{
    public static class NativeMethods
    {
        [DllImport("RouteHelper", CallingConvention = CallingConvention.Cdecl, EntryPoint = "GetBestInterfaceE")]
        public static extern int GetBestInterface(string address);

        [DllImport("RouteHelper", CallingConvention = CallingConvention.Cdecl, EntryPoint = "CreateRouteE")]
        public static extern bool CreateRoute(string address, int netmask, string gateway, int index, int metric = 0);

        [DllImport("RouteHelper", CallingConvention = CallingConvention.Cdecl, EntryPoint = "DeleteRouteE")]
        public static extern bool DeleteRoute(string address, int netmask, string gateway, int index, int metric = 0);
    }
}
