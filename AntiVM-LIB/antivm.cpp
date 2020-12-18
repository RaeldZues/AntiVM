#include <Windows.h>
#include <intrin.h>
#include <iostream>
#include <sstream>
#include <string.h>

BOOL isGuestOSVM()
{
    DWORD cpuInfo[4];
    __cpuid((int*)cpuInfo, 1);
    return ((cpuInfo[2] >> 31) & 1) == 1;
}

// reference to string to place version name in 
BOOL VersionCompare(std::string version)
{     
    DWORD cpuInfo[4];
    __cpuid((int*)cpuInfo, 0x40000000);
    std::stringstream ss;
    ss << std::hex << cpuInfo[3];
    ss << std::hex << cpuInfo[2];
    ss << std::hex << cpuInfo[1];
    std::string data = ss.str();
    return data.compare(version);
}

//int main()
//{
//    // Currently works on vmware and hyperv 
//    std::string HyperV("76482074666f736f7263694d");
//    std::string VmWare("657261774d56657261774d56");
//    
//    std::cout << HyperV << " is " << VersionCompare(HyperV) << "\n";
//    std::cout << VmWare << " is " << VersionCompare(VmWare) << "\n";
//    return 0;
//}

