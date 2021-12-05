#pragma once
#include "Time.h"

class Date
{
private:
	int day;
	int month;
	int year;
	Date Time;
public:
	Date() : day(0), month(0), year(0), Time(0, 0, 0) {};
	Date(int y, int m, int d) : day(d), month(m), year(y) {};
	Date(int y, int m, int d, int h, int min, int s) : day(d), month(m), year(y),
                                                       Time(h, min, s) {};
	Date(const Date& date) : day(date.day), month(date.month), year(date.year),
                             Time(date.Time) {};
	std::string whatday();
	void getDate() const;
	Date operator + (const Date& date);
	Date operator - (const Date& date);
	Date& operator = (const Date& date);
	bool operator == (const Date& date);
	bool operator != (const Date& date);
	bool operator > (const Date& date);
	bool operator < (const Date& date);
	friend std::ostream& operator << (std::ostream& out, const Date& other);
	~Date() {};
};
