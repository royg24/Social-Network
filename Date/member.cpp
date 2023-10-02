#include <iostream>
using namespace std;

#include "fan_page.h"
#include "member.h"


//c'tor reser the arrays
Member::Member(const string& n, const Date& date) : birthdate(date)
{
	name = n;
}

Member::Member(const Member& n) : birthdate(n.birthdate) , statusBoard(n.statusBoard)
{
	this->name = n.name;
	this->friends = n.friends;
	this->pages = n.pages;
}


//d'tor
Member::~Member() { }


//gettim
const string& Member::getName()const
{
	return name;
}
const Date& Member::getDate()const
{
	return birthdate;
}

vector<FanPage*> Member::getThePages() const
{
	return pages;
}
list<Status> Member::getStatusBoard() const
{
	return statusBoard;
}
vector<Member*> Member::getTheFriends() const
{
	return friends;
}


//friend
void Member::deleteFriend(Member& friendToDelete)
{
	int index = searchFriend(friendToDelete);
	if (name == friendToDelete.getName())
	{
		throw MemberException((string) "Error! A user can't remove himself!");
	}
	if (index == FALSE)
	{
		throw MemberException(name, friendToDelete.name, "not");
	}
	else
	{
		vector<Member*>::iterator itr = friends.begin() + index;
		friends.erase(itr);
	}
}
int Member::searchFriend(const Member& friendToFind)
{
	return searchUser(friends, friendToFind);
}
void Member::printAllFriends()
{
	cout << "The friends of " << name << " are:" << endl;

	vector<Member*>::iterator itr = friends.begin();
	vector<Member*>::iterator itrEnd = friends.end();

	for (; itr != itrEnd; ++itr)
	{
		cout << (*itr)->name << endl;
	}
}

//status
void Member::addStatus(Status& newStatus)
{
	statusBoard.push_back(newStatus);
}
void Member::printAllStatus()
{
	list<Status>::iterator itr = statusBoard.begin();
	list<Status>::iterator itrEnd = statusBoard.end();

	while (itr != itrEnd)
	{
		itr->printStatus();
		++itr;
	}
}
void Member::print10LastEachFriendsStatus()
{
	cout << "The last 10 statuses of each friend of " << name << " are: " << endl;

	vector<Member*>::iterator itr = friends.begin();
	vector<Member*>::iterator itrEnd = friends.end();

	for (; itr != itrEnd; ++itr)
	{
		cout << (*itr)->getName() << ":" << endl;
		if ((*itr)->getStatusBoard().size() <= 10)
		{
			(*itr)->printAllStatus();
		}
		else
		{
			(*itr)->print10LastStatus();
		}
	}

}
void Member::print10LastStatus()
{

	list<Status>::iterator itr = statusBoard.begin();
	advance(itr, (statusBoard.size() - TEN));
	list<Status>::iterator itrEnd = statusBoard.end();

	for (; itr != itrEnd; ++itr)
	{
		itr->printStatus();
	}
}

//fan page
void Member::addFanPageToFriend(FanPage& newPage)
{
	int index = searchPage(newPage);
	if (index == FALSE)
	{
		//add
		pages.push_back(&newPage);
	}
	else
	{
		//can't add
		throw MemberException(name, newPage, "already");
	}
}
void Member::deleteFanPage(FanPage& pageToDelete)
{
	int index = searchPage(pageToDelete);
	if (index == FALSE)
	{
		throw MemberException(name, pageToDelete, "not");
	}
	else
	{
		vector<FanPage*>::iterator itr = pages.begin() + index;
		pages.erase(itr);
	}
}
int Member::searchPage(FanPage& pageToFind)
{
	return searchFanPages(pages, pageToFind);
}
void Member::printPages()
{
	cout << "The pages that " << name << " is fan of are: " << endl;
	vector<FanPage*>::iterator itr = pages.begin();
	vector<FanPage*>::iterator itrEnd = pages.end();

	for (; itr != itrEnd; ++itr)
	{
		cout << (*itr)->getName() << " ";
	}

}

//operators
bool Member::operator>(const Member& other) const
{
	return(this->friends.size() > other.friends.size());
}

bool Member::operator>(const FanPage& other) const
{
	return (this->friends.size() > other.getFans().size());
}

Member& Member::operator+=(Member& newfriend)
{
	int index = searchFriend(newfriend);
	if (index == FALSE)
	{
		//add
		friends.push_back(&newfriend);
	}
	else if (name == newfriend.name)
	{
		throw MemberException("Error! A user can't be a friend of himself!");
	}
	else
	{
		//can't add
		throw MemberException(name, newfriend.name, "already");
	}
	return *this;
}
