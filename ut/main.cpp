#include "stdafx.h"
#include "ut.h"

using namespace std;

struct Options
{
	bool showLongFormat = false;
	bool showUsage = false;
};

bool ParseArguments(int argc, char* argv[], Options& options)
{
	for (int i = 1; i < argc; i++)
	{
		string arg(argv[i]);
		if (arg == "-l" || arg == "-L" || arg == "--long")
			options.showLongFormat = true;
		else if (arg == "-s" || arg == "-S" || arg == "--short")
			options.showLongFormat = false;
		else if (arg == "-h" || arg == "-H" || arg == "--help")
			options.showUsage = true;
		else
			return false; //unhandled argument passed
	}
	return true;
}

void ShowUsage(const char* appName)
{
	cout << "Uptime Tool\n";
	cout << "Usage:" << appName << " [-h] [-H] [--help] [-l] [-L] [--long] [-s] [-S] [--short]\n";
	cout << appName << " -l, -L or --long: Shows long format\n";
	cout << appName << " -s, -S or --short: Shows short format (Default)\n";
	cout << appName << " -h, -H or --help: Shows this screen\n";
}

int main(int argc, char* argv[])
{
	Options options;
	if (ParseArguments(argc, argv, options))
	{
		if (options.showUsage)
		{
			ShowUsage(argv[0]);
			return 0;
		}

		ULONGLONG secondsUptime = GetTickCount64() / 1000;
		if (options.showLongFormat)
			cout << "Windows has been running for " << FormatSecondsLong(secondsUptime) << endl;
		else
			cout << FormatSecondsShort(secondsUptime) << endl;
		return 0;
	}
	else
	{
		ShowUsage(argv[0]);
		return 1;
	}
}