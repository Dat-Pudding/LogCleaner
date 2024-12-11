#include "Messenger.h"
#include <iostream>
#include <string>

void Messenger::ErrorMsg_TooFewArgs()
{
	system("cls");
	std::cout << "\n"
			  << "ERROR: Too few arguments given! \n"
			  << "<======================================== INFO ========================================>\n"
			  << " | Please use this format: LogCleaner.exe <logfilePath> <outputFileName> <filterMode> |\n"
			  << "<======================================================================================>\n\n"
			  << std::endl;
	system("pause");
}
void Messenger::ErrorMsg_IdenticalIO()
{
	system("cls");
	std::cout << "\n"
			  << "ERROR: Output file can't be identical to the input file! \n"
			  << "<======================================== INFO ========================================>\n"
			  << " | Please use this format: LogCleaner.exe <logfilePath> <outputFileName> <filterMode> |\n"
			  << "<======================================================================================>\n\n"
			  << std::endl;
	system("pause");
}
void Messenger::ErrorMsg_BadPath()
{
	std::cout << "Couldn't open file at given path!"
			  << std::endl;
	system("pause");
}
void Messenger::ErrorMsg_BadOutput(std::string filterMode)
{
	if (filterMode == "-h")
	{
		std::cout << "Couldn't find hash log, trying to generate a new one..."
				  << std::endl;
		system("pause");
	}
	else if (filterMode == "-j")
	{
		std::cout << "Couldn't find job log, trying to generate a new one..."
				  << std::endl;
		system("pause");
	}
	else if (filterMode == "-s")
	{
		std::cout << "Couldn't find share log, trying to generate a new one..."
				  << std::endl;
		system("pause");
	}
}
void Messenger::ErrorMsg_BadDefaultOutput()
{
	std::cout << "Couldn't find hash log, trying to generate a new one..."
			  << std::endl;
	system("pause");
}
void Messenger::ErrorMsg_Generic()
{
	system("cls");
	std::cout << "\n"
			  << "Something went wrong! \n"
			  << "<======================================== INFO ========================================>\n"
			  << " | Please use this format: LogCleaner.exe <logfilePath> <outputFileName> <filterMode> |\n"
			  << "<======================================================================================>\n\n"
			  << std::endl;
	system("pause");
}

void Messenger::StatusMsg_Searching(std::string logfilePath)
{
	std::cout << "Trying to find log file "
			<< logfilePath
			<< "..."
			<< std::endl;
}
void Messenger::StatusMsg_Checking(unsigned int lineCounter)
{
	std::cout << "[#"
			  << lineCounter
			  << "] Checking for specified stats..."
			  << std::endl;
}
void Messenger::StatusMsg_Saving(unsigned int saveCounter)
{
	std::cout << "[#"
			  << saveCounter
			  << "] saved!"
			  << std::endl;
}
void Messenger::StatusMsg_Finished()
{
	std::cout << "\n"
			  << "<================== DONE ==================>"
			  << std::endl;
}