#ifndef _FACEBOOK_H
#define _FACEBOOK_H

#include <vector>
#include <list>
#include <string>
#include "funcs.h"

class Member;
class FanPage;
class Status;

class FacebookExceptions : public std::exception
{
private:
	std::string msg;

public:
	FacebookExceptions(const std::string& name, const std::string& type)
	{
		msg = "There is already " + type + " with the name " + name;
	}
	FacebookExceptions(int index)
	{
		msg = "The index " + std::to_string(index) + " does not excist ";
	}
	FacebookExceptions(const std::string& txt)
	{
		msg = txt;
	}
	char const* what() const
	{
		return msg.c_str();
	}
};

class Facebook
{
private:
	std::list<Member> users;
	std::list<FanPage> pages;
public:
	Facebook() = default;
	//copy c'tor
	Facebook(const Facebook& other) = delete;

	//d'tor
	~Facebook();

	//gettim
	std::list<Member>& getUser();
	std::list<FanPage>& getPages();


	//users
	Member* createUser();
	void addNewUser(const Member& newUser) noexcept(false); //add user to the system, change sizes accordingly
	void connectUsers(Member& user1, Member& user2);
	void unConnectUsers(Member& user1, Member& user2);
	int checkIfNameExsists(const Member& userToFind);
	int searcheUserInList(const Member& userToFind);
	void showAllUsers();
	int chooseUser() noexcept(false);

	//fan page
	FanPage* createFanPage();
	void addNewFanPage(FanPage& newPage) noexcept(false); //add fan page to the system, change sizes accordingly
	void addFanToPage(FanPage& page, Member& newFan);
	void removeFanFromPage(FanPage& page, Member& fanToRemove);
	int checkIfFanExists(FanPage& fanToFind);
	int searcheFanPageInList(FanPage& fanPageToFind);
	void showAllPages();
	int choosePage() noexcept(false);

	//status
	Status* getStatusFromUser(std::string text, char* tm);

	//general
	void showAllEntities();
	int chooseUserOrPage();
};

#endif // !_FACEBOOK_H
