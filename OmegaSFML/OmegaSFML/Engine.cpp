#include "Engine.hpp"

using namespace std;

bool IsOnlyInstance(LPCTSTR gameTitle);
bool CheckStorage(const DWORDLONG diskSpaceNeeded);
bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded);
string ReadCPUArchitecture();

Omega::GameState Omega::_gameState;
RenderWindow Omega::_mainWindow;
GameObjectManager Omega::_gameObjectManager;
PhysicsManager Omega::_physicsManager;

void Omega::Initialize(void)
{
	_gameState = ShowingSplash;
	_mainWindow.create(sf::VideoMode(1920, 1080, 32), "OmegaGame");
	WindowManager::Show(_mainWindow);

	if (IsOnlyInstance("Omega"))
	{
		cout << "This is the only instance." << endl;
	}
	else
	{
		return;
	}

	cout << "Checking storage..." << endl;
	if (CheckStorage(500000000))		//500mb required space for Engine/Game to exist on this machine. Likely never require all of it.
	{
		cout << "Enough Storage." << endl;
	}
	else
	{
		return;
	}

	cout << "Checking Memory..." << endl;
	if (CheckMemory(1000000000, 1000000000))	//1gb requirements for virtual and physical, likely will never need this much of either. 
	{
		cout << "Enough Memory." << endl;
	}
	else
	{
		return;
	}

	Sleep(1000 * 5);
	cout << "Starting" << endl;
	Omega::Start();
}

void Omega::Start(void)
{
	if (_gameState == Uninitialized)
	{
		return;
	}

	//Call other Awake functions for required pieces of the Engine here.
	_gameObjectManager.Awake();
	_physicsManager.Awake();

	//Call other Start functions for required pieces of the Engine here.
	_gameObjectManager.Start();
	_physicsManager.Start();

	//Clear the splash screen once the game starts.
	_gameState = Playing;
	_mainWindow.clear();
	_mainWindow.display();

	//Create a clock that begins keeping track of elapsed time on creation.
	sf::Clock t_clock;

	//Create the player object from the object manager, which has proper components attached.
	
	GameObject* playerObject = _gameObjectManager.CreateObject();

	//Create an enemy/interactable physics-wise character in the world with the player.
	
	//GameObject* opponentObject = _gameObjectManager.CreateObject();

	/*sf::Music music;

	if (!music.openFromFile("Audio/MainTrack.ogg"))
	{
		return;
	}

	//music.setLoop(true);

	music.play();
	*/

	while (_gameState != Exiting)
	{
		sf::Time elapsed = t_clock.restart();
		GameLoop(elapsed);
	}

	_mainWindow.close();
}

void Omega::GameLoop(sf::Time time)
{
	///If 'x' is pressed in corner, sets the game mode to Exiting and closes the window.
	while (_mainWindow.isOpen()) 
	{
		//WindowManager::Show(_mainWindow);

		//update systems
		_gameObjectManager.Update(0);
		_physicsManager.Update(0);

		//later update all systems
		_gameObjectManager.LateUpdate(0);
		_physicsManager.LateUpdate(0);

		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (_mainWindow.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
			{
				_gameState = Exiting;
				cout << "Exiting..." << endl;
				_mainWindow.close();
				exit(0);
			}
		}
	}
}

#pragma region Requirements Check

bool IsOnlyInstance(LPCTSTR gameTitle)
{
	HANDLE handle = CreateMutex(NULL, TRUE, gameTitle);
	if (GetLastError() != ERROR_SUCCESS)
	{
		HWND hWnd = FindWindow(gameTitle, NULL);
		return false;
	}
	return true;
}

bool CheckStorage(const DWORDLONG diskSpaceNeeded)
{
	// Check for enough free disk space on the current disk.
	int const drive = _getdrive();
	struct _diskfree_t diskfree;
	_getdiskfree(drive, &diskfree);
	unsigned __int64 const neededClusters = diskSpaceNeeded / (diskfree.sectors_per_cluster*diskfree.bytes_per_sector);

	if (diskfree.avail_clusters < neededClusters)
	{
		// if you get here you don’t have enough disk space!
		cout << "CheckStorage Failure : Not enough physical storage." << endl;
		return false;
	}
	return true;
}

bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded)
{
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	GlobalMemoryStatusEx(&status);

	if (status.ullTotalPhys < physicalRAMNeeded)
	{
		/*You don’t have enough physical memory. Tell the
		player to go get a real computer and give this one to
		his mother.*/
		cout << "CheckMemory Failure : Not enough physical memory." << endl;
		return false;
	}


	// Check for enough free memory.
	if (status.ullAvailVirtual < virtualRAMNeeded)
	{
		// you don’t have enough virtual memory available.
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
		// even though there is enough memory, it isn’t available in one block, which can be critical for games that manage their own memory
		cout << "CheckMemory Failure : Not enough contiguous memory." << endl;
		return false;
	}
}

string ReadCPUArchitecture()
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

#pragma endregion
