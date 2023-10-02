#ifndef _CLOCK_H
#define _CLOCK_H

const int MIN = 0, MAX_MINUTE = 59, MAX_HOUR = 24, CLOCK_FORMAT = 10;
const std::string SINGLE_DIGIT_CLOCK = "0", DOUBLE_DIGIT_CLOCK = "",CLOCK_SEPERATOR = ":", SPACE = " ";

class ClockExceptions : public std::exception
{
private:
	std::string msg;

public:
	ClockExceptions(const std::string& errorTxt)
	{
		msg = errorTxt;
	}
	char const* what() const
	{
		return msg.c_str();
	}
};



class Clock
{
private:
	int hours, minutes;

public:
	Clock(int h, int m);

public:
	int getMinutes() const; 
	int getHours() const;

	void setMinutes(int m) noexcept (false);
	void setHours(int h) noexcept (false);

	void show() const; //change to const
};



#endif // !_CLOCK_H
