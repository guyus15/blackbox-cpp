# blackbox-cpp

![Build](https://github.com/guyus15/blackbox-cpp/actions/workflows/build.yml/badge.svg)
![CodeQL](https://github.com/guyus15/blackbox-cpp/actions/workflows/codeql.yml/badge.svg)

Black box recorder and data logger, written in C++.

## Installation
- `git clone --recurse-submodules https://github.com/guyus15/blackbox-cpp`
- `cd blackbox-cpp`
- `cmake -S . -B build -G <generator of choice>`
- Build project with selected build tool
- Make sure `config.json` is present in the same directory as the resulting executable

### Additional CMake Options
There are a few options available to configure the build. These can be used in the command line with the prefex `-D`:
- `TEST` - Enables the building of tests as an executable alongside the main executable.
- `ENABLE_INFO_OUTPUT` - Enables verbose info output. By default this is set to `OFF`, so only
  error messages are output.
- `ENABLE_PROFILING` - Enables profiling across the project. This will output profiling results to a 
  JSON file which can be inserted into `chrome://tracing` in most browsers.

## Usage
Usage of the **blackbox** is very simple:
1. Connect serial cable from one of your computer's COM ports to panel's COM2 port.
2. Modify the COM port configuration setting in `config.json` to match the
selected COM port.
3. Run the **blackbox** executable from within the executable directory.

## Configuration
All configuration of the **blackbox** program is done through the accompanying `config.json` file.

### Logging
- Logging can be enabled/disabled with the "enabled" setting in the logging category.
- The directory to which log files are created can be set with the "directory" configuration setting.
- The name of the log file to which entries are added can be changed by modifying the "logfile" setting.
- Verbose logging can be switched on/off with the "verbose-logging" setting:
  - Verbose loggingg means that packet values are decoded into a human-readable format before they are written
    to the log file.
  - Disabling verbose logging will mean that the raw hexadecimal byte values of the packet data will be written
    to the log file. These can later be decoded.
    
### Serial
Serial settings can be configured in the "serial" section of the configuration file. However, with the exception of the COM port, it is highly unlikely that 
these settings will need to be changed.

- The COM port can be changed per platform - Windows and Linux - with the "com" setting.
- The timeout can be set with the "timeout" setting.
- The bytesize can be set with the "bytesize" setting. Valid values for the bytesize are the following:
  - `5, 6, 7, 8, 16`
- The parity can be set with the "parity" setting. Valid values for the parity are the following:
  - `none, even, odd, mark, space`
- The stopbit can be set with the "stopbit" setting. Valid values for the stopbit are the following:
  - `1, 1.5, 2`
  
### Timing
Timing setting can be configured in the "timing" section of the configuration file. Timing covers time period used between polls and pings to the panel.

- The polling time period can be set with the "poll-time-period" setting. This is measured in seconds and represents the time between polls in the initial scan of panel loops.
- The ping time period can be set with the "ping-time-period" setting. This is also measured in seconds and represents the time between pinging the panel for points with existing devices.

<br />

If at all you make changes to cause your configuration to fail, please refer to this repository to see the default configuration file (`config.json`).
