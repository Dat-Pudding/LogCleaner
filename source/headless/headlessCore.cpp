#include "headlessCore.h"


bool XMCleaner::Core::Init()
{
	return true;
}

bool XMCleaner::Core::Run(int argc, char* argv[])
{
	bool isFirstLine = true;
	XMCleaner::FileIO::TextFileProcessor io;

	if (argv[1] != NULL)
	{
		std::string inputPath = argv[1];
		io.ReadLine(inputPath, isFirstLine);
		return true;
	}
	else
	{
		return false;
	}
}

void XMCleaner::Core::Stop()
{
	return;
}