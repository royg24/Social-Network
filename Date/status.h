#ifndef _STATUS_H
#define _STATUS_H
#include <string>

#include "date.h"
#include "clock.h"


class Status
{
private:
	std::string text;
	const Date publishDate;
	const Clock publishTime;

public:
	Status(const Date& date, const Clock& time, const std::string& newText);
	Status(const Status& st);
	~Status();

	const std::string& getText() const;
	const Date& getDate() const;
	const Clock& getTime() const;

	void printStatus() const;

	bool operator==(const Status& other) const;
	bool operator!=(const Status& other) const;


};

#endif // !_STATUS_H