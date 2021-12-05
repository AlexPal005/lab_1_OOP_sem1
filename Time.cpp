#include "Time.h"


Date Date:: operator + (const Date& Time)
{
    int k = 0;
    int km = 0;
    int ks = 0;
    Date tmp;
    if (seconds + Time.seconds >= 60)
    {
        tmp.minutes = tmp.minutes + 1;
        tmp.seconds = (seconds + Time.seconds) - 60;
        if (tmp.minutes == 60)
        {
            tmp.minutes = 0;
            tmp.hour = tmp.hour + 1;
        }
        ks++;
    }
    if (ks == 0)
        tmp.seconds = seconds + Time.seconds;
    if (minutes + Time.minutes >= 60)
    {
        tmp.hour = tmp.hour + 1;
        tmp.minutes = (minutes + Time.minutes) - 60;
        km++;
    }
    if (km == 0)
        tmp.minutes = minutes + Time.minutes;
    if (hour + Time.hour >= 24)
    {
        tmp.hour = (hour + Time.hour) - 24;
        k++;
    }
    if (k == 0)
        tmp.hour = hour + Time.hour;

    return tmp;
}
Date Date::operator - (const Date& Time)
{
    int k = 0;
    int km = 0;
    int ks = 0;
    Date tmp;
    if (seconds - Time.seconds < 0)
    {
        tmp.minutes = tmp.minutes - 1;
        tmp.seconds = 60 + (seconds - Time.seconds);
        ks++;
    }
    if (ks == 0)
        tmp.seconds = seconds - Time.seconds;

    if (minutes - Time.minutes < 0)
    {
        tmp.hour = tmp.hour - 1;
        tmp.minutes = 60 + (minutes - Time.minutes);
        km++;
    }
    if (km == 0)
        tmp.minutes = minutes - Time.minutes;

    if (this->hour - Time.hour < 0)
    {
        tmp.hour = 24 + (hour - Time.hour);
        k++;
    }
    if (k == 0)
        tmp.hour = hour - Time.hour;

    return tmp;
}
Date& Date::operator = (const Date& Time)
{
    hour = Time.hour;
    minutes = Time.minutes;
    seconds = Time.seconds;

    return *this;
}
bool Date::operator == (const Date& Time)
{
    return hour == Time.hour && minutes == Time.minutes && seconds == Time.seconds;
}
bool Date::operator != (const Date& Time)
{
    return !(*this == Time);
}
bool Date::operator > (const Date& Time)
{
    if (hour > Time.hour)
        return true;
    else if (hour == Time.hour && minutes > Time.minutes)
        return true;
    else if (hour == Time.hour && minutes == Time.minutes && seconds > Time.seconds)
        return true;
    else
        return false;
}
bool Date::operator < (const Date& Time)
{
    return !(*this > Time);
}
void Date::timeday()
{
    if (hour < 6 || hour == 6 && minutes == 0)
        std::cout << "Night" << std::endl;
    else if (hour < 12 || hour == 12 && minutes == 0)
        std::cout << "Morning" << std::endl;
    else if (hour < 18 || hour == 18 && minutes == 0)
        std::cout << "Daytime" << std::endl;
    else if (hour < 24 || hour == 24 && minutes == 0)
        std::cout << "Evening" << std::endl;
}
void Date::setH()
{
    std::cout << "Enter hours: " << std::endl;
    std::cin >> hour;
}
void Date::setM()
{
    std::cout << "Enter minutes: " << std::endl;
    std::cin >> minutes;
}
void Date::setS()
{
    std::cout << "Enter seconds: " << std::endl;
    std::cin >> seconds;
}
void Date::getH() const
{
    std::cout << "Hours: " << hour << std::endl;
}
void Date::getM() const
{
    std::cout << "Minutes: " << minutes << std::endl;
}
void Date::getS() const
{
    std::cout << "Seconds: " << seconds << std::endl;
}