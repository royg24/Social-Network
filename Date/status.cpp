#include "status.h"
#include <iostream>
#include "funcs.h"
using namespace std;

#pragma warning (disable: 4996)


Status::Status(const Date& date, const Clock& time,const string& newText) : publishDate(date), publishTime(time)
{
	text = newText;
}

Status::Status(const Status& st) : publishDate(st.publishDate), publishTime(st.publishTime)
{
	text = st.text;
}

Status::~Status() {  }


const string& Status::getText() const
{
	return text;
}

const Date& Status::getDate() const
{
	return publishDate;
}

const Clock& Status::getTime() const
{
	return publishTime;
}

void Status::printStatus() const
{
	cout << "Date: ";
	publishDate.showDate();
	cout << " Time: ";
	publishTime.show();
	cout << endl;
	cout << text << endl;
}

bool Status::operator==(const Status& other) const
{
	return (other.text == this->text);
}

bool Status::operator!=(const Status& other) const
{
	return(other.text != this->text);
}
