#pragma once

#include <iostream>

void AppInformation::LoadAndPrint()
{
    App app;
	   	std::cout << app.name << " " << app.version << " by " << app.author << "\n"
		  << "Published and licensed under " << app.license << "\n"
		  << "Further information on Github at " << app.githubLink << std::endl;
};
AppInformation::App
{
    name[11] = "LogCleaner";
		  version[7] = "v1.0.0";
	   	author[15] = "Joshua Ostwald";
   		license[9] = "LGPL-2.1";
   		githubLink[42] = "github.com/Dat-Pudding/LogCleaner";
};