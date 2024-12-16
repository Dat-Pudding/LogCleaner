#include <iostream>

// `int counter` here should start at 1
void Converters::HashLogs::ToCSV::Convert(std::string line, int counter)
{
    BracketToSpace(line, counter);
}

void Converters::HashLogs::ToCSV::BracketToSpace(std::string line, int counter)
{
    std::string lineCache = line;

    for (int i = 0; i < line.length(); ++i)
    {
        if (lineCache[i] == '[' || lineCache[i] == ']')
        {
            lineCache[i] = ' ';
        }
    }
    line = lineCache;
    std::cout << "After BTS: " << line << std::endl;
    EqualiseSpaces(line, counter);
}

void Converters::HashLogs::ToCSV::EqualiseSpaces(std::string line, int counter)
{
    int prevPos = 0;
    int currentPos = 1;
    char filterMask = ' ';
    std::string lineCache = line;
    
    while (lineCache[currentPos] != '\0')
    {
        if (lineCache[prevPos] == filterMask && lineCache[currentPos] == filterMask)
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
    std::cout << "After ES: " << line << std::endl;
    SpaceToComma(line, counter);
}

void Converters::HashLogs::ToCSV::SpaceToComma(std::string line, int counter)
{
    std::string lineCache = line;

    for (int i = 0; i < line.length(); ++i)
    {
        if (lineCache[i] == ' ')
        {
            lineCache[i] = ',';
        }
    }

    line = lineCache;
    std::cout << "After STC: " << line << std::endl;
    Polisher(line, counter);
}

void Converters::HashLogs::ToCSV::Polisher(std::string line, int counter)
{
    char filterMask[4] = { ',' , 'R', 'P', 'M' };
    std::string lineCache = line;
    
     for (int i = 0; i < line.length(); ++i)
    {
        switch (i)
        {
            case 0:
            {
                auto lcStart = lineCache.begin();

                lineCache.erase(lcStart);
                lineCache.shrink_to_fit();
                line = lineCache;
                
                std::cout << "After P1: " << line << std::endl;
                continue;
            }

            case 31:
            {
                std::string filterPhrase = ",speed(10s/60s/15m)";
                
                auto start = lineCache.begin() + i;
                auto last = start + filterPhrase.length();

                lineCache.erase(start, last);
                lineCache.shrink_to_fit();
                line = lineCache;
         
                std::cout << "After P2: " << line << std::endl;
                continue;
            }

            case 52:
            {
                auto first = lineCache.begin() + i;
                auto last = lineCache.end();

                lineCache.erase(first, last);
;
                lineCache.shrink_to_fit();
                line = lineCache;
                 
                std::cout << "After P3: " << line << std::endl;
                continue;
            }

            default:
            {
                ++i;
                continue;
            }
        }
    }

    line = lineCache;
    Emitter(line, counter);
}

void Converters::HashLogs::ToCSV::Emitter(std::string line, int counter)
{
    std::cout << "Converted line [#" << counter << "] into CSV-compatible format" << std::endl;
    std::cout << "Result: \n" << line << std::endl;
    std::cout << "Expected: \n21-12-2024,16:34:56:678,sensor1,2377.7,2488.4,2322.2" << std::endl;
    return;
}