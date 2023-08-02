#ifndef BASE_CAMP_LIBRARY_H
#define BASE_CAMP_LIBRARY_H

#include <filesystem>
#include <string>

void DisplayDirectoryTree(const std::filesystem::path& pathToScan, std::string to_find, int level = 0, int counter = 0);

#endif
