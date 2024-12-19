#pragma once
#include <iostream>
#include <string>
#include <regex>

namespace Converters
{
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
            void BracketToSpace(std::string&);
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
            void BracketToSpace(std::string&);
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
};