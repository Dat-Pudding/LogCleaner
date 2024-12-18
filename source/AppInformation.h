#pragma once
#include <iostream>

static class AppInformation
{
public:
	static void LoadAndPrint()
	{
		App app;
		std::cout << app.name << " " << app.version << " by " << app.author << "\n"
				  << "Published and licensed under " << app.license << "\n"
				  << "Further information on Github at " << app.githubLink << std::endl;
	}
private:
	const static struct App
	{
		const char name[11] = "LogCleaner";
		const char version[7] = "v0.1.5";
		const char author[15] = "Joshua Ostwald";
		const char license[9] = "LGPL-2.1";
		const char githubLink[42] = "github.com/Dat-Pudding/LogCleaner";
	};
};

