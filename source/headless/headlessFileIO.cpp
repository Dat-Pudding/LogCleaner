#include "headlessCore.h"

namespace fs = std::filesystem;

void XMCleaner::FileIO::TextFileProcessor::ReadLine(std::string& logfilePath, std::string& outputFileName, bool& needsHeader)
{
    fs::path p;
    p = logfilePath;
    std::ifstream inputFile(p);

    if (!inputFile.is_open())
    {
        inputFile.open(logfilePath);
        return;
    }
    else if (inputFile.is_open())
    {
        std::string line;
        int lineCounter = 1;

        while (std::getline(inputFile, line))
        {
            CheckLine(line, outputFileName, needsHeader);
            ++lineCounter;
        }
        inputFile.close();
    }
    return;
}

void XMCleaner::FileIO::TextFileProcessor::CheckLine(std::string& lineToCheck, std::string& outputFileName, std::string& filterMode, bool& needsHeader)
{ 
    switch (stepper)
    {
        case 1:
            std::regex stringPattern("(speed 10s/60s/15m)");
            
            if (std::regex_search(lineToCheck, stringPattern))
            {
                WriteLine(lineToCheck, outputFileName, needsHeader);
            }
    
        case 2:
            std::regex stringPattern("(new job from)");

            if (std::regex_search(lineToCheck, stringPattern))
            {
                WriteLine(lineToCheck, outputFileName, needsHeader);
            }
    }
    else if (filterMode == "-s")
    {
        std::regex patternAccept("(accepted)");
        std::regex patternReject("(rejected)");

        if (std::regex_search(lineToCheck, patternAccept) || std::regex_search(lineToCheck, patternReject))
        {
            WriteLine(lineToCheck, outputFileName, needsHeader);
        }
    }
    return;
}

void XMCleaner::FileIO::TextFileProcessor::WriteLine(std::string& lineToCheck, std::string& outputFileName, bool& needsHeader)
{
    int stepper = 0;

    switch (stepper)
    {
        case 1:
            XMCleaner::Converter::HashLog::ToCSV hashConverter;
            std::ofstream outputFile(outputFileName, std::ios::out | std::ios::app);

            if (!outputFile.is_open())
            {
                outputFile.open(outputFileName);
            }
            else if (outputFile.is_open())
            {
                if (needsHeader)
                {
                    outputFile << "date,time,system,10s,60s,15m,max" << std::endl;
                    needsHeader = false;
                }
                if (!needsHeader)
                {
                    hashConverter.Convert(lineToCheck);
                    outputFile << hashConverter.outputLine << std::endl;
            }
        }
        case 2:
            XMCleaner::Converter::JobLog::ToCSV jobConverter;
            std::ofstream outputFile(outputFileName, std::ios::out | std::ios::app);
            std::regex stringPattern("(new job from)");

            if (!outputFile.is_open())
            {
                outputFile.open(outputFileName);
            }
            else if (outputFile.is_open())
            {
                if (needsHeader)
                {
                    outputFile << "date,time,system,server,diff,algo,height,tx" << std::endl;
                    needsHeader = false;
                }
                if (!needsHeader)
                {
                    jobConverter.Convert(lineToCheck);
                    outputFile << jobConverter.outputLine << std::endl;
                }
            }
        case 3:
            XMCleaner::Converter::ShareLog::ToCSV shareConverter;
            std::ofstream outputFile(outputFileName, std::ios::out | std::ios::app);

            if (!outputFile.is_open())
            {
                outputFile.open(outputFileName);
            }
            else if (outputFile.is_open())
            {
                if (needsHeader)
                {
                    outputFile << "date,time,system,status,numAccept,numReject,difficulty,latency" << std::endl;
                    needsHeader = false;
                }
                if (!needsHeader)
                {
                    shareConverter.Convert(lineToCheck);
                    outputFile << shareConverter.outputLine << std::endl;
                }
            }
        }
    }
}