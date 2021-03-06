#include "stdafx.h"
#include "ut.h"
#include <iomanip>

using namespace std;

string FormatSecondsLong(ULONGLONG sec)
{
	if (sec == 0)	
		return "0 seconds";

	struct DatePart
	{
		const char* name;
		ULONGLONG seconds;
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
		ULONGLONG n = sec / dateParts[i].seconds;
		if (n > 0)
		{
			os << (printed ? ", " : "") << n << ' ' << dateParts[i].name << (n > 1 ? "s" : "");
			sec %= dateParts[i].seconds;
			printed = true;
		}
	}
	return os.str();
}

string FormatSecondsShort(ULONGLONG sec)
{
	ULONGLONG days = sec / SECONDS_PER_DAY;
	sec %= SECONDS_PER_DAY;
	ULONGLONG hours = sec / SECONDS_PER_HOUR;
	sec %= SECONDS_PER_HOUR;
	ULONGLONG minutes = sec / SECONDS_PER_MINUTE;
	sec %= SECONDS_PER_MINUTE;
	ULONGLONG seconds = sec;

	ostringstream os;
	if (days > 0)
		os << days << '.';
	os << setfill('0') << setw(2) << hours << ':';
	os << setfill('0') << setw(2) << minutes << ':';
	os << setfill('0') << setw(2) << seconds;
	return os.str();
}