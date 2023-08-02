#include "directory_tree.h"
#include <iostream>
#include <filesystem>
#include <string>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

bool found_check = false;

mutex found_check_mutex;

void DisplayDirectoryTree(const filesystem::path& pathToScan, string to_find, int level, int counter) 
{
	if(found_check)
	{
		return;
	}

	vector<thread> threads;

	try
	{
		for (const auto& entry : filesystem::directory_iterator(pathToScan)) 
		{
			const auto filenameStr = entry.path().filename().string();

			if(entry.is_regular_file() && filenameStr == to_find)
			{
				found_check_mutex.lock();
				if(!found_check)
				{
					cout << "File found with path: " << entry.path() << endl;
					found_check = true;
				}
				found_check_mutex.unlock();
			}

			else if (entry.is_directory()) 
			{
				if(counter == 8)
				{
					for (auto& thread : threads)
					{
						thread.join();
					}
				}
				threads.emplace_back(DisplayDirectoryTree, entry, to_find, level + 1, counter + 1);
			}
		}
	}

	catch(...) {}

    for (auto& thread : threads) 
    {
        thread.join();
    }
}