// handles input (file I/O used) 
#include <iostream>
#include <fstream>
#include <string>
#include "logParser.cpp"

using namespace std; 

void FileReader() {
    string logLine; 

    ifstream ReadSysLog("samplelog.txt");

    getline(ReadSysLog, logLine, '\n');
    logParser(logLine); // pass the raw data through into logParser.cpp
}