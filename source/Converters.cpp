#include "Converters.h"

std::string Converters::HashLog::ToCSV::outputLine = "";
int Converters::HashLog::ToCSV::counter = 1;

std::string Converters::HashLog::ToCSV::Convert(std::string& line)
{
    BracketToSpace(line);
    ++counter;
    return outputLine;
}
void Converters::HashLog::ToCSV::BracketToSpace(std::string& line)
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
    EqualiseSpaces(line);
}
void Converters::HashLog::ToCSV::EqualiseSpaces(std::string& line)
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
                line = lineCache;
            }
            lineCache.shrink_to_fit();
        }
        else
        {
            ++currentPos;
            ++prevPos;
        }
    }
    line = lineCache;
    SpaceToComma(line);
}
void Converters::HashLog::ToCSV::SpaceToComma(std::string& line)
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
    Polisher polisher;
    polisher.Polish(line);
}
void Converters::HashLog::ToCSV::Polisher::Polish(std::string& line)
{
    std::string lineCache = line;
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
        RemovePhrase(lineCache, matchStore, pattern3);
    }
    line = lineCache;
    line.shrink_to_fit();
    outputLine = line;
}
void Converters::HashLog::ToCSV::Polisher::RemovePhrase(std::string& lineCache, std::smatch& matchStore, std::regex& pattern)
{
    auto phraseBegin = matchStore.position(0);
    auto phraseEnd = matchStore.length(0);
    lineCache.erase(phraseBegin, phraseEnd);
    lineCache.shrink_to_fit();
}

// ============================ ShareLog ===============================
std::string Converters::ShareLog::ToCSV::outputLine = "";
int Converters::ShareLog::ToCSV::counter = 1;

std::string Converters::ShareLog::ToCSV::Convert(std::string& line)
{
    BracketToSpace(line);
    ++counter;
    return outputLine;
}
void Converters::ShareLog::ToCSV::BracketToSpace(std::string& line)
{
    std::string lineCache = line;
    
    for (int i = 0; i < line.length(); ++i)
    {
        if (lineCache[i] == openBracket || lineCache[i] == closeBracket || lineCache[i] == openParens || lineCache[i] == closeParens || lineCache[i] == forwardSlash)
        {
            lineCache[i] = space;
        }
    }
    
    line = lineCache;
    EqualiseSpaces(line);
}
void Converters::ShareLog::ToCSV::EqualiseSpaces(std::string& line)
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
                line = lineCache;
            }
            lineCache.shrink_to_fit();
        }
        else
        {
            ++currentPos;
            ++prevPos;
        }
    }
    line = lineCache;
    SpaceToComma(line);
}
void Converters::ShareLog::ToCSV::SpaceToComma(std::string& line)
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
    Polisher polisher;
    polisher.Polish(line);
}
void Converters::ShareLog::ToCSV::Polisher::Polish(std::string& line)
{
    std::string lineCache = line;
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
        RemovePhrase(lineCache, matchStore, pattern3);
    }
    line = lineCache;
    line.shrink_to_fit();
    outputLine = line;
}
void Converters::ShareLog::ToCSV::Polisher::RemovePhrase(std::string& lineCache, std::smatch& matchStore, std::regex& pattern)
{
    auto phraseBegin = matchStore.position(0);
    auto phraseEnd = matchStore.length(0);
    lineCache.erase(phraseBegin, phraseEnd);
    lineCache.shrink_to_fit();
}

// ============================ ShareLog ===============================
std::string Converters::JobLog::ToCSV::outputLine = "";
int Converters::JobLog::ToCSV::counter = 1;

std::string Converters::JobLog::ToCSV::Convert(std::string& line)
{
    BracketToSpace(line);
    ++counter;
    return outputLine;
}
void Converters::JobLog::ToCSV::BracketToSpace(std::string& line)
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
    EqualiseSpaces(line);
}
void Converters::JobLog::ToCSV::EqualiseSpaces(std::string& line)
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
                line = lineCache;
            }
            lineCache.shrink_to_fit();
        }
        else
        {
            ++currentPos;
            ++prevPos;
        }
    }
    line = lineCache;
    SpaceToComma(line);
}
void Converters::JobLog::ToCSV::SpaceToComma(std::string& line)
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
    Polisher polisher;
    polisher.Polish(line);
}
void Converters::JobLog::ToCSV::Polisher::Polish(std::string& line)
{
    std::string lineCache = line;
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
        RemovePhrase(lineCache, matchStore, pattern3);
    }
    line = lineCache;
    line.shrink_to_fit();
    outputLine = line;
}
void Converters::JobLog::ToCSV::Polisher::RemovePhrase(std::string& lineCache, std::smatch& matchStore, std::regex& pattern)
{
    auto phraseBegin = matchStore.position(0);
    auto phraseEnd = matchStore.length(0);
    lineCache.erase(phraseBegin, phraseEnd);
    lineCache.shrink_to_fit();
}