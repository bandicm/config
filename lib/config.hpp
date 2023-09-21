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
    vector<string> necessary;
    map<string, string> element;

    bool isHaveNecessary(); 
    bool init(const string _configFilePath);   

    public:

    config(const string _configFilePath, const vector<string> _necessary = {});
    string operator[] (const string& key);
    void print();
    
};


#endif