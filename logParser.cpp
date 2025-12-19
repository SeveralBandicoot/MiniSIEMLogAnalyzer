#include <iostream>
#include <fstream>
#include <string>

#include "logEntry.h"

using namespace std; 

int main() {
    string logLine; 

    ifstream ReadSysLog("/var/log/system.log");

    for (int i = 0; i < 100; i ++) {
        getline(ReadSysLog, logLine, '\n');
        cout << logLine << endl; 
    }
    
    return 0; 
}