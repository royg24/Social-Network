#ifndef _MEMBER_H
#define _MEMBER_H

#include <string>
#include <vector>
#include <list>
#include "status.h"
#include "funcs.h"

class FanPage;

class MemberException : public std::exception
{
private:
	std::string msg;
public:
	MemberException(const std::string& errorTxt)
	{
		msg = errorTxt;
	}
	MemberException( const std::string& name1, std::string& name2,const std::string& situation)
	{
		msg = name1 + " and " + name2 + " are " + situation + " friends!";
	}
	MemberException(const std::string& friendName, const FanPage& fanPage,const std::string& situation)
	{
		msg = friendName + " is " + situation + " fan of " + fanPage.getName();
	}
	char const* what() const 
	{
		return msg.c_str();
	}
};



class Member
{
private:
	std::string name;
	Date birthdate;
	std::vector<FanPage*> pages;
	std::list<Status> statusBoard;
	std::vector<Member*> friends;

public:
	Member(const std::string& n, const Date& date); //init the arrays
	Member(const Member& n);
	~Member();

	//gettim , add phys size 
	const std::string& getName() const;
	const Date& getDate() const;

	std::vector<FanPage*> getThePages() const;
	std::list<Status> getStatusBoard() const;
	std::vector<Member*> getTheFriends() const;


	//friends
	void deleteFriend(Member& friendToDelete) noexcept (false); // delete friend and decrease the num of friend 
	void printAllFriends();
	int searchFriend(const Member& firendToFind);


	//fan page
	void addFanPageToFriend(FanPage& newPage) noexcept (false);//add page and increase the num of page 
	void deleteFanPage(FanPage& pageToDelete) noexcept (false); // delete page and decreas the num of page 
	int searchPage(FanPage& pageToFind);
	void printPages();

	//status
	void addStatus(Status& newStatus); // add status and increase the num of status
	void printAllStatus();
	void print10LastEachFriendsStatus();
	void print10LastStatus();


	//operators
	bool operator>(const Member& other) const;
	bool operator>(const FanPage& other) const;

	Member& operator+=( Member& newfriend) noexcept (false);

};



#endif // !_MEMBER_H