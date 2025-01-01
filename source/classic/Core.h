#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>

namespace XMCleaner
{
    class Core
    {
    public:
        bool Init();
        bool Run(int argc, char* argv[]);
        void Stop();
    };
    class AppInfo
    {
    public:
        static void LoadAndPrint();
        struct App
        {
            const std::string name = "XMCleaner";
            const std::string version = "v1.5.0";
            const std::string author = "Joshua Ostwald";
            const std::string license = "LGPL-2.1";
            const std::string githubLink = "github.com/Dat-Pudding/LogCleaner";
        };
    };

    class FileIO
    {
    public:
        class TextFileProcessor
        {
        public:
            void DelegateLine(std::string&, std::string&, bool&); // Defaults to filterMode '-h', then follows normal procedure via ReadLine()
            void ReadLine(std::string&, std::string&, std::string&, bool&);
            void CheckLine(std::string&, std::string&, std::string&, bool&);
            void WriteLine(std::string&, std::string&, std::string&, bool&);

        public:
            int saveCounter;
        };
    };

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

    class Converter
    {
    public:
        class HashLog
        {
        public:
            class ToCSV
            {
            public:
                std::string Convert(std::string&);
                static std::string outputLine;
                static int counter;
            private:
                void SymbolToSpace(std::string&);
                void EqualiseSpaces(std::string&);
                void SpaceToComma(std::string&);

                const char space = ' ';
                const char openBracket = '[';
                const char closeBracket = ']';
                const char comma = ',';

                class Polisher
                {
                public:
                    void Polish(std::string&);
                private:
                    void RemovePhrase(std::string&, std::smatch&, std::regex&);

                    const std::string phrase1 = ",speed,10s/60s/15m";
                    const std::string phrase2 = ",H/s,max";
                    const std::string phrase3 = ",H/s";
                };
            };
        };
        class ShareLog
        {
        public:
            class ToCSV
            {
            public:
                std::string Convert(std::string&);
                static std::string outputLine;
                static int counter;
            private:
                void SymbolToSpace(std::string&);
                void EqualiseSpaces(std::string&);
                void SpaceToComma(std::string&);

                const char space = ' ';
                const char openBracket = '[';
                const char closeBracket = ']';
                const char openParens = '(';
                const char closeParens = ')';
                const char forwardSlash = '/';
                const char comma = ',';

                class Polisher
                {
                public:
                    void Polish(std::string&);
                private:
                    void RemovePhrase(std::string&, std::smatch&, std::regex&);

                    const std::string phrase1 = ",diff";
                    const std::string phrase2 = ",ms";
                };
            };
        };
        class JobLog
        {
        public:
            class ToCSV
            {
            public:
                std::string Convert(std::string&);
                static std::string outputLine;
                static int counter;
            private:
                void BracketToSpace(std::string&);
                void EqualiseSpaces(std::string&);
                void SpaceToComma(std::string&);

                const char space = ' ';
                const char openBracket = '[';
                const char closeBracket = ']';
                const char comma = ',';
                const char openParens = '(';
                const char closeParens = ')';

                class Polisher
                {
                public:
                    void Polish(std::string&);
                private:
                    void RemovePhrase(std::string&, std::smatch&, std::regex&);

                    const std::string phrase1 = ",new,job";
                    const std::string phrase2 = ",from";
                    const std::string phrase3 = ",diff";
                    const std::string phrase4 = ",algo";
                    const std::string phrase5 = ",height";
                    const std::string phrase6 = ",tx";
                };
            };
        };
    };
};