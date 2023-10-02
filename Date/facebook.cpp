#include <iostream>
using namespace std;

#include "facebook.h"
#include "fan_page.h"
#include "member.h"
#include "status.h"


//d'tor 
Facebook::~Facebook(){}

//gettim
list<Member>& Facebook::getUser()
{
	return users;
}
list<FanPage>& Facebook::getPages()
{
	return pages;
}

//user
Member* Facebook::createUser()
{
	string name;
	int day, month, year;
	cout << "Enter your name: " << endl;
	cin.ignore();
	getline(cin, name);
	cout << "Enter your birthday: " << endl;
	cin >> day >> month >> year;
	Date d(day, month, year);
	Member* newUser = new Member(name, d);
	return newUser;
}
void Facebook::addNewUser(const Member& newUser)
{
	int exsist = checkIfNameExsists(newUser);
	if (exsist == FALSE)
	{
		users.push_back(newUser);
	}
	else
	{
		throw FacebookExceptions(newUser.getName(), " User ");
	}

}
int Facebook::checkIfNameExsists(const Member& userToFind)
{
	return searcheUserInList(userToFind);
}
int Facebook::searcheUserInList(const Member& userToFind)
{
	list<Member>::iterator itr = users.begin();
	list<Member>::iterator itrEnd = users.end();
	int index = ZERO;
	for (; itr != itrEnd; ++itr)
	{
		if (itr->getName() == userToFind.getName())
		{
			return index;
		}
		index++;
	}
	return FALSE;
}
void Facebook::connectUsers(Member& user1, Member& user2)
{
	user1 += user2;
	user2 += user1;
}
void Facebook::unConnectUsers(Member& user1, Member& user2)
{
	user1.deleteFriend(user2);
	user2.deleteFriend(user1);
}
void Facebook::showAllUsers()
{
	cout << "The users in facebook are: " << endl << endl;
	int counter = ZERO;
	list<Member>::iterator itr = users.begin();
	list<Member>::iterator itrEnd = users.end();
	for (; itr != itrEnd; ++itr)
	{
		counter++;
		cout << counter << "." << itr->getName() << endl;
	}
}
int Facebook::chooseUser()
{
	int user;
	cout << "Choose a user (his number)" << endl << endl;
	showAllUsers();
	cin >> user;
	if (user > users.size() || user < ONE)
	{
		throw FacebookExceptions(user);
	}
	return user;
}

//fan page
FanPage* Facebook::createFanPage()
{
	string name;
	cout << "Enter the page's name: " << endl;
	cin.ignore();
	getline(cin, name);
	FanPage* newPage = new FanPage(name);
	return newPage;
}
void Facebook::addNewFanPage(FanPage& newPage)
{
	int exsist = checkIfFanExists(newPage);
	if (exsist == FALSE)
	{
		pages.push_back(newPage);
	}
	else
	{
		throw FacebookExceptions(newPage.getName(), " Fan page ");
	}
}
void Facebook::addFanToPage(FanPage& page, Member& newFan)
{
	page += newFan;
	newFan.addFanPageToFriend(page);
}
void Facebook::removeFanFromPage(FanPage& page, Member& fanToRemove)
{
	page.deleteFans(fanToRemove);
	fanToRemove.deleteFanPage(page);
}
int Facebook::checkIfFanExists(FanPage& fanToFind)
{
	return searcheFanPageInList(fanToFind);
}
int Facebook::searcheFanPageInList(FanPage& fanPageToFind)
{
	list<FanPage>::iterator itr = pages.begin();
	list<FanPage>::iterator itrEnd = pages.end();
	int index = ZERO;
	for (; itr != itrEnd; ++itr)
	{
		if (itr->getName() == fanPageToFind.getName())
		{
			return index;
		}
		index++;
	}
	return FALSE;
}
void Facebook::showAllPages()
{
	cout << "The fan pages in facebook are: " << endl << endl;

	int counter = ZERO;
	list<FanPage>::iterator itr = pages.begin();
	list<FanPage>::iterator itrEnd = pages.end();
	for (; itr != itrEnd; ++itr)
	{
		counter++;
		cout << counter << "." << itr->getName() << endl;
	}
}
int Facebook::choosePage()
{
	int page;
	cout << "Choose a page (his number)" << endl << endl;
	showAllPages();
	cin >> page;
	if (page > pages.size() || page < ONE)
	{
		throw FacebookExceptions(page);
	}
	return page;
}

//status
Status* Facebook::getStatusFromUser(string text, char* tm)
{
	Status newStatus(convertDate(tm), convertClock(tm), text);
	return &newStatus;
}

//general
void Facebook::showAllEntities()
{
	showAllUsers();
	cout << endl;
	showAllPages();

}
int Facebook::chooseUserOrPage()
{
	int statusChoice;
	cin >> statusChoice;
	if (statusChoice != ONE && statusChoice != TWO)
	{
		throw FacebookExceptions("You can Only choose 1 or 2");
	}
	return statusChoice;
}
