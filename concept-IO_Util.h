#pragma once
#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include "AppInformation.h"
#include "Messenger.h"
#include "Converters.h"

namespace IO_Util
{
    namespace fs = std::filesystem;
    unsigned int saveCounter = 1;
    class DefaultIO
    {
        void CheckAndSave(std::string, std::string, bool&) // default to hashing logs when no filterMode is given
        void ReadFromFile(std::string, std::string, bool&)
    }
    

    void CheckAndSave(std::string&, std::string, std::string, bool&)

 // default when no filterMode is given

    void ReadFromFile(std::string, std::string, std::string, bool&)
