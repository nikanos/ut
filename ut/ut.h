#pragma once

#include <string>

const int SECONDS_PER_SECOND = 1;
const int SECONDS_PER_MINUTE = 60;
const int SECONDS_PER_HOUR = 3600;
const int SECONDS_PER_DAY = SECONDS_PER_HOUR * 24;

std::string FormatSecondsLong(unsigned int sec);
std::string FormatSecondsShort(unsigned int sec);