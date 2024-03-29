#pragma warning(disable:4996)

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include "DateTime.h"

using namespace std;


DateTime::DateTime()
{
	// Systemzeit ermitteln
	std::chrono::system_clock::time_point timeNow = std::chrono::system_clock::now();
	aktuell = std::chrono::system_clock::to_time_t(timeNow);

	struct tm tstruct;
	tstruct = *localtime(&aktuell);  // use locale time

	sec = tstruct.tm_sec;
	min = tstruct.tm_min;
	hour = tstruct.tm_hour;

	day = tstruct.tm_mday;
	month = tstruct.tm_mon + 1;
	year = tstruct.tm_year + 1900;


	// Millisekunden ermitteln
	auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(timeNow);
	auto value = now_ms.time_since_epoch();
	ms = value.count();

	time = this->toStringTime();
	date = this->toStringDate();
}

/// <summary>
/// DateTime aus zwei strings
/// </summary>
/// <param name="date">: Datum, Format: tt.mm.yyyy</param>
/// <param name="time">: Uhrzeit, Format: hh.mm.ss</param>
DateTime::DateTime(string date, string time)
{
	// Datum
	int tag1 = 0, monat1 = 0, jahr1 = 0, i = 0;
	string teilstring;
	string::size_type ende;

	while (string::npos != (ende = date.find("."))) {
		teilstring = date.substr(0, ende);
		switch (i)
		{
		case 0:
			tag1 = stoi(teilstring);
			break;
		case 1:
			monat1 = stoi(teilstring);
			break;
		}
		i++;
		date.erase(0, ende + 1);
	}
	jahr1 = stoi(date);

	if (jahr1 < 0 || monat1 < 1 || monat1 > 12 || tag1 < 1 || monat1 < 8 && monat1 % 2 == 0 && tag1 > 30 || monat1 < 8 && monat1 % 2 == 1 && tag1 > 31 || monat1 > 8 && monat1 % 2 == 0 && tag1 > 31 || monat1 > 8 && monat1 % 2 == 1 && tag1 > 30) cout << "Ung�ltiges Datum" << endl;
	else
	{
		day = tag1;
		month = monat1;
		year = jahr1;
	}

	// Time
	int sec1 = 0, min1 = 0, std1 = 0;
	i = 0;
	string ts;
	string::size_type e;

	while (string::npos != (e = time.find("."))) {
		ts = time.substr(0, e);
		switch (i)
		{
		case 0:
			std1 = stoi(ts);
			break;
		case 1:
			min1 = stoi(ts);
			break;
		}
		i++;
		time.erase(0, e + 1);
	}
	sec1 = stoi(time);

		sec = sec1;
		min = min1;
		hour = std1;

		// Systemzeit ermitteln
		std::chrono::system_clock::time_point timeNow = std::chrono::system_clock::now();
		time = std::chrono::system_clock::to_time_t(timeNow);

		// Millisekunden ermitteln
		auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(timeNow);
		auto value = now_ms.time_since_epoch();
		ms = value.count();

}

long long DateTime::millisUntil(DateTime other)
{
	long dis = this->getDateTime() - other.getDateTime();
	return dis;
}

long long DateTime::inMillis()
{
	return ms;
}


string DateTime::toString()
{
	return to_string(day) +"." + to_string(month) + "." + to_string(year) + " " + to_string(hour) + ":" + to_string(min) + ":" + to_string(sec);
}

string DateTime::toStringDate()
{
	return to_string(day) + "." + to_string(month) + "." + to_string(year);
}

string DateTime::toStringTime()
{
	return to_string(hour) + ":" + to_string(min) + ":" + to_string(sec);
}

int DateTime::getYear()
{
	return year;
}

int DateTime::getMonth()
{
	return month;
}

int DateTime::getDay()
{
	return day;
}

int DateTime::getHour()
{
	return hour;
}

int DateTime::getMin()
{
	return min;
}

int DateTime::getSec()
{
	return sec;
}

time_t DateTime::getDateTime()
{
	return aktuell;
}

int DateTime::compareTo(DateTime* dt)
{
	if (this->getYear() < dt->getYear()) { //liegt DateTime Objekt vor dem Parameter, dann wird -1 zur�ckgegeben
		return -1;
	}
	if (this->getMonth() < dt->getMonth()) {
		return -1;
	}
	if (this->getDay() < dt->getDay()) {
		return -1;
	}
	if (this->getHour() < dt->getHour()) {
		return -1;
	}
	if (this->getMin() < dt->getMin()) {
		return -1;
	}
	if (this->getSec() < dt->getSec()) {
		return -1;
	}

	if (this->getYear() == dt->getYear()) { //DateTime Objekt ist gleich dem Parameter

		if (this->getMonth() == dt->getMonth()) {


			if (this->getDay() == dt->getDay()) {


				if (this->getHour() == dt->getHour()) {

					if (this->getMin() == dt->getMin()) {

						if (this->getSec() == dt->getSec()) {
							return 0;
						}
					}
				}
			}
		}
	}

	if (this->getYear() > dt->getYear()) { //liegt DateTime Objekt nach dem Parameter, dann wird 1 zur�ckgegeben
		return 1;
	}
	if (this->getMonth() > dt->getMonth()) {
		return 1;
	}
	if (this->getDay() > dt->getDay()) {
		return 1;
	}
	if (this->getHour() > dt->getHour()) {
		return 1;
	}
	if (this->getMin() > dt->getMin()) {
		return 1;
	}
	if (this->getSec() > dt->getSec()) {
		return 1;
	}

	return 2;//Fehler
}

