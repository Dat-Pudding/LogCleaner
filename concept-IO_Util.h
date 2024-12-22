#pragma once

#include <string>
#include "Messenger.h"

namespace CustomUtils
{
    class IO
    {
        class TextFileProcessor
        {
        public:
            void DelegateLine(std::string&, std::string&, bool&); // Defaults to filterMode '-h', then follows normal procedure
            void ReadLine(std::string&, std::string&, std::string&, bool&);
            void CheckLine(std::string&, std::string&, std::string&, bool&);
            void WriteLine(std::string&, std::string&, std::string&, bool&);

        public:
            const Messenger messenger;
            static unsigned int saveCounter = 1;
        }
    }
}