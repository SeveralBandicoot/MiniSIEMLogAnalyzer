// parses raw data logs 
#include <iostream>
#include <sstream>
#include <string>

#include "logEntry.h"

using namespace std; 

void printLog(LogEntry &entry) {
    cout << "\"timestamp\": " << entry.timestamp << endl; 
    cout << "\"level\": " << entry.level << endl; 
    cout << "\"message\": " << entry.message << endl;
    cout << "\"user_id\": " << entry.user_id << endl;   
    cout << "\"user_agent\": " << entry.user_agent << endl; 
}

void logParser(string& rawData) {
    LogEntry entry; 

    vector<string> tokens; // vector of string to save tokens
    vector<string> timestamp; 
    vector<string> message; 

    stringstream ss(rawData);
    stringstream dt; // date and time
    stringstream msg; // message

    string intermediate; 
    //----tokenizing using whitespace----
    while (getline(ss, intermediate, ' ')) { 
        tokens.push_back(intermediate);
    }

    // TIMESTAMP 

    //----concatenating date and time----
    for (size_t i = 0; i < 2; i++) { // push back the data and time from tokens vector to timestamp vector
        timestamp.push_back(tokens[i]);
    }

    for (string& word : timestamp) {
        dt << word; // append each word 
    }
    //----extract date and time from timestamp vector----
    string entireDTStream = dt.str();
    string date = entireDTStream.substr(5, 10);
    string time = entireDTStream.substr(20);
    string timeStamp = date + "T" + time +"Z";
    
    entry.timestamp = timeStamp; // assign concatenated timestamp to the log entries timestamp defined in LogEntry.h

    // LEVEL

    //----extract and assign level----
    string levelStream = tokens[5];
    levelStream = levelStream.substr(6);
    entry.level = levelStream; 

    // MESSAGE 

    //----concatenating message----
    for (size_t i = 21; i < tokens.size(); i++) {
        message.push_back(tokens[i]);
    }

    for (string& word : message) {
        msg << word << " "; // append each word
    }
    //----extract message from message vector----
    string msgStream = msg.str();
    msgStream = msgStream.substr(4);
    entry.message = msgStream;

    // USER ID
    string userIdStream = tokens[12];
    userIdStream = userIdStream.substr(5);
    entry.user_id = userIdStream; 

    // USER AGENT 
    string userAgentStream = tokens[13];
    userAgentStream = userAgentStream.substr(3);
    entry.user_agent = userAgentStream;

    // PRINTS JSON LOG
    printLog(entry);

    //cout << entry.user_agent << endl; 
    /*for (string word : tokens) { // prints out tokens vector line by line (element by element)
        cout << word << endl;
    }*/

}