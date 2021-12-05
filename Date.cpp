#include "Date.h"

std::ostream& operator << (std::ostream& out, const Date& other)
{
    out << other.day << "." << other.month << "." << other.year;
    return out;
}


const std::string DW[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

std::string Date::whatday()
{
    int m = month;
    int y = year;
    int d = day;
    m = (m + 9) % 12;
    y -= m / 10;
    int dn = 365 * y + y / 4 - y / 100 + y / 400 + (m * 306 + 5) / 10 + (d - 1);

    std::cout<<DW[dn % 7]<<std::endl;
    return DW[dn % 7];
}

void Date::getDate() const
{
    std::cout << day << "." << month << "." << year;
}

const int Max[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int getdays(int m1, int m2)
{
    int days = 0;
    for (int i = 0; i < m1; i++)
        days = days + Max[i];
    for (int i = 0; i < m2; i++)
        days = days + Max[i];

    return days;
}


bool isleap(int year)
{
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        return true;
    else 
        return false;
}


Date Date::operator + (const Date& date)
{
    Date tmp;
    tmp.year = year + date.year;
    int days = getdays(month, date.month);
    days = days + day + date.day;
    if (isleap(year) == true)
        days++;
    if (isleap(date.year) == true)
        days++;
    if (days > 365)
    {
        days = days - 365;
        tmp.year++;
    }
    int c = 0;
    for (int i = 0; i < 12; i++)
    {
        if (days - Max[i] > 0)
        {
            days = days - Max[i];
            c++;
        }
        else
            break;
    }
    tmp.month = c;
    tmp.day = days;

    return tmp;
}

int getdays1(int m1, int m2)
{
    int days = 0;
    int days1 = 0;
    for (int i = 0; i < m1; i++)
        days = days + Max[i];
    for (int i = 0; i < m2; i++)
        days1 = days1 + Max[i];

    return days - days1;
}

Date Date::operator - (const Date& date)
{
    Date tmp;
    tmp.year = year - date.year;
    int days = getdays1(month, date.month);
    if (isleap(year) == true)
        days + 1;
    if (isleap(date.year) == true)
        days - 1;
    if (days > 0)
    {
        int c = 0;
        for (int i = 0; i < 12; i++)
        {
            if (days - Max[i] > 0)
            {
                days = days - Max[i];
                c++;
            }
            else
                break;
        }
        if (c == 0)
        {
            tmp.month = 1;
            tmp.day = days;
        }
        else
        {
            tmp.month = c;
            tmp.day = days;
        }
    }
    else if (days == 0)
    {
        tmp.day = 1;
        tmp.month = 1;
    }
    else if (days < 0)
    {
        tmp.year--;
        int c = 0;
        days = days * -1;
        for (int i = 11; i >= 0; i--)
        {
            if (days - Max[i] > 0)
            {
                days = days - Max[i];
                c++;
            }
            else
                break;
        }
        tmp.month = 12 - c;
        tmp.day = days;
    }


    return tmp;
}

Date& Date::operator = (const Date& date)
{
    day = date.day;
    month = date.month;
    year = date.year;
    Time = date.Time;

    return *this;
}

bool Date::operator == (const Date& date)
{
    return year == date.year && month == date.month && day == date.day && Time == date.Time;
}

bool Date::operator != (const Date& date)
{
    return !(*this == date);
}

bool Date::operator > (const Date& date)
{
    if (year > date.year)
        return true;
    else if (year == date.year && month > date.month)
        return true;
    else if (year == date.year && month == date.month && day > date.day)
        return true;
    else
        return false;
}

bool Date::operator < (const Date& date)
{
    return !(*this > date);
}