#include "stdafx.h"
#include "ut.h"
#include <iomanip>

using namespace std;

string FormatSecondsLong(unsigned int sec)
{
	if (sec == 0)	
		return "0 seconds";

	struct DatePart
	{
		const char* name;
		unsigned int seconds;
	};

	DatePart dateParts[] =
	{
		{ "day", SECONDS_PER_DAY },
		{ "hour", SECONDS_PER_HOUR },
		{ "minute", SECONDS_PER_MINUTE },
		{ "second", SECONDS_PER_SECOND }
	};
	ostringstream os;
	bool printed = false;

	for (int i = 0; i < sizeof(dateParts) / sizeof(DatePart); i++)
	{
		int n = sec / dateParts[i].seconds;
		if (n > 0)
		{
			os << (printed ? ", " : "") << n << ' ' << dateParts[i].name << (n > 1 ? "s" : "");
			sec %= dateParts[i].seconds;
			printed = true;
		}
	}
	return os.str();
}

string FormatSecondsShort(unsigned int sec)
{
	int days = sec / SECONDS_PER_DAY;
	sec %= SECONDS_PER_DAY;
	int hours = sec / SECONDS_PER_HOUR;
	sec %= SECONDS_PER_HOUR;
	int minutes = sec / SECONDS_PER_MINUTE;
	sec %= SECONDS_PER_MINUTE;
	int seconds = sec;

	ostringstream os;
	if (days > 0)
		os << days << '.';
	os << setfill('0') << setw(2) << hours << ':';
	os << setfill('0') << setw(2) << minutes << ':';
	os << setfill('0') << setw(2) << seconds;
	return os.str();
}