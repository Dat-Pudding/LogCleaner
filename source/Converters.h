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

                const std::string phrase1 = ",from";
                const std::string phrase2 = ",algo";
                const std::string phrase3 = ",diff";
                const std::string phrase4 = ",height";
                const std::string phrase5 = ",tx";
            };
        };
    };
};