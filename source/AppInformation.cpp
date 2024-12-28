#include "Core.h"

void XMCleaner::AppInfo::LoadAndPrint()
{
	App app;
	std::cout << app.name << " " << app.version << " by " << app.author << "\n"
	<< "Published and licensed under " << app.license << "\n"
	<< "Further information on Github at " << app.githubLink << std::endl;
};
