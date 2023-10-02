#ifndef _DATE_H
#define _DATE_H
#include <string>

enum eMonth { _ZERO, JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
const int _ONE = 1, _FOUR = 4, TWENTY_NINE = 29, THIRTY = 30, THIRTY_ONE = 31, DATE_FORMAT = 10;
const std::string SINGLE_DIGIT_DATE = "0", DOUBLE_DIGIT_DATE = "", DATE_SEPERATOR = "\\";
const int MIN_YEAR = 1900, MAX_YEAR = 2100;

class DateExceptions : public std::exception
{
private:
	std::string msg;
public:
	DateExceptions(const std::string& errorTxt)
	{
		msg = errorTxt;
	}

	char const* what() const
	{
		return msg.c_str();
	}
};

class Date
{
private:
	int day, month, year;

public:
	Date(int d, int m, int y); // c'tor checks if the date is valid, if isn't valid = false
	~Date();

public:
	void setDay(int d, int m, int y) noexcept(false); 
	void setMonth(int m) noexcept(false);
	void setYear(int y) noexcept(false);

	int getDay() const; 
	int getMonth() const; 
	int getYear() const; 

	void showDate() const; 
};


#endif // !_DATE_H

