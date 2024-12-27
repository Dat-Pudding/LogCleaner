[![Github All Releases](https://img.shields.io/github/downloads/Dat-Pudding/LogCleaner/total.svg)](https://github.com/Dat-Pudding/LogCleaner/releases)
[![GitHub release](https://img.shields.io/github/release/Dat-Pudding/LogCleaner/all.svg)](https://github.com/xmrig/xmrig/releases)
[![GitHub Release Date](https://img.shields.io/github/release-date/Dat-Pudding/LogCleaner.svg)](https://github.com/Dat-Pudding/LogCleaner/releases)
[![GitHub license](https://img.shields.io/github/license/Dat-Pudding/LogCleaner.svg)](https://github.com/Dat-Pudding/LogCleaner/blob/master/LICENSE)
[![GitHub stars](https://img.shields.io/github/stars/Dat-Pudding/LogCleaner.svg)](https://github.com/Dat-Pudding/LogCleaner/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/Dat-Pudding/LogCleaner.svg)](https://github.com/Dat-Pudding/LogCleaner/network)

# LogCleaner
Purpose-built to extract information about hashrates, accepted/rejected shares and newly received jobs out of your standard XMRig log-file and saving it to respectively dedicated files.

## What can it do?
> **NOTE:** As of right now it's pretty bare-bones, this will change in the near future.

When run in default mode it will take the specified logfile and extract all lines that contain the hashrate reports with their timestamps.
By choosing one of the three available filter modes the lines that should be extracted can be set.

## How to use
You can run it either manually via command line or append it to your `start.cmd` in the XMRig directory to have it run as soon as XMRig stops and therefore automatically stripping the most recent log-file.

For it to have any data to work with it is **obligatory** to enable log-files in XMRig. 
You can do this by just appending a `-l yourLogfileNameHere` to your usual `xmrig.exe <YOUR_MINING_CREDENTIALS>` setup line.

### General usage
Independent of the platform, the overall usage syntax will always be as follows:

```.cmd
<executable> <logFilePath> <extractFilePath> <filterMode>
```

And the individual parameters consist of the following:
| Command/Parameter  | Description |
| ------------- | ------------- |
| `<executable>`  | Unless renamed and depending on the platform either `LogCleaner.exe` or `LogCleaner`  |
| `<logFilePath>`  | The file path AND file name of XMRig's log-file.<li>Can be absolute or relative to the executable</li><li>Has to be explicit with the file extension if the target file has one</li><li>Should be the same as the one specified in XMRig settings</li><br>Example: `./logs/miner.log`  |
| `<extractFilePath>`  | The file path AND name of the desired output file.<li>Can be absolute or relative to the executable</li><li>Has to be explicit with the file extension</li><li>If a subdirectory is desired as target, this subdirectory has to already exist</li><br>Example: `./cleaned/hashRates.csv`  |
| `<filterMode>`  | Defines the type of extracted information<li>`-h` extracts hashrate information</li><li>`-j` extracts new-job-reception information</li><li>`-s` extracts accepted/rejected share information</li>  |

#### Syntax examples
On Windows:
```.cmd
LogCleaner.exe miner.log ./cleaned/hashes.csv -h
```
On Linux:
```.bash
LogCleaner miner.log ./cleaned/hashes.csv -h
```

### Examples
#### Usage examples - Windows
Given a directory structure like this:
```
[C:\]═╦[\xmrig\]═╦[\cleaned\]
      ╠[<other>] ╠[SHA256sums]
      ╚[<stuff>] ╠[LogCleaner.exe]
                 ╠[miner.log]
                 ╠[WinRing64]
                 ╠[start.cmd]
                 ╚[xmrig.exe]
```
We can either directly run it from the command line with:
```.cmd
C:\xmrig\LogCleaner.exe miner.log .\cleaned\hashes.csv -h
```
After which we'll find `hashes.csv` within the `\cleaned\` directory, containing our extracted information and making our structure look like this:
```
[C:\]═╦[\xmrig\]═╦[\cleaned\]══[hashes.csv]
      ╠[<other>] ╠[other]
      ╚[<stuff>] ╚[stuff]
```

Or in case that we want to keep it updating the output after each mining session we simply edit XMRig's `start.cmd` content from this:
```.cmd
@echo off
cd /d "%~dp0"
xmrig.exe <YOUR_MINING_CREDENTIALS> -l miner.log
pause
```
To this:
```.cmd
@echo off
cd /d "%~dp0"
xmrig.exe <YOUR_MINING_CREDENTIALS> -l miner.log
LogCleaner.exe miner.log .\cleaned\hashes.csv -h
del miner.log
pause
```
Since multi-filtering (more than one filterMode at a time) isn't yet implemented, to get all available output information we have to write it like this:
```.cmd
@echo off
cd /d "%~dp0"
xmrig.exe <YOUR_MINING_CREDENTIALS> -l miner.log
LogCleaner.exe miner.log .\cleaned\hashes.csv -h
LogCleaner.exe miner.log .\cleaned\shares.csv -s
LogCleaner.exe miner.log .\cleaned\jobs.csv -j
del miner.log
pause
```
This will result in our exemplary directory structure looking like this:
```
[C:\]═╦[\xmrig\]═╦[\cleaned\]═╦[hashes.csv]
      ╠[<other>] ╠[other]     ╠[shares.csv]
      ╚[<stuff>] ╚[stuff]     ╚[jobs.csv]
```

We have added `del miner.log` here as to mitigate already stripped lines from being read twice. Leave it out if you have other ways of dealing with duplicate lines in e.g. your data processing software.

### Compiling
You can either build it yourself from the code in `/source/`.

When compiling yourself make sure to use at least `C++17` or newer, since the code utilises the non-experimental `std::filestream` for reading/writing. The code itself was written in a `C++22` environment.
