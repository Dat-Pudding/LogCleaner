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
        class DefaultProcessor
        {
        public:
            
            void ReadLine(std::string, std::string, bool&);
            void CheckLine(std::string, std::string, bool&);
            void WriteLine(std::string, std::string, bool&);
        private:
            unsigned int saveCounter = 1;
        }
        class Processor
        {
        public:
            void CheckASave(std::string&, std::string, std::string, bool&);
            void ReadFile(std::string, std::string, std::string, bool&);
        private:
            unsigned int saveCounter = 1;
        }
    }
}