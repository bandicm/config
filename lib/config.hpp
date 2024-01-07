#ifndef _CFG_
#define _CFG_

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

namespace marcelb {

/**
 * Clears white fields from a string
*/
void clearWhiteSpaces(string &a);

/**
 * Removes comments from a string
 * Returns false if the entire line is a comment, 
 * false if it is not
*/
bool clearComments(string &a);

/**
 * It parses the line of the configuration file, 
 * receives the string line and returns the key, 
 * value pair via reference
*/
void parseConfigLine(const string a, string &b, string &c);

/**
 * Configuration class - at the level of a single file
*/
class config {
    vector<string> necessary;
    map<string, string> element;

    /**
     * Internal method to check if necessary keys exist
    */
    bool isHaveNecessary(); 

    /**
     * Internal method for initialization
    */
    bool init(const string _configFilePath);   

    public:

    /**
     * Constructor, receives a string of configuration file paths
     * and a vector of strings with necessary keys (optional)
    */
    config(const string _configFilePath, const vector<string> _necessary = {});

    /**
     * Operator [] to access individual configuration parameter via key
    */
    string operator[] (const string& key);

    /**
     * Method to print all configuration key value pairs
    */
    void print();
    
};

}

#endif