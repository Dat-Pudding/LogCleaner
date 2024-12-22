#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include "AppInformation.h"
#include "Messenger.h"
#include "Converters.h"

namespace fs = std::filesystem;
unsigned int saveCounter = 1;
Messenger messenger;

void CustomUtils::IO::TextFileProcessor::DelegateLine(std::string& logfilePath, std::string& outputFileName, bool& needsHeader)
{
    ReadLine(logfilePath, outputFileName, needsHeader);
}

void CustomUtils::IO::TextFileProcessor::ReadLine(std::string& logfilePath, std::string& outputFileName, std::string& filterMode, bool& isFirstLine)
{
    fs::path p;
    p = logfilePath;

    messenger.StatusMsg_Searching(logfilePath);
    std::ifstream inputFile(p);

    if (!inputFile.is_open())
    {
        messenger.ErrorMsg_BadPath();
        inputFile.open(logfilePath);
        return;
    }
    else if (inputFile.is_open())
    {
        std::string line;
        int lineCounter = 1;

        while (std::getline(inputFile, line))
        {
            messenger.StatusMsg_Checking(lineCounter);
            CheckLine(line, outputFileName, isFirstLine);
            ++lineCounter;
        }
        inputFile.close();
    }
}

void CustomUtils::IO::TextFileProcessor::CheckLine(std::string& lineToCheck, std::string& outputFileName, bool& needsHeader)
{
    if (filterMode == "-h")
    {
        Converters::HashLog::ToCSV hashConverter;
        std::ofstream outputFile(outputFileName, std::ios::out | std::ios::app);
        std::regex stringPattern("(speed 10s/60s/15m)");

        if (std::regex_search(lineToCheck, stringPattern))
        {
            if (!outputFile.is_open())
            {
                messenger.ErrorMsg_BadOutput(filterMode);
                outputFile.open(outputFileName);
            }
            else if (outputFile.is_open())
            {
                if (isFirstLine)
                {
                    outputFile << "date,time,system,10s,60s,15m,max" << std::endl;
                    isFirstLine = false;
                }
                if (!isFirstLine)
                {
                    hashConverter.Convert(lineToCheck);
                    std::string lineToOutput = hashConverter.outputLine;
                    outputFile << lineToOutput << std::endl;
                    messenger.StatusMsg_Saving(saveCounter);
                    ++saveCounter;
                }
            }
        }
    }
    else if (filterMode == "-j")
    {
        Converters::JobLog::ToCSV jobConverter;
        std::ofstream outputFile(outputFileName, std::ios::out | std::ios::app);
        std::regex stringPattern("(new job from)");

        if (std::regex_search(lineToCheck, stringPattern))
        {
            if (!outputFile.is_open())
            {
                messenger.ErrorMsg_BadOutput(filterMode);
                outputFile.open(outputFileName);
            }
            else if (outputFile.is_open())
            {
                if (isFirstLine)
                {
                    outputFile << "date,time,system,server,diff,algo,height" << std::endl;
                    isFirstLine = false;
                }
                if (!isFirstLine)
                {
                    jobConverter.Convert(lineToCheck);
                    std::string lineToOutput = jobConverter.outputLine;
                    outputFile << lineToOutput << std::endl;
                    messenger.StatusMsg_Saving(saveCounter);
                    ++saveCounter;
                }
            }
        }
    }
    else if (filterMode == "-s")
    {
        Converters::ShareLog::ToCSV shareConverter;
        std::ofstream outputFile(outputFileName, std::ios::out | std::ios::app);
        std::regex patternAccept("(accepted)");
        std::regex patternReject("(rejected)");

        if (std::regex_search(lineToCheck, patternAccept) || std::regex_search(lineToCheck, patternReject))
        {
            if (!outputFile.is_open())
            {
                messenger.ErrorMsg_BadOutput(filterMode);
                outputFile.open(outputFileName);
            }
            else if (outputFile.is_open())
            {
                if (isFirstLine)
                {
                    outputFile << "date,time,system,status,numAccept,numReject,difficulty,latency" << std::endl;
                    isFirstLine = false;
                }
                if (!isFirstLine)
                {
                    shareConverter.Convert(lineToCheck);
                    std::string lineToOutput = shareConverter.outputLine;
                    outputFile << lineToOutput << std::endl;
                    messenger.StatusMsg_Saving(saveCounter);
                    ++saveCounter;
                }
            }
        }
    }
    else
    {
        return;
    }
}

void CustomUtils::IO::TextFileProcessor::WriteLine(std::string lineToCheck, std::regex& pattern, std::string outputFileName, bool& needsHeader)
{
    if (filterMode == "-h")
    {
        Converters::HashLog::ToCSV hashConverter;
        std::ofstream outputFile(outputFileName, std::ios::out | std::ios::app)
        
        if (!outputFile.is_open())
        {
            messenger.ErrorMsg_BadOutput(filterMode);
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
                std::string lineToOutput = hashConverter.outputLine;
                outputFile << lineToOutput << std::endl;
                messenger.StatusMsg_Saving(saveCounter);
                ++saveCounter;
            }
        }
    }
    else if (filterMode == "-j")
    {
        Converters::JobLog::ToCSV jobConverter;
        std::ofstream outputFile(outputFileName, std::ios::out | std::ios::app);
        std::regex stringPattern("(new job from)");
    
        if (!outputFile.is_open())
        {
            messenger.ErrorMsg_BadOutput(filterMode);
            outputFile.open(outputFileName);
        }
        else if (outputFile.is_open())
        {
            if (needsHeader)
            {
                outputFile << "date,time,system,server,diff,algo,height" << std::endl;
                needsHeader = false;
            }
            if (!needsHeader)
            {
                jobConverter.Convert(lineToCheck);
                std::string lineToOutput = jobConverter.outputLine;
                outputFile << lineToOutput << std::endl;
                messenger.StatusMsg_Saving(saveCounter);
                ++saveCounter;
            }
        }
    }
    else if (filterMode == "-s")
    {
        Converters::ShareLog::ToCSV shareConverter;
        std::ofstream outputFile(outputFileName, std::ios::out | std::ios::app);

        if (!outputFile.is_open())
        {
            messenger.ErrorMsg_BadOutput(filterMode);
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
                std::string lineToOutput = shareConverter.outputLine;
                outputFile << lineToOutput << std::endl;
                messenger.StatusMsg_Saving(saveCounter);
                ++saveCounter;
            }
        }
    }
    else
    {
        return;
    }
}