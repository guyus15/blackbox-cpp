# blackbox-cpp
Black box recorder and data logger, written in C++.

## Installation
- `git clone https://github.com/guyus15/blackbox-cpp`
- `cd blackbox-cpp`
- `cmake -S . -B build -G <generator of choice>`
- Build project with selected build tool
- Make sure `config.json` is present in the same directory as the resulting executable

## Usage
Usage of the **blackbox** is very simple:
1. Connect serial cable from one of your computer's COM ports to panel's COM2 port.
2. Modify the COM port configuration setting in `config.json` to match the
selected COM port.
3. Run the **blackbox** executable from within the executable directory.
