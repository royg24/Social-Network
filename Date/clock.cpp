#include <iostream>
using namespace std;

#include"clock.h"

int Clock::getMinutes() const
{
	return minutes;
}

int Clock::getHours() const
{
	return hours;
}

void Clock::setMinutes(int m)
{
	if (m < MIN || m > MAX_MINUTE)
	{
		throw ClockExceptions("Invalid minutes, the minutes unchanged");
	}
	else
	{
		minutes = m;
	}
}

void Clock::setHours(int h)
{
	if (h < MIN || h > MAX_HOUR)
	{
		throw ClockExceptions("Invalid hour, the hour unchanged");
	}
	else
	{
		hours = h;
	}
}

void Clock::show() const
{
	cout << (hours < CLOCK_FORMAT ? SINGLE_DIGIT_CLOCK : DOUBLE_DIGIT_CLOCK)
		<< hours << CLOCK_SEPERATOR
		<< (minutes < CLOCK_FORMAT ? SINGLE_DIGIT_CLOCK : DOUBLE_DIGIT_CLOCK)
		<< minutes << SPACE;
}

Clock::Clock(int h, int m) 
{
	setHours(h);
	setMinutes(m);
	
}


