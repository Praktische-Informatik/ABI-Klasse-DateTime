#pragma once
#pragma warning(disable:4996) // Compilerwarnung für ctime _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

using namespace std;

class DateTime
{
private:
    time_t aktuell;
    string date;
    int day, month, year;

    string time;
    int hour, min, sec;
    long long ms; // ms Millisekunden
    
public:
    DateTime();
    DateTime(string date, string time);
    long long millisUntil(DateTime other); // 
	long long inMillis(); // liefert die vergangen Milisekunden relativ zum 01.01.1970.
    string toString(); // liefert eine String-Repräsentanz des date-Objekts im Format "dd.mm.yyyy hh:mm:ss"
    string toStringDate();
    string toStringTime();

    int getYear();
    int getMonth();
    int getDay();

    int getHour();
    int getMin();
    int getSec();

    time_t getDateTime();
    int compareTo(DateTime* dt);  // Danke an Simon Schneider ABI 2022! Wer Hilft die Methode zu kommentieren und in der main zu testen?

};

