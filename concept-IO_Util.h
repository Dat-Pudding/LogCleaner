#pragma once
#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include "AppInformation.h"
#include "Messenger.h"
#include "Converters.h"

namespace CustomUtils
{
    class IO
    {
        class Processor
        {
        public:
            void DelegateLine(std::string&, std::string&, bool&); // Defaults to filterMode '-h', then follows normal procedure
            void ReadLine(std::string, std::string, bool&);
            void CheckLine(std::string, std::string, bool&);
            void WriteLine(std::string, std::string, bool&);
        private:
            static unsigned int saveCounter = 1;
        }
    }
}