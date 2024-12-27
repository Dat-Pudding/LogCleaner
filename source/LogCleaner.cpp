#include "Core.h"

int main(int argc, char* argv[])
{
	AppInformation::LoadAndPrint();
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
				system("cls");
				ReadFromFile(argv[1], argv[2], isFirstLine);
				messenger.StatusMsg_Finished();
				return 0;

			case 4:
				if (argv[3] == "-h" || "-j" || "-s")
				{
					system("cls");
					ReadFromFile(argv[1], argv[2], argv[3], isFirstLine);
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