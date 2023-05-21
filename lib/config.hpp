#ifndef _CFG_
#define _CFG_

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

void clearWhiteSpaces(string &a);
bool clearComments(string &a);
void parseConfigLine(const string a, string &b, string &c);

class config {
    public:
    vector<string> necessary; // = {"Username", "API", "Domain", "consolePrintLogs", "DinioServer1", "DinioServer2", "DinioGetIPURL", "DinioServer1Port", "DinioServer2Port" };
    map<string, string> element;

    config(const string _configFilePath, const vector<string> _necessary = {});

    void print();
    bool init(const string _configFilePath);   
    bool isHaveNecessary(); 
    
};


#endif