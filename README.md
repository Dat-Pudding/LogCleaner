# LogCleaner
Purpose-built to extract information about hashrates, accepted/rejected shares and newly received jobs out of your standard XMRig log-file and saving it to respectively dedicated files.

## What can it do?
> **NOTE:** As of right now it's pretty bare-bones, this will change in the near future.

When run in default mode it will take the specified logfile and extract all lines that contain the hashrate reports with their timestamps.

## How to use
You can run it either manually via command line or append it to your `start.cmd` in the XMRig directory to have it run as soon as XMRig stops and therefore automatically stripping the most recent log-file.

## Windows
You can either build it yourself from the code in `/source/` or wait for me to upload the compiled executable.

When compiling yourself make sure to use at least `C++17` or newer, since the code utilises the non-experimental `std::filestream` for reading/writing. The code itself was written in a `C++22` environment.

### Manual usage
 -1. Open a terminal/command line interface (CLI)
 -2. Within the terminal navigate to the directory of your `LogCleaner` executable

     ```sh
     cd DRIVE:\dir\thatContains\LogCleaner.exe
     ```

 -3. Enter the following line into your command line, replacing the placeholders to your liking:
     
     ```batch
     LogCleaner.exe path/of/log-file desired/path/of/extract-file filterMode
     ```

 -4. Watch it go through the log-file

### Usage via `start.cmd`