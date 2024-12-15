# LogCleaner
Purpose-built to extract information about hashrates, accepted/rejected shares and newly received jobs out of your standard XMRig log file and saving it to respectively dedicated files.

## What can it do?
> **NOTE:** As of right now it's pretty bare-bones, this will change in the near future.
When run in default mode it will take the specified logfile and extract all lines that contain the hashrate reports with their timestamps.

## How to use
You can run it either manually via command line or append it to your `start.cmd` in the XMRig directory to have it run as soon as XMRig stops and therefore automatically stripping the most recent log file