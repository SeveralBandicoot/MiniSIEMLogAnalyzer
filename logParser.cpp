// parses raw data logs 
#include <iostream>
#include <sstream>
#include <string>

#include "logEntry.h"

using namespace std; 

void logParser(string& rawData) {
    LogEntry entry; 

    vector<string> tokens; // vector of string to save tokens
    vector<string> timestamp; 

    stringstream ss(rawData);
    stringstream dt; // date and time

    string intermediate; 
    //----tokenizing using whitespace----
    while (getline(ss, intermediate, ' ')) { 
        tokens.push_back(intermediate);
    }
    //----concatenating date and time----
    for (size_t i = 0; i < 2; i++) { // push back the data and time from tokens vector to timestamp vector
        timestamp.push_back(tokens[i]);
    }

    for (string& word : timestamp) {
        dt << word; // append each word 
    }
    //----extract date and time from timestamp vector----
    string entireStream = dt.str();
    string date = entireStream.substr(5, 10);
    string time = entireStream.substr(20);
    string timeStamp = date + "T" + time +"Z";
    
    entry.timestamp = timeStamp; // assign concatenated timestamp to the log entries timestamp defined in LogEntry.h
}