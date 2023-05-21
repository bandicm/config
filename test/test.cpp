#include <iostream>

#include "../lib/config.hpp"

using namespace std;

int main() {

    config mycfg ("../example/config.cfg", {"Username", "API", "Domain" });

    // cout << "HAloooo" << endl;
    cout << mycfg.element["consolePrintLogs"];
    

    return 0;
}