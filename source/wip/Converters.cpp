#include "Converters.h"
#include <regex>

// `int counter` here should start at 1
// so the numbering works properly
std::string Converters::HashLog::ToCSV::Convert(std::string& line, int& counter)
{
    BracketToSpace(line, counter);
    ++counter;
    return line;
}

void Converters::HashLog::ToCSV::BracketToSpace(std::string& line, int& counter)
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

void Converters::HashLog::ToCSV::EqualiseSpaces(std::string- line, int& counter)
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

void Converters::HashLog::ToCSV::SpaceToComma(std::string& line, int& counter)
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

void Converters::HashLog::ToCSV::Polisher(std::string& line, int& counter)
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

    if (std::regex_search(lineCache, matchStore, pattern1))
    {
        RemovePhrase(lineCache, matchStore, pattern1);
    }

    if (std::regex_search(lineCache, matchStore, pattern2))
    {
        RemovePhrase(lineCache, matchStore, pattern2);
    }
    
    if (std::regex_search(lineCache, matchStore, pattern3))
    {
        RemovePhrase(lineCache, matchStore, pattern1);
    }

    line = lineCache;
    line.shrink_to_fit();
    Emitter(line, counter);
}

void Converters::HashLog::ToCSV::Polisher::RemovePhrase(std::string& lineCache, std::smatch matchStore, std::regex pattern)
{
    auto phraseBegin = matchStore.position(0);
    auto phraseEnd = matchStore.position(0) + matchStore.length(0);
    lineCache.erase(phraseBegin, phraseEnd);
    lineCache.shrink_to_fit();
}

void Converters::HashLog::ToCSV::Emitter(std::string& line, int& counter)
{
    std::cout << "Converted line [#" << counter << "] into CSV-compatible format" << std::endl;
}