#pragma once
#include <string>

namespace Converters
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
    };
};
