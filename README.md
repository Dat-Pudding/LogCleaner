# LogCleaner
Purpose-built to extract information about hashrates, accepted/rejected shares and newly received jobs out of your standard XMRig log-file and saving it to respectively dedicated files.

## What can it do?
> **NOTE:** As of right now it's pretty bare-bones, this will change in the near future.

When run in default mode it will take the specified logfile and extract all lines that contain the hashrate reports with their timestamps.

## How to use
You can run it either manually via command line or append it to your `start.cmd` in the XMRig directory to have it run as soon as XMRig stops and therefore automatically stripping the most recent log-file.

For it to have any data to work with it is **obligatory** to enable log-files in XMRig. You can do this by just appending a `-l yourLogfileNameHere` to your usual `xmrig.exe -bla blabla blabla.bla -bla blabla` setup line. It does not need a file extension of any sort but using `.log` makes things easier and faster to comprehend on a gaze what's what.

### General usage
Independent of the platform, the overall usage syntax will always be as follows:

```.sh
<executable> <logFilePath> <extractFilePath> <filterMode>
```

And the individual parameters consist of the following:
| Command/Parameter  | Description |
| ------------- | ------------- |
| `<executable>`  | Unless renamed and depending on the platform either `LogCleaner.exe` or `LogCleaner`  |
| `<logFilePath>`  | The file path AND file name of XMRig's log-file. <br></br><li>Can be absolute or relative to the executable</li><li>Has to be explicit with the file extension e.g.: `./logs/miner.log`</li><li>Should be the same as the one specified in XMRig settings</li>  |
| `<extractFilePath>`  | The file path AND name of the desired output file.<br></br><li>Can be absolute or relative to the executable</li><li>Has to be explicit with the file extension if the target file has one</li><li>If a subdirectory is desired as target, this subdirectory has to already exist</li> Example: `./cleanedLogs/hashRates.log`  |
| `<filterMode>`  | Defines the type of extracted information<li>`-h` extracts hashrate information</li><li>`-j` extracts new-job-reception information</li><li>`-s` extracts accepted/rejected share information</li>  |

#### Examples
##### Usage example - Windows
Assuming we're on a windows machine, have placed the `LogCleaner.exe` in the same directory as our `xmrig.exe` and its `start.cmd` in `C:\xmrig\`. In this scenario the log-file is set to just be in the same directory with the name `miner.log`. We want our output files to be generated in a subdirectory called `cleanedLogs` and we only want to know at which times we got shares accepted, this information should be stored in a file called `shares` without an file extension.

To achieve this we have XMRig run for a while with enabled log-files and then close it. Afterwards we start a CMD or Powershell window and navigate to the directory by typing:

```.cmd
cd C:\xmrig\
```

After pressing the `Enter` key, we verify that we are at the right place by typing:

```.cmd
dir
```

This should show all files in our current directory of which we care about `LogCleaner.exe` and `miner.log` being present. To create our desired target directory we type in:

```.cmd
mkdir cleanedLogs
```

Using the `dir` command again should now also lost a directory named `cleanedLogs`. Now that we're all set we actually get started by typing in:

```.cmd
LogCleaner.exe miner.log ./cleanedLogs/shares -s
```

Now it should start working while showing its current status and close itself upon finishing. You can now open your extracted file however you want to process the information.
> **NOTE:** The output being proper comma-separated values to improve usability with data processing software is currently in the making. For the first (and already outdated) converter prototype is available in [/concept_wip/](/concept_wip/)

### Usage on Windows
You can either build it yourself from the code in `/source/` or wait for me to upload the compiled executable.

When compiling yourself make sure to use at least `C++17` or newer, since the code utilises the non-experimental `std::filestream` for reading/writing. The code itself was written in a `C++22` environment.

#### Manual usage - Windows 
 1. Open a *CMD* or *Powershell* window
 2. Within the shell navigate to the directory of your `LogCleaner` executable:

```.cmd
cd DRIVE:\dir\thatContains\LogCleaner.exe
```
> **NOTE:** This likely is your `Download` directory or your build directory if you compiled yourself

 3. Enter the following line into your command line, replacing the placeholders to your liking:
     
```.cmd
LogCleaner.exe path/of/log-file desired/path/of/extract-file filterMode
```

 4. Watch it go through the log-file
 5. Notice the newly appeared file of the specified name in the specified directory 

#### Usage via `start.cmd`- Windows
To use the LogCleaner from within XMRig we have to quickly set it up for that.

##### Setup
 1. Put the executable into the same directory as `xmrig.exe`
 2. In this directory open the `start.cmd` for editing 
 3. Insert the following line in-between the lines of your `xmrig.exe` setup and the `pause` command and fill in the placeholders to your liking:

```.bat
LogCleaner.exe nameOfLogfile nameOfDesiredOutputFile filterMode
```
 4. Save and close the changed `start.cmd` file

##### Usage
 1. Start up XMRig as you normally would with the `start.cmd`
 2. Mine happily
 3. As soon as you hit `Ctrl`+`C` or close XMRig's window you can watch it go through the generated log-file
 5. Once done, notice the newly generated file of the specified name in the specified directory 