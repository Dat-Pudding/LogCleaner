# LogCleaner
Purpose-built to extract information about hashrates, accepted/rejected shares and newly received jobs out of your standard XMRig log-file and saving it to respectively dedicated files.

## What can it do?
> **NOTE:** As of right now it's pretty bare-bones, this will change in the near future.

When run in default mode it will take the specified logfile and extract all lines that contain the hashrate reports with their timestamps.

## How to use
You can run it either manually via command line or append it to your `start.cmd` in the XMRig directory to have it run as soon as XMRig stops and therefore automatically stripping the most recent log-file.

For it to have any data to work with it is **obligatory** to enable log-files in XMRig. You can do this by just appending a `-l yourLogfileNameHere` to your usual `xmrig.exe -bla blabla blabla.bla -bla blabla` setup line.

### General usage
Independent of the platform, the overall usage syntax will always be as follows:

```.sh
<executable> <logFilePath> <extractFilePath> <filterMode>
```

And the individual parameters consist of the following:
| Command/Parameter  | Description |
| ------------- | ------------- |
| `<executable>`  | Unless renamed and depending on the platform either `LogCleaner.exe` or `LogCleaner`  |
| `<logFilePath>`  | The file path AND file name of XMRig's log-file.<li>Can be absolute or relative to the executable</li><li>Has to be explicit with the file extension if the target file has one</li><li>Should be the same as the one specified in XMRig settings</li><br>Example: `./logs/miner.log`  |
| `<extractFilePath>`  | The file path AND name of the desired output file.<li>Can be absolute or relative to the executable</li><li>Has to be explicit with the file extension</li><li>If a subdirectory is desired as target, this subdirectory has to already exist</li><br>Example: `./cleanedLogs/hashRates.csv`  |
| `<filterMode>`  | Defines the type of extracted information<li>`-h` extracts hashrate information</li><li>`-j` extracts new-job-reception information</li><li>`-s` extracts accepted/rejected share information</li>  |

#### Syntax examples
On Windows:
```.cmd
LogCleaner.exe miner.log ./cleanedLogs/hashes.csv -h
```
On Linux:
```.bash
LogCleaner miner.log ./cleanedLogs/hashes.csv -h
```

### Examples
#### Usage examples - Windows
Given a directory structure like this:
```
[C:\]---[\xmrig\]---[\cleanedLogs\]
      |-[<other>] |-[SHA256sums]
      |-[<stuff>] |-[LogCleaner.exe]
                  |-[miner.log]
                  |-[WinRing64]
                  |-[start.cmd]
                  |-[xmrig.exe]
```
We can either directly run it from the command line with:
```.cmd
C:\xmrig\LogCleaner.exe miner.log .\cleanedLogs\hashes.csv -h
```
After which we'll find `hashes.csv` within the `\cleanedLogs\` directory, containing our extracted information and making our structure look like this:
```
[C:\]═╦═[\xmrig\]═╦═[\cleanedLogs\]═══[hashes.csv]
      ╠═[<other>] ╠═[other]
      ╚═[<stuff>] ╚═[stuff]
```

Or in case that we want to keep it updating the output after each mining session we simply edit XMRig's `start.cmd` content from this:
```.cmd
@echo off
cd 
xmrig.exe <YOUR_MINING_CREDENTIALS> -l miner.log
pause
```
To this:
```.cmd
@echo off
cd
xmrig.exe <YOUR_MINING_CREDENTIALS> -l miner.log
LogCleaner.exe miner.log .\cleanedLogs\hashes.csv -h
rm miner.log
pause
```

> **NOTE:** The output being proper comma-separated values to improve usability with data processing software is currently in the making. The first (and already outdated) converter prototype is readable in [/concept_wip/](/concept_wip/)

### Compiling
You can either build it yourself from the code in `/source/` or wait for me to upload the compiled executable.

When compiling yourself make sure to use at least `C++17` or newer, since the code utilises the non-experimental `std::filestream` for reading/writing. The code itself was written in a `C++22` environment.
