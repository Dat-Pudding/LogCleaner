// `int counter` here should start at 1
// so the numbering works properly
std::string Converters::HashLog::ToCSV::Convert(std::string line, int counter)
{
    BracketToSpace(line, counter);
    return outputLine;
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
                continue;
            }
            case 31:
            {                
                auto start = lineCache.begin() + i;
                auto last = start + infix.length();

                lineCache.erase(start, last);
                lineCache.shrink_to_fit();
                line = lineCache;
                continue;
            }
            case 52:
            {
                auto first = lineCache.begin() + i;
                auto last = first + suffix.length();
                
                lineCache.erase(first, last);
                lineCache.shrink_to_fit();
                line = lineCache;
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

void Converters::HashLog::ToCSV::Emitter(std::string line, int counter)
{
    std::cout << "Converted line [#" << counter << "] into CSV-compatible format" << std::endl;
    outputLine = line;
}