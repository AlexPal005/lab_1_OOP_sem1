#pragma once
#include <iostream>

class Date
{
public:
    Date() : hour(0), minutes(0), seconds(0) {};
    Date(int h, int m, int s) : hour(h), minutes(m), seconds(s) {};
    Date(const Date& Time) : hour(Time.hour), minutes(Time.minutes), seconds(Time.seconds) {};
    ~Date() {};
    Date operator + (const Date& Time);
    Date operator - (const Date& Time);
    Date& operator = (const Date& Time);
    bool operator == (const Date& Time);
    bool operator != (const Date& Time);
    bool operator > (const Date& Time);
    bool operator < (const Date& Time);
    friend std::ostream& operator << (std::ostream& out, const Date& other);
    void timeday();
    void setH();
    void setM();
    void setS();
    void getH() const;
    void getM() const;
    void getS() const;
private:
    int hour;
    int minutes;
    int seconds;
};