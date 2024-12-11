#include <conio.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>

namespace fs = std::filesystem;
unsigned int saveCounter = 0;
std::string logFileName = "miner.log";

void CheckAndSave(std::string lineToCheck, fs::path p)
{
	std::ofstream outputFile(p / "HashLogs.log", std::ios::out | std::ios::app);
	std::regex stringPattern("(speed 10s/60s/15m)");

	if (std::regex_search(lineToCheck, stringPattern))
	{
		if (!outputFile.is_open())
		{
			std::cout << "Couldn't find hash log, trying to generate a new one..."
					  << std::endl;

			outputFile.open(p / "HashLogs.log");
		}
		else if (outputFile.is_open())
		{
			outputFile << lineToCheck
					   << std::endl;

			std::cout << "Saved line #"
					  << saveCounter
					  << std::endl;

			++saveCounter;
		}
	}
}

void ReadFromFile()
{
	fs::path p;
	p = fs::current_path();	// in MSVC leads to only half the path being assigned, kinda works in the standalone

	std::cout << "Trying to find log file in " << p << "..." << std::endl;
	std::ifstream inputFile(p / logFileName);

	if (!inputFile.is_open())
	{
		std::cout << "Couldn't open file at given path!" << std::endl;
		return;
	}
	else if (inputFile.is_open())
	{
		std::cout << "Log file found and successfully opened!"
				  << std::endl;

		std::string line;
		int lineCounter = 1;

		while (std::getline(inputFile, line))
		{
			std::cout << "Checking line #"
					  << lineCounter
					  << " for hashing stats..."
					  << std::endl;

			CheckAndSave(line, p);
			++lineCounter;
		}
		inputFile.close();
	}
}

int main()
{
	std::cout << "Ready to read log file..."
			  << std::endl;

	_getch();

	ReadFromFile();

	std::cout << "\n"
			  << "<================== DONE ==================>"
			  << std::endl;

	system("pause");
	return 0;
}