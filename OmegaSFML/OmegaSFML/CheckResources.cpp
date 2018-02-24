#include <tchar.h>
#include "CheckResources.hpp"

using namespace std;

bool CheckResources::IsOnlyInstance(LPCTSTR gameTitle)
{
	HANDLE handle = CreateMutex(NULL, TRUE, gameTitle);
	if (GetLastError() != ERROR_SUCCESS)
	{
		HWND hWnd = FindWindow(gameTitle, NULL);
		return false;
	}
	return true;
}

bool CheckResources::CheckStorage(const DWORDLONG diskSpaceNeeded)
{
	// Check for enough free disk space on the current disk.
	int const drive = _getdrive();
	struct _diskfree_t diskfree;
	_getdiskfree(drive, &diskfree);
	unsigned __int64 const neededClusters = diskSpaceNeeded / (diskfree.sectors_per_cluster*diskfree.bytes_per_sector);

	if (diskfree.avail_clusters < neededClusters)
	{
		// if you get here you don�t have enough disk space!
		cout << "CheckStorage Failure : Not enough physical storage." << endl;
		return false;
	}
	return true;
}

bool CheckResources::CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded)
{
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	GlobalMemoryStatusEx(&status);

	if (status.ullTotalPhys < physicalRAMNeeded)
	{
		/*You don�t have enough physical memory. Tell the
		player to go get a real computer and give this one to
		his mother.*/
		cout << "CheckMemory Failure : Not enough physical memory." << endl;
		return false;
	}


	// Check for enough free memory.
	if (status.ullAvailVirtual < virtualRAMNeeded)
	{
		// you don�t have enough virtual memory available.
		// Tell the player to shut down the copy of Visual Studio running in the background.
		cout << "CheckMemory Failure : Not enough virtual memory." << endl;
		return false;
	}
	else
		return true;

	char *buff = new char[virtualRAMNeeded];

	if (buff)
		delete[] buff;
	else
	{
		// even though there is enough memory, it isn�t available in one block, which can be critical for games that manage their own memory
		cout << "CheckMemory Failure : Not enough contiguous memory." << endl;
		return false;
	}
}

DWORD CheckResources::ReadCPUSpeed()
{
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;

	// open the key where the proc speed is hidden:
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey);

	if (lError == ERROR_SUCCESS)
	{
		// query the key:
		RegQueryValueEx(hKey, "~MHz", NULL, &type, (LPBYTE)&dwMHz, &BufSize);
		cout << "CPU Speed is " << ((float)dwMHz * 0.001f) << "GHz." << endl;
	}
	return dwMHz;
}

string CheckResources::ReadCPUArchitecture()
{
	DWORD BufSize = 1024;
	char CPU[1024];
	string dwMHz;
	DWORD type = REG_SZ;
	HKEY hKey;

	//New function to determine architecture 
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey);

	if (lError == ERROR_SUCCESS)
	{
		RegQueryValueEx(hKey, "ProcessorNameString", NULL, NULL, (LPBYTE)&CPU, &BufSize);
	}

	cout << "Processor Type: " << CPU << endl;
	return string(CPU);
}

void CheckResources::PrintResults()
{
	cout << "Welcome to the Program" << endl << endl;

//Call to check for if there is more than one instance of the program running
if (CheckResources::IsOnlyInstance("Omega") == true)
cout << "There is only one instance running." << endl;
else
cout << "More than one instance running. Please exit this application." << endl;
cout << endl;

//Checking to ensure ample storage for program
if (CheckResources::CheckStorage(300000000) == true)
cout << "Storage: There is enough storage." << endl;
else
cout << "Storage: There is NOT enough storage available." << endl;
cout << endl;

MEMORYSTATUSEX statex;
statex.dwLength = sizeof(statex);
GlobalMemoryStatusEx(&statex);

if (CheckResources::CheckMemory(1000000, 1000000) == true)
cout << "Memory: There is enough RAM available for this program." << endl;
cout << endl;

//Display available memory in KB
_tprintf(TEXT("There are  %*I64d total KBs of physical memory.\n"), WIDTH, statex.ullTotalPhys / DIV);
_tprintf(TEXT("There are %*I64d total KBs of virtual memory.\n"), WIDTH, statex.ullTotalVirtual / DIV);
cout << endl;

//Run these functions
CheckResources::ReadCPUSpeed();
CheckResources::ReadCPUArchitecture();
}

void CheckResources::CheckRequirements()
{
	if (CheckResources::CheckStorage(536870912) && CheckResources::CheckMemory(1000000, 1000000))
	{
		return;
	}
	else
	{
		cout << "Not enough resources." << endl;
		exit(0);
	}
}