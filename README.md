# ut
### Uptime Tool

Command line application for windows in C++ to see the system uptime. It should be noted that the Win32 API Call [GetTickCount()](https://docs.microsoft.com/en-us/windows/desktop/api/sysinfoapi/nf-sysinfoapi-gettickcount) is used, so there will be a wrap around after 49.7 days of uptime.

Tests have been implemented using the [Microsoft Unit Testing Framework for C++](https://docs.microsoft.com/en-us/visualstudio/test/how-to-use-microsoft-test-framework-for-cpp?view=vs-2019)
