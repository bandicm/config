#include <iostream>
#include "../lib/config.hpp"

using namespace std;
using namespace marcelb;

int main() {

    config mycfg ("../example/config.cfg", {"Username", "API", "Domain" });
    cout << mycfg["consolePrintLogs"];

    return 0;
}