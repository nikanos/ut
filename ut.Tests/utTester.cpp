#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ut/ut.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace utTests
{
	TEST_CLASS(utTester)
	{
	public:

		//FormatSecondsShort Tests Start
		TEST_METHOD(FormatSecondsShort_Second_ReturnsExpected)
		{
			string str = FormatSecondsShort(SECONDS_PER_SECOND);
			Assert::AreEqual(str, "00:00:01"s);
		}

		TEST_METHOD(FormatSecondsShort_Minute_ReturnsExpected)
		{
			string str = FormatSecondsShort(SECONDS_PER_MINUTE);
			Assert::AreEqual(str, "00:01:00"s);
		}

		TEST_METHOD(FormatSecondsShort_Hour_ReturnsExpected)
		{
			string str = FormatSecondsShort(SECONDS_PER_HOUR);
			Assert::AreEqual(str, "01:00:00"s);
		}

		TEST_METHOD(FormatSecondsShort_Day_ReturnsExpected)
		{
			string str = FormatSecondsShort(SECONDS_PER_DAY);
			Assert::AreEqual(str, "1.00:00:00"s);
		}

		TEST_METHOD(FormatSecondsShort_DayHourMinuteAndSecond_ReturnsExpected)
		{
			string str = FormatSecondsShort(SECONDS_PER_DAY + SECONDS_PER_HOUR + SECONDS_PER_MINUTE + SECONDS_PER_SECOND);
			Assert::AreEqual(str, "1.01:01:01"s);
		}

		TEST_METHOD(FormatSecondsShort_ThousandDays_ReturnsExpected)
		{
			string str = FormatSecondsShort(SECONDS_PER_DAY * 1000);
			Assert::AreEqual(str, "1000.00:00:00"s);
		}

		TEST_METHOD(FormatSecondsShort_ZeroSeconds_ReturnsExpected)
		{
			string str = FormatSecondsShort(0);
			Assert::AreEqual(str, "00:00:00"s);
		}
		//FormatSecondsShort Tests End

		//FormatSecondsLong Tests Start
		TEST_METHOD(FormatSecondsLong_Second_ReturnsExpected)
		{
			string str = FormatSecondsLong(SECONDS_PER_SECOND);
			Assert::IsTrue(str.find("1 second") != string::npos);
		}

		TEST_METHOD(FormatSecondsLong_Minute_ReturnsExpected)
		{
			string str = FormatSecondsLong(SECONDS_PER_MINUTE);
			Assert::IsTrue(str.find("1 minute") != string::npos);
			Assert::IsTrue(str.find("second") == string::npos);
		}

		TEST_METHOD(FormatSecondsLong_Hour_ReturnsExpected)
		{
			string str = FormatSecondsLong(SECONDS_PER_HOUR);
			Assert::IsTrue(str.find("1 hour") != string::npos);
			Assert::IsTrue(str.find("minute") == string::npos);
			Assert::IsTrue(str.find("second") == string::npos);
		}

		TEST_METHOD(FormatSecondsLong_Day_ReturnsExpected)
		{
			string str = FormatSecondsLong(SECONDS_PER_DAY);
			Assert::IsTrue(str.find("1 day") != string::npos);
			Assert::IsTrue(str.find("hour") == string::npos);
			Assert::IsTrue(str.find("minute") == string::npos);
			Assert::IsTrue(str.find("second") == string::npos);
		}

		TEST_METHOD(FormatSecondsLong_DayHourMinuteAndSecond_ReturnsExpected)
		{
			string str = FormatSecondsLong(SECONDS_PER_DAY + SECONDS_PER_HOUR + SECONDS_PER_MINUTE + SECONDS_PER_SECOND);
			Assert::IsTrue(str.find("1 day") != string::npos);
			Assert::IsTrue(str.find("1 hour") != string::npos);
			Assert::IsTrue(str.find("1 minute") != string::npos);
			Assert::IsTrue(str.find("1 second") != string::npos);
		}

		TEST_METHOD(FormatSecondsLong_DaysHoursMinutesAndSeconds_ReturnsExpected)
		{
			string str = FormatSecondsLong(2 * SECONDS_PER_DAY + 2 * SECONDS_PER_HOUR + 2 * SECONDS_PER_MINUTE + 2 * SECONDS_PER_SECOND);
			Assert::IsTrue(str.find("2 days") != string::npos);
			Assert::IsTrue(str.find("2 hours") != string::npos);
			Assert::IsTrue(str.find("2 minutes") != string::npos);
			Assert::IsTrue(str.find("2 seconds") != string::npos);
		}

		TEST_METHOD(FormatSecondsLong_ZeroSeconds_ReturnsExpected)
		{
			string str = FormatSecondsLong(0);
			Assert::AreEqual(str, "0 seconds"s);
		}
		//FormatSecondsLong Tests End
	};
}