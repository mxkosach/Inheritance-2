#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

class Seasons :public tm {
	string season;
	void setSeason();
public:
	Seasons();
	Seasons(int day, int month, int year);
	
	void setDay(int day) {
		if (day < 1 || day>31) {
			cout << "Incorrect day!\n";
			return;
		}
		this->tm_mday = day;
	}
	void setMonth(int month) {
		if (month < 1 || month>12) {
			cout << "Incorrect month!\n";
			return;
		}
		this->tm_mon = month;
		setSeason();
	}
	void setYear(int year) {
		if (year < 1980 || year>2050) {
			cout << "Incorrect year! Year must be from 1980 to 2050.\n";
			return;
		}
		this->tm_year = year;
	}

	int getDay() {
		return tm_mday;
	}
	int getMonth() {
		return tm_mon;
	}
	int getYear() {
		return tm_year;
	}
	string getSeason() {
		return season;
	}

	void show() {
		cout <<((tm_mday < 10) ? "0" : "") << this->tm_mday << '.' << ((tm_mon < 10) ? "0" : "") << tm_mon << '.' << this->tm_year << " - " << this->season << endl;
	}
};

int main()
{
		srand(time(0));
		Seasons a[10];
		for (int i = 0; i < 10; i++)
			a[i].show();
	return 0;
}

Seasons::Seasons(){
	this->tm_mday = rand() % 27 + 1;
	this->tm_mon = rand() % 12 + 1;
	this->tm_year = 2000 + rand() % 22;
	setSeason();
}

Seasons::Seasons(int day, int month, int year)
{
	this->tm_mday = day;
	this->tm_mon = month;
	this->tm_year = year;
	setSeason();
}

void Seasons::setSeason()
{
	switch (this->tm_mon)
	{
	case 12:
	case 1:
	case 2:
		this->season = "winter";
		break;
	case 3:
	case 4:
	case 5:
		this->season = "spring";
		break;
	case 6:
	case 7:
	case 8:
		this->season = "summer";
		break;
	case 9:
	case 10:
	case 11:
		this->season = "autumn";
		break;
	default:
		break;
	}
}
