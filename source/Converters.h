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

        class ToSQL
        {

        };
    };

/*
    class ShareLog
    {
        class ToCSV
        {
        public:
            std::string Convert(std::string);
        private:
            void BracketToSpace(std::string, int);
            void EqualiseSpaces(std::string, int);
            void SpaceToComma(std::string, int);
            void Polisher(std::string, int);
            std::string Emitter(std::string, int);

            const char space = ' ';
            const char openBracket = '[';
            const char closeBracket = ']';
            const char comma = ',';
        };

        class ToSQL
        {

        };
    };
*/
};