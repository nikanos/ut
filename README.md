### UT
**Uptime Tool**

Command line application for windows in C++ to see the system uptime.


### Command line arguments
  **-l, --long**			Shows long uptime format

  **-s, --short**			Shows short uptime format (Default)

### Examples
1. Show windows uptime in long format

        ut -l
        
    **Windows has been running for 5 hours, 55 minutes, 1 second**

2. Show windows uptime in short format
        
        ut -s

    **05:55:01**

#### Notes
Tests have been implemented using the [Microsoft Unit Testing Framework for C++](https://docs.microsoft.com/en-us/visualstudio/test/how-to-use-microsoft-test-framework-for-cpp?view=vs-2019)
