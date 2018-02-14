#include <iostream>
#include <Windows.h>
#include <direct.h>
#include <string>

#define DIV 1024
#define WIDTH 7

using namespace std;

class CheckResources
{
public:
	static bool IsOnlyInstance(LPCTSTR gameTitle);
	static bool CheckStorage(const DWORDLONG diskSpaceNeeded);
	static bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded);
	static DWORD ReadCPUSpeed();
	static string ReadCPUArchitecture();
	static void PrintResults();
};