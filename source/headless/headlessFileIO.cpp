#include "headlessCore.h"
namespace fs = std::filesystem;


void XMCleaner::FileIO::TextFileProcessor::ReadLine
(
    std::string& logfilePath,
    bool& needsHeader
)
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
            CheckLine(line, needsHeader);
            ++lineCounter;
        }
        inputFile.close();
    }
    return;
}

void XMCleaner::FileIO::TextFileProcessor::CheckLine
(
    std::string& lineToCheck,
    bool& needsHeader
)
{
    std::regex speedPattern("(speed 10s/60s/15m)");
    std::regex jobPattern("(new job from)");
    std::regex acceptPattern("(accepted)");
    std::regex rejectPattern("(rejected)");

    if (std::regex_search(lineToCheck, speedPattern))
    {
        WriteLine(lineToCheck, outputPathSpeed, needsHeader);
    }

    else if (std::regex_search(lineToCheck, jobPattern))
    {
        WriteLine(lineToCheck, outputPathJobs, needsHeader);
    }

    else if (std::regex_search(lineToCheck, acceptPattern))
    {
        WriteLine(lineToCheck, outputPathShares, needsHeader);
    }
    else if (std::regex_search(lineToCheck, rejectPattern))
    {
        WriteLine(lineToCheck, outputPathShares, needsHeader);
    }
    return;
}

void XMCleaner::FileIO::TextFileProcessor::WriteLine
(
    std::string& lineToCheck,
    std::string& outputFile,
    bool& needsHeader
)
{
    if (outputFile == outputPathSpeed)
    {
        XMCleaner::Converter::HashLog::ToCSV hashConverter;
        std::ofstream speedOutput(outputPathSpeed, std::ios::out | std::ios::app);

        if (!speedOutput.is_open())
        {
            speedOutput.open(outputPathSpeed);
        }
        else if (speedOutput.is_open())
        {
            if (needsHeader)
            {
                speedOutput << "date,time,system,10s,60s,15m,max" << std::endl;
                needsHeader = false;
            }
            if (!needsHeader)
            {
                hashConverter.Convert(lineToCheck);
                speedOutput << hashConverter.outputLine << std::endl;
            }
        }
    }
    else if (outputFile == outputPathJobs)
    {
        XMCleaner::Converter::JobLog::ToCSV jobConverter;
        std::ofstream jobsOutput(outputPathJobs, std::ios::out | std::ios::app);
        std::regex stringPattern("(new job from)");

        if (!jobsOutput.is_open())
        {
            jobsOutput.open(outputPathJobs);
        }
        else if (jobsOutput.is_open())
        {
            if (needsHeader)
            {
                jobsOutput << "date,time,system,server,diff,algo,height,tx" << std::endl;
                needsHeader = false;
            }
            if (!needsHeader)
            {
                jobConverter.Convert(lineToCheck);
                jobsOutput << jobConverter.outputLine << std::endl;
            }
        }
    }
    else if (outputFile == outputPathShares)
    {
        XMCleaner::Converter::ShareLog::ToCSV shareConverter;
        std::ofstream sharesOutput(outputPathShares, std::ios::out | std::ios::app);

        if (!sharesOutput.is_open())
        {
            sharesOutput.open(outputPathShares);
        }
        else if (sharesOutput.is_open())
        {
            if (needsHeader)
            {
                sharesOutput << "date,time,system,status,numAccept,numReject,difficulty,latency" << std::endl;
                needsHeader = false;
            }
            if (!needsHeader)
            {
                shareConverter.Convert(lineToCheck);
                sharesOutput << shareConverter.outputLine << std::endl;
            }
        }
    }
}