#include <iostream>
#include <string.h>
using namespace std;

#include "fan_page.h"
#include "funcs.h"
#include "member.h"
#include "status.h"

//c'tor
FanPage::FanPage(string n)
{
	name = n;
}

FanPage::FanPage(const FanPage& n) : statusBoard(n.statusBoard)
{
	this->name = n.name;
	this->fans = n.fans;
}
//d'tor
FanPage::~FanPage()
{
	
}

//gettim
const string& FanPage::getName() const
{
	return name;
}
vector<Member*> FanPage::getFans() const
{
	return fans;
}
list<Status> FanPage::getStatusBoard() const
{
	return statusBoard;
}

//fans
int FanPage::searchFan(Member& fanToFind)
{
	return searchUser(fans, fanToFind);
}
void FanPage::deleteFans(Member& fanToDelete)
{
	int index = searchFan(fanToDelete);
	if (index == FALSE)
	{
		throw FanPageExceptions(fanToDelete.getName(), name, " not ");
	}
	else
	{
		vector<Member*>::iterator itr = fans.begin() + index;
		fans.erase(itr);
	}

}
void FanPage::printAllFans()
{
	cout << "the fans of " << name << " are: " << endl;

	vector<Member*>::iterator itr = fans.begin();
	vector<Member*>::iterator itrEnd = fans.end();

	for (; itr != itrEnd; ++itr)
	{
		cout << (*itr)->getName() << endl;
	}
}

//status
void FanPage::addStatus(Status newStatus)
{
	statusBoard.push_back(newStatus);
}
void FanPage::printAllStatuses()
{
	cout << "The status of the this page are:" << endl;

	list<Status>::iterator itr = statusBoard.begin();
	list<Status>::iterator itrEnd = statusBoard.end();

	while (itr != itrEnd)
	{
		itr->printStatus();
		++itr;
	}
}


//operators

bool FanPage::operator>(const FanPage& other) const
{
	return(this->fans.size() > other.fans.size());
}

bool FanPage::operator>(const Member& other) const
{
	return (this->fans.size() > other.getTheFriends().size());
}

FanPage& FanPage::operator+=(Member& fan)
{
	int index = searchFan(fan);
	if (index == FALSE)
	{
		fans.push_back(&fan);
	}
	else
	{
		throw FanPageExceptions(fan.getName(), name, " already ");
	}
	return *this;
}

