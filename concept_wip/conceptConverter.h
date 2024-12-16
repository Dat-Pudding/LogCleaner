#pragma once
#include <string>

namespace Converters
{
    class HashLog
    {
        class ToCSV
        {
        public:
            void Convert(std::string);
        private:
            void BracketToSpace(std::string, int);
            void EqualiseSpaces(std::string, int);
            void SpaceToComma(std::string, int);
            void Polisher(std::string, int);
            void Emitter(std::string, int);

            const char space = ' ';
            const char openBracket = '[';
            const char closeBracket = ']';
            const char comma = ',';
        };

        class ToSQL
        {

        };
    }

    class ShareLog
    {
        class ToCSV
        {
        public:
            void Convert(std::string);
        private:
            void BracketToSpace(std::string, int);
            void EqualiseSpaces(std::string, int);
            void SpaceToComma(std::string, int);
            void Polisher(std::string, int);
            void Emitter(std::string, int);

            const char space = ' ';
            const char openBracket = '[';
            const char closeBracket = ']';
            const char comma = ',';
        }


        class ToSQL
        {

        };
    }
        
};
