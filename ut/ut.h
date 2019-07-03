#pragma once

#include <string>
#include <Windows.h>

const ULONGLONG SECONDS_PER_SECOND = 1;
const ULONGLONG SECONDS_PER_MINUTE = 60;
const ULONGLONG SECONDS_PER_HOUR = 3600;
const ULONGLONG SECONDS_PER_DAY = SECONDS_PER_HOUR * 24;

std::string FormatSecondsLong(ULONGLONG sec);
std::string FormatSecondsShort(ULONGLONG sec);