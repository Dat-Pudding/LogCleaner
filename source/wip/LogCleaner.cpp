#include <conio.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include "Messenger.h"
#include "Converters.h"

Messenger messenger;
namespace fs = std::filesystem;
unsigned int saveCounter = 1;

void CheckAndSave(std::string lineToCheck, std::string outputFileName) // default to hashing logs when no filterMode is given
{
	Converters::HashLog::ToCSV converter;
	std::ofstream outputFile(outputFileName, std::ios::out | std::ios::app);
	std::regex stringPattern("(speed 10s/60s/15m)");

	if (std::regex_search(lineToCheck, stringPattern))
	{
		if (!outputFile.is_open())
		{
			messenger.ErrorMsg_BadDefaultOutput();
			outputFile.open(outputFileName);
		}
		else if (outputFile.is_open())
		{
			converter.Convert(lineToCheck, 1);
			std::string lineToOutput = converter.outputLine;
			outputFile << lineToOutput
					   << std::endl;

			messenger.StatusMsg_Saving(saveCounter);
			++saveCounter;
		}
	}
}
void CheckAndSave(std::string lineToCheck, std::string outputFileName, std::string filterMode)
{
	if (filterMode == "-h")
	{
		std::ofstream outputFile(outputFileName, std::ios::out | std::ios::app);
		std::regex stringPattern("(speed 10s/60s/15m)");

		if (std::regex_search(lineToCheck, stringPattern))
		{
			if (!outputFile.is_open())
			{
				messenger.ErrorMsg_BadOutput(filterMode);
				outputFile.open(outputFileName);
			}
			else if (outputFile.is_open())
			{
				outputFile << lineToCheck
						   << std::endl;

				messenger.StatusMsg_Saving(saveCounter);
				++saveCounter;
			}
		}
	}
	else if (filterMode == "-j")
	{
		std::ofstream outputFile(outputFileName, std::ios::out | std::ios::app);
		std::regex stringPattern("(new job from)");

		if (std::regex_search(lineToCheck, stringPattern))
		{
			if (!outputFile.is_open())
			{
				messenger.ErrorMsg_BadOutput(filterMode);
				outputFile.open(outputFileName);
			}
			else if (outputFile.is_open())
			{
				outputFile << lineToCheck
						   << std::endl;

				messenger.StatusMsg_Saving(saveCounter);
				++saveCounter;
			}
		}
	}
	else if (filterMode == "-s")
	{
		std::ofstream outputFile(outputFileName, std::ios::out | std::ios::app);
		std::regex stringPatternAccept("(accepted)");
		std::regex stringPatternReject("(rejected)");

		if (std::regex_search(lineToCheck, stringPatternAccept) || std::regex_search(lineToCheck, stringPatternReject))
		{
			if (!outputFile.is_open())
			{
				messenger.ErrorMsg_BadOutput(filterMode);
				outputFile.open(outputFileName);
			}
			else if (outputFile.is_open())
			{
				outputFile << lineToCheck
						   << std::endl;

				messenger.StatusMsg_Saving(saveCounter);
				++saveCounter;
			}
		}
	}
	else
	{
		return;
	}
}

void ReadFromFile(std::string logfilePath, std::string outputFileName) // default when no filterMode is given
{
	fs::path p;
	p = logfilePath;

	messenger.StatusMsg_Searching(logfilePath);
	std::ifstream inputFile(p);

	if (!inputFile.is_open())
	{
		messenger.ErrorMsg_BadPath();
		inputFile.open(logfilePath);
		return;
	}
	else if (inputFile.is_open())
	{
		std::string line;
		int lineCounter = 1;

		while (std::getline(inputFile, line))
		{
			messenger.StatusMsg_Checking(lineCounter);
			CheckAndSave(line, outputFileName);
			++lineCounter;
		}
		inputFile.close();
	}
}

void ReadFromFile(std::string logfilePath, std::string outputFileName, std::string filterMode)
{
	fs::path p;
	p = logfilePath;

	messenger.StatusMsg_Searching(logfilePath);
	std::ifstream inputFile(p);

	if (!inputFile.is_open())
	{
		messenger.ErrorMsg_BadPath();
		return;
	}
	else if (inputFile.is_open())
	{
		std::string line;
		int lineCounter = 1;

		while (std::getline(inputFile, line))
		{
			messenger.StatusMsg_Checking(lineCounter);
			CheckAndSave(line, outputFileName, filterMode);
			++lineCounter;
		}
		inputFile.close();
	}
}

int main(int argc, char* argv[])
{
	if (argc <= 2)
	{
		messenger.ErrorMsg_TooFewArgs();
		return 1;
	}
	else if (argc >= 3)
	{
		std::string inputPath = argv[1];
		std::string outputPath = argv[2];

		if (inputPath == outputPath)
		{
			messenger.ErrorMsg_IdenticalIO();
			return 1;
		}
		else
		{
			switch (argc)
			{
			case 3:
				system("cls");
				ReadFromFile(argv[1], argv[2]);
				messenger.StatusMsg_Finished();
				return 0;

			case 4:
				if (argv[3] == "-h" || "-j" || "-s")
				{
					system("cls");
					ReadFromFile(argv[1], argv[2], argv[3]);
					messenger.StatusMsg_Finished();
					return 0;
				}
				else
				{
					messenger.ErrorMsg_BadMode(argv[3]);
					return 1;
				}

			default:
				messenger.ErrorMsg_Generic();
				return 1;
				break;
			}
		}
	}
}