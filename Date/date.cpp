#include <iostream>
using namespace std;
#include "date.h"

Date::Date(int d, int m, int y)
{
	setMonth(m);
	setYear(y);
	setDay(d,m,y);
}

Date::~Date(){}

void Date::setDay(int d, int m, int y)
{
	if (d < _ONE || d>THIRTY_ONE)
	{
		throw DateExceptions("Day have to be between 1-31");
	}
	else if (d == THIRTY && m == FEB)
	{
		throw DateExceptions("February doesn't have the day 30");
	
	}
	else if (d == THIRTY_ONE && (m == FEB || m == APR || m == JUN || m == SEP || m == NOV))
	{
		throw DateExceptions("This month doesn't have the day 31");
	}
	else if (d == TWENTY_NINE && m == FEB && y % _FOUR != _ZERO)
	{
		throw DateExceptions("This year isn't a leap year");
	}
	else
	{
		day = d;
	}
}

void Date::setMonth(int m)
{
	if (m < JAN || m>DEC)
	{
		throw DateExceptions("Month have to be between 1-12");
	}
	else
	{
		month = m;
	}
}

void Date::setYear(int y)
{
	if (y < MIN_YEAR || y> MAX_YEAR)
	{
		throw DateExceptions("Year have to be between 1900-2100.");
	}
	else
	{
		year = y;
	}
}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

void Date::showDate() const
{
	cout << (day < DATE_FORMAT ? SINGLE_DIGIT_DATE : DOUBLE_DIGIT_DATE)
		<< day << DATE_SEPERATOR
		<< (month < DATE_FORMAT ? SINGLE_DIGIT_DATE : DOUBLE_DIGIT_DATE)
		<< month << DATE_SEPERATOR
		<< year;
}


