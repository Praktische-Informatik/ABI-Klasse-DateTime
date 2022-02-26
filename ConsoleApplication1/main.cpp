#include <iostream>
#include <windows.h>
#include "DateTime.h"

using namespace std;

int main()
{
    DateTime dt1;
	cout << dt1.getYear() << "." << dt1.getMonth() << "." << dt1.getDay() << " " << dt1.getHour() << ":" << dt1.getMin() << ":" << dt1.getSec() << " " << dt1.inMillis() << endl;
	cout << "toString: " << dt1.toString() << endl;
	cout << "toStringDate: " << dt1.toStringDate() << endl;
	cout << "toStringTime: " << dt1.toStringTime() << endl;

	//Sleep(1500);

	DateTime dt2;
	cout << dt2.getYear() << "." << dt2.getMonth() << "." << dt2.getDay() << " " << dt2.getHour() << ":" << dt2.getMin() << ":" << dt2.getSec() << " " << dt2.inMillis() << endl;

	cout << dt2.millisUntil(dt1) << endl; 

	DateTime dt3("21.10.2022", "12.24.40");
	cout << dt3.getYear() << "." << dt3.getMonth() << "." << dt3.getDay() << " " << dt3.getHour() << ":" << dt3.getMin() << ":" << dt3.getSec() << " " << dt3.inMillis() << endl;


	cout << dt3.millisUntil(dt1) << endl;
	cout << "toString: " << dt3.toString() << endl;
	cout << "toStringDate: " << dt3.toStringDate() << endl;
	cout << "toStringTime: " << dt3.toStringTime() << endl;

	DateTime dt4("21.10.2022", "13.24.40");
	cout <<"Differenz: " << dt4.millisUntil(dt3) << endl;


        return 0;
}
