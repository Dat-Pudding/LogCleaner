#include "Core.h"


bool XMCleaner::Core::Init()
{
    return true;
}

bool XMCleaner::Core::Run(int argc, char* argv[])
{
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
			     switch (argc)
			     {
			         case 3:
				            ReadFromFile(argv[1], argv[2], isFirstLine);
				            messenger.StatusMsg_Finished();
				            return true;

			         case 4:
				            if (argv[3] == "-h" || "-j" || "-s")
				            {
					               ReadFromFile(argv[1], argv[2], argv[3], isFirstLine);
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

void XMCleaner::Core::Stop()
{
    return;
}