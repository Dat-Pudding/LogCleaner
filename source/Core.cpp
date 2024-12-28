#include "Core.h"


bool XMCleaner::Core::Init()
{
	AppInfo::LoadAndPrint();
    return true;
}

bool XMCleaner::Core::Run(int argc, char* argv[])
{
	XMCleaner::Messenger messenger;
    bool isFirstLine = true;

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
			XMCleaner::FileIO::TextFileProcessor io;
			switch (argc)
			{
			case 3:
				io.DelegateLine(inputPath, outputPath, isFirstLine);
				messenger.StatusMsg_Finished();
				return true;

			case 4:
				if (argv[3] == "-h" || "-j" || "-s")
				{
					std::string filterMode = argv[3];
					io.ReadLine(inputPath, outputPath, filterMode, isFirstLine);
					messenger.StatusMsg_Finished();
					return true;
				}
				else
				{
					messenger.ErrorMsg_BadMode(argv[3]);
					return false;
				}

			default:
				messenger.ErrorMsg_Generic();
				return false;
				break;
			}
		}
	}
}

void XMCleaner::Core::Stop()
{
    return;
}