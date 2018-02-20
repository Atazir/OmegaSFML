#include <tchar.h>
#include "Engine.hpp"
#include "CheckResources.hpp"

int main(int argc, _TCHAR* argv[])
{
	//Checks resources and prints them.

	Omega::Initialize();
	CheckResources::PrintResults();
	Omega::Start();

	return 0;
}