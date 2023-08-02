#include "directory_tree.h"
#include <iostream>
#include <filesystem>

using namespace std;

int main(int argc, char* argv[])
{
	const filesystem::path pathToShow{"/"};

	DisplayDirectoryTree(pathToShow, argv[1]);
	
	return 0;
}
