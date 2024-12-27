#include "Core.h"

void XMCleaner::Messenger::ErrorMsg_TooFewArgs()
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
void XMCleaner::Messenger::ErrorMsg_IdenticalIO()
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
void XMCleaner::Messenger::ErrorMsg_BadMode(std::string filterMode)
{
	system("cls");
	std::cout << "\n"
	<< "ERROR: '" << filterMode << "' is not a valid filterMode\n"
	<< "<======================================== INFO ========================================>\n"
	<< " | Available filterMode variants are:                                                 |\n"
	<< " | -h          Extracts hashrate information in the log file                          |\n"
			  << " | -j          Extracts 'new job' information in the log file                         |\n"
	<< " | -s          Extracts 'accepted/rejected' share information in the log file         |\n"
	<< "<======================================================================================>\n\n"
	<< std::endl;
	system("pause");
}
void XMCleaner::Messenger::ErrorMsg_BadPath()
{
	std::cout << "Couldn't open file at given path!"
			  << std::endl;
	system("pause");
}
void XMCleaner::Messenger::ErrorMsg_BadOutput(std::string filterMode)
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
void XMCleaner::Messenger::ErrorMsg_BadDefaultOutput()
{
	std::cout << "Couldn't find hash log, trying to generate a new one..."
			  << std::endl;
	system("pause");
}
void XMCleaner::Messenger::ErrorMsg_Generic()
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

void XMCleaner::Messenger::StatusMsg_Searching(std::string logfilePath)
{
	std::cout << "Trying to find log file '" << logfilePath << "'..." << std::endl;
}
void XMCleaner::Messenger::StatusMsg_Checking(unsigned int lineCounter)
{
	std::cout << "[#" << lineCounter << "] Checking for specified stats..." << std::endl;
}
void XMCleaner::Messenger::StatusMsg_Saving(unsigned int saveCounter)
{
	std::cout << "[#" << saveCounter << "] saved!" << std::endl;
}
void XMCleaner::Messenger::StatusMsg_Finished()
{
	std::cout << "\n" << "<================== DONE ==================>" << std::endl;
}