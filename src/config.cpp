#include "../lib/config.hpp"


marcelb::config::config(const string _configFilePath, const vector<string> _necessary) {
   necessary = _necessary;
   if(!init(_configFilePath)) {
      throw string("[ERROR] Init config file ");
   }
   if (!isHaveNecessary()) {
      throw string("[ERROR] Configuration file does not have all the required fields ");
   }
}


string marcelb::config::operator[](const string& key) {
   return element[key];
}


bool marcelb::config::init(const string _configFilePath) {

   ifstream configFile; 
   configFile.open(_configFilePath, ios::in);  
   if(!configFile) { 
      //printf ("[CRITICAL ERROR] Nema konfiguracijske datoteke!");
      return false;
   }
   
   else {
      for (string line; getline(configFile, line); ) {
         clearWhiteSpaces(line);
         if(clearComments(line) && !line.empty()) { // samo ako nije komentar
            string key, value; 
            parseConfigLine(line, key, value);
            element[key] = value;
         } 
      }
   }

   configFile.close();
   return true;
}


void marcelb::config::print() {
    for(auto i : element) {
        cout << i.first << " " << i.second << "\n";
    }

}


bool marcelb::config::isHaveNecessary() {
    bool necessaryHave = true;
    for (int i=0; i<necessary.size(); i++) {
        if (element[necessary[i]].empty()) {
            necessaryHave = false;
            break;
        }
    }

    return necessaryHave;
}


void marcelb::clearWhiteSpaces(string &a) {
   const char whitespaces[] = {' ', '\t'};
   for (int i=0; i<sizeof(whitespaces)/sizeof(const char); i++) {
      for (int j=0; j<a.length(); j++) {
         if (a[j] == whitespaces[i]) {
            a.erase(j, 1);
         }
      }
   }
}


bool marcelb::clearComments(string &a) {
   bool r = a[0] != '#';
   size_t commentLocation = a.find('#');
   if(commentLocation <= a.length()) {
      a = a.substr(0, commentLocation);
   }
   return r;
}


void marcelb::parseConfigLine(const string a, string &b, string &c) {

   size_t separatorLocation = a.find('=');
   b = a.substr(0, separatorLocation);
   string t;
   t = a.substr(separatorLocation + 1, a.length()-separatorLocation-1);
   separatorLocation = t.find(';');
   c = t.substr(0, separatorLocation);

}