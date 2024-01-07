
# A library for loading a simple configuration file and accessing parameters

Easily load variable configuration parameters into your program using this library.


## Features

- Object oriented
- Principle key value
- Multiple configuration files supported
- Arbitrary key names
- Predefined necessary keys and enabled validation
- Strict configuration file format
- Comments in configuration file supported

## Installation

Just download the latest release and unzip it into your project. You can turn it on with:

```
#include config/lib/config.hpp
```

## Usage

```c++
#include <iostream>
#include "../lib/config.hpp"

using namespace std;

int main() {

    config mycfg ("../example/config.cfg", {"Username", "API", "Domain" });
    cout << mycfg["consolePrintLogs"];

    return 0;
}
```

### Configuration file example

```
Username=tom;
API=tom_and_jerry;
Domain=tom_and_jerry.example;

# dont touch this
consolePrintLogs=true;
```
## License

[APACHE 2.0](http://www.apache.org/licenses/LICENSE-2.0/)


## Support & Feedback

For support and any feedback, contact the address: marcelb96@yahoo.com.

## Contributing

Contributions are always welcome!

Feel free to fork and start working with or without a later pull request. Or contact for suggest and request an option.

