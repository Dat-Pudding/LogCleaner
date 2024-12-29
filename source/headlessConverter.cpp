#include "headlessCore.h"

std::string XMCleaner::Converter::HashLog::ToCSV::outputLine = "";
int XMCleaner::Converter::HashLog::ToCSV::counter = 1;

std::string XMCleaner::Converter::HashLog::ToCSV::Convert(std::string& line)
{
    SymbolToSpace(line);
    ++counter;
    return outputLine;
}
void XMCleaner::Converter::HashLog::ToCSV::SymbolToSpace(std::string& line)
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
void XMCleaner::Converter::HashLog::ToCSV::EqualiseSpaces(std::string& line)
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
void XMCleaner::Converter::HashLog::ToCSV::SpaceToComma(std::string& line)
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
void XMCleaner::Converter::HashLog::ToCSV::Polisher::Polish(std::string& line)
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
void XMCleaner::Converter::HashLog::ToCSV::Polisher::RemovePhrase(std::string& lineCache, std::smatch& matchStore, std::regex& pattern)
{
    auto phraseBegin = matchStore.position(0);
    auto phraseEnd = matchStore.length(0);
    lineCache.erase(phraseBegin, phraseEnd);
    lineCache.shrink_to_fit();
}

// ============================ ShareLog ===============================
std::string XMCleaner::Converter::ShareLog::ToCSV::outputLine = "";
int XMCleaner::Converter::ShareLog::ToCSV::counter = 1;

std::string XMCleaner::Converter::ShareLog::ToCSV::Convert(std::string& line)
{
    SymbolToSpace(line);
    ++counter;
    return outputLine;
}
void XMCleaner::Converter::ShareLog::ToCSV::SymbolToSpace(std::string& line)
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
void XMCleaner::Converter::ShareLog::ToCSV::EqualiseSpaces(std::string& line)
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
void XMCleaner::Converter::ShareLog::ToCSV::SpaceToComma(std::string& line)
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
void XMCleaner::Converter::ShareLog::ToCSV::Polisher::Polish(std::string& line)
{
    std::string lineCache = line;
    std::smatch matchStore;

    std::regex pattern1((phrase1));
    std::regex pattern2((phrase2));

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

    line = lineCache;
    line.shrink_to_fit();
    outputLine = line;
}
void XMCleaner::Converter::ShareLog::ToCSV::Polisher::RemovePhrase(std::string& lineCache, std::smatch& matchStore, std::regex& pattern)
{
    auto phraseBegin = matchStore.position(0);
    auto phraseEnd = matchStore.length(0);
    lineCache.erase(phraseBegin, phraseEnd);
    lineCache.shrink_to_fit();
}

// ============================ JobLog ===============================
std::string XMCleaner::Converter::JobLog::ToCSV::outputLine = "";
int XMCleaner::Converter::JobLog::ToCSV::counter = 1;

std::string XMCleaner::Converter::JobLog::ToCSV::Convert(std::string& line)
{
    BracketToSpace(line);
    ++counter;
    return outputLine;
}
void XMCleaner::Converter::JobLog::ToCSV::BracketToSpace(std::string& line)
{
    std::string lineCache = line;

    for (int i = 0; i < line.length(); ++i)
    {
        if (lineCache[i] == openBracket || lineCache[i] == closeBracket || lineCache[i] == openParens || lineCache[i] == closeParens)
        {
            lineCache[i] = space;
        }
    }
    line = lineCache;
    EqualiseSpaces(line);
}
void XMCleaner::Converter::JobLog::ToCSV::EqualiseSpaces(std::string& line)
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
void XMCleaner::Converter::JobLog::ToCSV::SpaceToComma(std::string& line)
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
void XMCleaner::Converter::JobLog::ToCSV::Polisher::Polish(std::string& line)
{
    std::string lineCache = line;
    std::smatch matchStore;

    std::regex pattern1((phrase1));
    std::regex pattern2((phrase2));
    std::regex pattern3((phrase3));
    std::regex pattern4((phrase4));
    std::regex pattern5((phrase5));
    std::regex pattern6((phrase6));

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
    if (std::regex_search(lineCache, matchStore, pattern4))
    {
        RemovePhrase(lineCache, matchStore, pattern4);
    }
    if (std::regex_search(lineCache, matchStore, pattern5))
    {
        RemovePhrase(lineCache, matchStore, pattern5);
    }
    if (std::regex_search(lineCache, matchStore, pattern6))
    {
        RemovePhrase(lineCache, matchStore, pattern6);
    }


    line = lineCache;
    line.shrink_to_fit();
    outputLine = line;
}
void XMCleaner::Converter::JobLog::ToCSV::Polisher::RemovePhrase(std::string& lineCache, std::smatch& matchStore, std::regex& pattern)
{
    auto phraseBegin = matchStore.position(0);
    auto phraseEnd = matchStore.length(0);
    lineCache.erase(phraseBegin, phraseEnd);
    lineCache.shrink_to_fit();
}