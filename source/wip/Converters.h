#pragma once

#include <iostream>
#include <string>

namespace Converters
{
    class HashLog
    {
    public:
        class ToCSV
        {
        public:
            std::string Convert(std::string, int);
            std::string outputLine;
        private:
            void BracketToSpace(std::string, int);
            void EqualiseSpaces(std::string, int);
            void SpaceToComma(std::string, int);
            void Polisher(std::string, int);
            void Emitter(std::string, int);

        private:
            const char space = ' ';
            const char openBracket = '[';
            const char closeBracket = ']';
            const char comma = ',';
            const std::string infix = ",speed 10s/60s/15m ";
            const std::string suffix = ",H/s ";
        };

        class ToSQL
        {

        };
    };

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
};