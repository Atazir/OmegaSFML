#include <tchar.h>
#include "Engine.hpp"
//#include "CheckResources.hpp"

int main(int argc, _TCHAR* argv[])
{
	//Checks resources and prints them.
	//CheckResources::PrintResults();

	Omega::Initialize();
	Omega::Start();

	return 0;
}