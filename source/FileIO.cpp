#include "Core.h"

namespace fs = std::filesystem;
XMCleaner::Messenger messenger;

void XMCleaner::FileIO::TextFileProcessor::DelegateLine(std::string& logfilePath, std::string& outputFileName, bool& needsHeader)
{
    std::string defaultString = "-h";
    ReadLine(logfilePath, outputFileName, defaultString, needsHeader);
    return;
}

void XMCleaner::FileIO::TextFileProcessor::ReadLine(std::string& logfilePath, std::string& outputFileName, std::string& filterMode, bool& needsHeader)
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
            CheckLine(line, outputFileName, filterMode, needsHeader);
            ++lineCounter;
        }
        inputFile.close();
    }
    return;
}

void XMCleaner::FileIO::TextFileProcessor::CheckLine(std::string& lineToCheck, std::string& outputFileName, std::string& filterMode, bool& needsHeader)
{
    if (filterMode == "-h")
    {
        std::regex stringPattern("(speed 10s/60s/15m)");

        if (std::regex_search(lineToCheck, stringPattern))
        {
            WriteLine(lineToCheck, outputFileName, filterMode, needsHeader);
        }
    }
    else if (filterMode == "-j")
    {
        std::regex stringPattern("(new job from)");

        if (std::regex_search(lineToCheck, stringPattern))
        {
            WriteLine(lineToCheck, outputFileName, filterMode, needsHeader);
        }
    }
    else if (filterMode == "-s")
    {
        std::regex patternAccept("(accepted)");
        std::regex patternReject("(rejected)");

        if (std::regex_search(lineToCheck, patternAccept) || std::regex_search(lineToCheck, patternReject))
        {
            WriteLine(lineToCheck, outputFileName, filterMode, needsHeader);
        }
    }
    return;
}

void XMCleaner::FileIO::TextFileProcessor::WriteLine(std::string& lineToCheck, std::string& outputFileName, std::string& filterMode, bool& needsHeader)
{
    if (filterMode == "-h")
    {
        XMCleaner::Converter::HashLog::ToCSV hashConverter;
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
                outputFile << "date,time,system,10s,60s,15m,max" << std::endl;
                needsHeader = false;
            }
            if (!needsHeader)
            {
                hashConverter.Convert(lineToCheck);
                outputFile << hashConverter.outputLine << std::endl;
                messenger.StatusMsg_Saving(saveCounter);
                ++saveCounter;
            }
        }
    }
    else if (filterMode == "-j")
    {
        XMCleaner::Converter::JobLog::ToCSV jobConverter;
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
                outputFile << "date,time,system,server,diff,algo,height,tx" << std::endl;
                needsHeader = false;
            }
            if (!needsHeader)
            {
                jobConverter.Convert(lineToCheck);
                outputFile << jobConverter.outputLine << std::endl;
                messenger.StatusMsg_Saving(saveCounter);
                ++saveCounter;
            }
        }
    }
    else if (filterMode == "-s")
    {
        XMCleaner::Converter::ShareLog::ToCSV shareConverter;
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
                outputFile << shareConverter.outputLine << std::endl;
                messenger.StatusMsg_Saving(saveCounter);
                ++saveCounter;
            }
        }
    }
    return;
}