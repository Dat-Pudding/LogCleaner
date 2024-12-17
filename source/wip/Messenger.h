#pragma once
#include <string>

class Messenger
{
public:
	void ErrorMsg_TooFewArgs();
	void ErrorMsg_IdenticalIO();
	void ErrorMsg_BadMode(std::string);
	void ErrorMsg_BadPath();
	void ErrorMsg_BadOutput(std::string);
	void ErrorMsg_BadDefaultOutput();
	void ErrorMsg_Generic();

	void StatusMsg_Searching(std::string);
	void StatusMsg_Checking(unsigned int);
	void StatusMsg_Saving(unsigned int);
	void StatusMsg_Finished();
};