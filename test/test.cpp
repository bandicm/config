#include <iostream>
#include "../lib/config.hpp"
#include <unistd.h>

using namespace std;
using namespace marcelb;

int main() {

    config mycfg ("../example/config.cfg", {"Username", "API", "Domain" });
    cout << mycfg["consolePrintLogs"];

    mycfg.update("Baba2", "Janja");
    cout << mycfg["Baba"];

    sleep(10000);
    return 0;
}