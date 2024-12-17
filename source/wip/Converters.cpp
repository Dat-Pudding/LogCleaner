#include "Converters.h"
#include <regex>

// `int counter` here should start at 1
// so the numbering works properly
std::string Converters::HashLog::ToCSV::Convert(std::string line, int counter)
{
    BracketToSpace(line, counter);
    ++counter;
    return line;
}

void Converters::HashLog::ToCSV::BracketToSpace(std::string line, int counter)
{
    std::string lineCache = line;

    for (int i = 0; i < line.length(); ++i)
    {
        if (lineCache[i] == openBracket || lineCache[i] == closeBracket)
        {
            lineCache[i] = space;
        }
    }
    line = lineCache;

    EqualiseSpaces(line, counter);
}

void Converters::HashLog::ToCSV::EqualiseSpaces(std::string line, int counter)
{
    int prevPos = 0;
    int currentPos = 1;
    std::string lineCache = line;

    while (lineCache[currentPos] != '\0')
    {
        if (lineCache[prevPos] == space && lineCache[currentPos] == space)
        {
            int newPos = currentPos;

            while (newPos <= lineCache.length() - 1)
            {
                lineCache[newPos] = lineCache[newPos + 1];
                ++newPos;
                lineCache.shrink_to_fit();
                line = lineCache;
            }
        }
        else
        {
            ++currentPos;
            ++prevPos;
        }
    }

    line = lineCache;

    SpaceToComma(line, counter);
}

void Converters::HashLog::ToCSV::SpaceToComma(std::string line, int counter)
{
    std::string lineCache = line;

    for (int i = 0; i < line.length(); ++i)
    {
        if (lineCache[i] == space)
        {
            lineCache[i] = comma;
        }
    }
    line = lineCache;

    Polisher(line, counter);
}

void Converters::HashLog::ToCSV::Polisher(std::string line, int counter)
{
    std::string lineCache = line;
    std::string phrase1 = ",speed,10s/60s/15m";
    std::string phrase2 = ",H/s,max";
    std::string phrase3 = ",H/s";

    std::smatch matchStore;
    std::regex pattern1((phrase1));
    std::regex pattern2((phrase2));
    std::regex pattern3((phrase3));

    auto lineCacheStart = lineCache.begin();
    lineCache.erase(lineCacheStart);
    lineCache.shrink_to_fit();

    for (int i = 0; i < matchStore.size(); ++i)
    {
        switch (i)
        {
            case 0:
                if (std::regex_search(lineCache, matchStore, pattern1))
                {
                    auto p1_begin = matchStore.position(i);
                    auto p1_end = p1_begin + phrase1.length() - 1;
                    lineCache.erase(p1_begin, p1_end);
                    lineCache.shrink_to_fit();
                    break;
                }

            case 1:
                if (std::regex_search(lineCache, matchStore, pattern2))
                {
                    auto p2_begin = matchStore.position(i);
                    auto p2_end = p2_begin + phrase2.length() - 1;
                    lineCache.erase(p2_begin, p2_end);
                    lineCache.shrink_to_fit();
                    break;
                }

            case 2:
                if (std::regex_search(lineCache, matchStore, pattern3))
                {
                    auto p3_begin = matchStore.position(i);
                    auto p3_end = p3_begin + phrase3.length();
                    lineCache.erase(p3_begin, p3_end);
                    lineCache.shrink_to_fit();
                    break;
                }

            default:
                std::cout << "Something went wrong in Polisher()" << std::endl;
                return;
        }
    }

    line = lineCache;
    line.shrink_to_fit();
    Emitter(line, counter);
}

void Converters::HashLog::ToCSV::Emitter(std::string line, int counter)
{
    std::cout << "Converted line [#" << counter << "] into CSV-compatible format" << std::endl;
    outputLine = line;
}