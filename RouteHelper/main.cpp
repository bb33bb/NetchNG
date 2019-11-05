#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <iostream>

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <netioapi.h>
#include <iphlpapi.h>

using namespace std;

#define DLLEXPORT extern "C" __declspec(dllexport)

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_PROCESS_DETACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}

	return TRUE;
}

MIB_IPFORWARD_ROW2 GetRouteE(const char* address, int netmask, const char* gateway, int index, int metric)
{
	MIB_IPFORWARD_ROW2 row = { 0 };
	row.InterfaceIndex = index;
	row.DestinationPrefix.Prefix.si_family = row.NextHop.si_family = AF_INET;
	row.DestinationPrefix.Prefix.Ipv4.sin_addr.S_un.S_addr = inet_addr(address);
	row.DestinationPrefix.PrefixLength = netmask;
	row.NextHop.Ipv4.sin_addr.S_un.S_addr = inet_addr(gateway);
	row.ValidLifetime = 0xffffffff;
	row.PreferredLifetime = 0xffffffff;
	row.Metric = metric;
	row.Protocol = MIB_IPPROTO_NETMGMT;

	return row;
}

DLLEXPORT INT GetBestInterfaceE(const char* address, unsigned long* index)
{
	SOCKADDR_INET destination = { 0 };
	MIB_IPFORWARD_ROW2 bestRoute = { 0 };
	SOCKADDR_INET bestSource = { 0 };

	if (inet_pton(AF_INET, address, &destination.Ipv4.sin_addr))
	{
		destination.si_family = AF_INET;
		destination.Ipv4.sin_family = AF_INET;
	}
	else if (inet_pton(AF_INET6, address, &destination.Ipv6.sin6_addr))
	{
		destination.si_family = AF_INET6;
		destination.Ipv6.sin6_family = AF_INET6;
	}
	else
	{
		return -1;
	}

	if (NO_ERROR == GetBestRoute2(NULL, NULL, NULL, &destination, NULL, &bestRoute, &bestSource))
	{
		return bestRoute.InterfaceIndex;
	}

	return 0;
}

DLLEXPORT BOOL CreateRouteE(const char* address, int netmask, const char* gateway, int index, int metric = 0)
{
	return (CreateIpForwardEntry2(&GetRouteE(address, netmask, gateway, index, metric)) == NO_ERROR) ? TRUE : FALSE;
}

DLLEXPORT BOOL DeleteRouteE(const char* address, int netmask, const char* gateway, int index, int metric = 0)
{
	return (DeleteIpForwardEntry2(&GetRouteE(address, netmask, gateway, index, metric)) == NO_ERROR) ? TRUE : FALSE;
}
