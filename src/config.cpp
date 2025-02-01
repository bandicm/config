#include "../lib/config.hpp"


marcelb::config::config(const string _configFilePath, const vector<string> _necessary):
   configFilePath(_configFilePath), necessary(_necessary) {

   if(!init(_configFilePath)) {
      throw string("[ERROR] Init config file ");
   }
   if (!isHaveNecessary()) {
      throw string("[ERROR] Configuration file does not have all the required fields ");
   }
}


string marcelb::config::operator[](const string& key) {
   if (element.count(key)) {
      return element[key];
   } 
   return "";
}

void marcelb::config::update(const string& key, const string& value) {
   element[key] = value;
   update_file(key);
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


void marcelb::config::update_file(const string& key) {
   ifstream configFile(configFilePath);
   if (!configFile.is_open()) {
      throw invalid_argument("[ERROR] Cant open config file for update!");
   }

   vector<string> lines;
   string line;
   bool update = false;
   while (getline(configFile, line)) {

      size_t pos = line.find(key + "=");
      if (pos != string::npos) {

         size_t eqPos = line.find("=", pos);
         size_t semicolonPos = line.find(";", eqPos);
         if (eqPos != string::npos && semicolonPos != string::npos) {
            line = key + "=" + element[key] + ";";
            update = true;
         }
      }
      lines.push_back(line);
   }
   if (!update) {
      line = key + "=" + element[key] + ";";
      lines.push_back(line);
   }
   configFile.close();

   ofstream configFileOut(configFilePath);
   if (!configFileOut.is_open()) {
      throw invalid_argument("[ERROR] Cant update config file!");
   }

   for (const string& updatedLine : lines) {
      configFileOut << updatedLine << endl;
   }

   configFileOut.close();
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