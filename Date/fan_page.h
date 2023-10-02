#ifndef _FAN_PAGE_H
#define _FAN_PAGE_H

#include <string>
#include <vector>
#include <list>
#include "date.h"
#include "clock.h"
//#include "status.h"
//#include "member.h"

#pragma warning (disable: 4996)

class Member;
class Status;

class FanPageExceptions : public std::exception
{
private:
	std::string msg;

public:
	FanPageExceptions(const std::string& fanName, std::string& pageName, const std::string& situation)
	{
		msg = fanName + " is " + situation + " fan of the page " + pageName;
	}

	char const* what() const
	{
		return msg.c_str();
	}
};

class FanPage
{
private:
	std::string name;
	std::vector<Member*> fans;
	std::list<Status> statusBoard;

public:
	FanPage(std::string n);
	FanPage(const FanPage& n);
	~FanPage();

	const std::string& getName() const;
	std::vector<Member*> getFans() const;
	std::list<Status> getStatusBoard() const;

	//fans
	void deleteFans(Member& fanToDelete) noexcept(false); //delete fans and decrease the num of fans
	int searchFan(Member& fanToFind);
	void printAllFans();


	//status
	void addStatus(Status newStatus);
	void printAllStatuses();

	//operators
	bool operator>(const FanPage& other) const;
	bool operator>(const Member& other) const;

	FanPage& operator+=(Member& fan) noexcept(false);
};





#endif // !_FAN_PAGE_H
