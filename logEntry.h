// struct holding parsed data
#pragma once

#include <iostream>

using namespace std; 

struct LogEntry {
    string timestamp; 
    string level; // error, warning, info, debug 
    string message; 
    string request_id; 
    string user_id; 
    
    string free_memory;  // available memory on the server
    string total_memory; // total memory on the server
    
    string user_agent; // user's web browser
    
    string server_id; 
    string start_time; // start time of the server    

};
void logParser(string& rawData);