#include <iostream>
#include <string>
using namespace std;
#include "funcs.h"


int searchUser(vector<Member*>& users, const Member& friendToFind)
{
	vector<Member*>::iterator itr = users.begin();
	vector<Member*>::iterator itrEnd = users.end();
	int index = 0;
	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == friendToFind.getName())
		{
			return index;
		}
		index++;
	}
	return FALSE;
}

int searchFanPages(vector<FanPage*>& pages, const FanPage& pageToFind)
{
	vector<FanPage*>::iterator itr = pages.begin();
	vector<FanPage*>::iterator itrEnd = pages.end();
	int index = 0;
	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == pageToFind.getName())
		{
			return index;
		}
		index++;
	}
	return FALSE;
}

const Clock& convertClock(char* arr)
{
	int hour, min;

	hour = (arr[ELEVEN] - ZERO_ASCII) * TEN + arr[TWELVE] - ZERO_ASCII;
	min = (arr[FOURTEEN] - ZERO_ASCII) * TEN + arr[FIFTEEN] - ZERO_ASCII;

	Clock clock(hour, min);

	return clock;

}

const Date& convertDate(char* arr)
{
	int year = ZERO, day = ZERO, month = ZERO;
	char str[FOUR];
	str[ZERO] = arr[FOUR];
	str[ONE] = arr[FIVE];
	str[TWO] = arr[SIX];
	str[THREE] = NULL_CHAR;

	year = (arr[TWENTY] - ZERO_ASCII) * THOUSEND + (arr[TWENTY_ONE] - ZERO_ASCII) * HUNDRED + (arr[TWENTY_TWO] - ZERO_ASCII) * TEN + (arr[TWENTY_THREE] - ZERO_ASCII);
	if (arr[EIGHT] == ' ')
	{
		day = arr[NINE] - ZERO_ASCII;
	}
	else
		day = (arr[EIGHT] - ZERO_ASCII) * TEN + arr[NINE] - ZERO_ASCII;

	if (strcmp(str, "Jan") == ZERO)
	{
		month = ONE;
	}
	else if (strcmp(str, "Feb") == ZERO)
	{
		month = TWO;
	}
	else if (strcmp(str, "Mar") == ZERO)
	{
		month = THREE;
	}
	else if (strcmp(str, "Apr") == ZERO)
	{
		month = FOUR;
	}
	else if (strcmp(str, "May") == ZERO)
	{
		month = FIVE;
	}
	else if (strcmp(str, "Jun") == ZERO)
	{
		month = SIX;
	}
	else if (strcmp(str, "Jul") == ZERO)
	{
		month = SEVEN;
	}
	else if (strcmp(str, "Aug") == ZERO)
	{
		month = EIGHT;
	}
	else if (strcmp(str, "Sep") == ZERO)
	{
		month = NINE;
	}
	else if (strcmp(str, "Oct") == ZERO)
	{
		month = TEN;
	}
	else if (strcmp(str, "Nov") == ZERO)
	{
		month = ELEVEN;
	}
	else if (strcmp(str, "Dec") == ZERO)
	{
		month = TWELVE;
	}

	Date date(day, month, year);

	return date;

}

int showMenuAndChooseOption()
{
	cout << endl << endl << "Welcome to Facebook!" << endl << endl;
	cout << "1.Add user to system." << endl;
	cout << "2.Add fan page to system." << endl;
	cout << "3.Add status." << endl;
	cout << "4.Show all statuses." << endl;
	cout << "5.Show last 10 statuss of user's friends." << endl;
	cout << "6.Connect friends." << endl;
	cout << "7.Unconnect friends." << endl;
	cout << "8.Add fan to page." << endl;
	cout << "9.Remove fan from page." << endl;
	cout << "10.Show all the entities in the system." << endl;
	cout << "11.Show all friends, or show all fans of fan page." << endl;
	cout << "12.Exit." << endl << endl;

	int choose = ZERO;
	do
	{
		cout << "Choose option from the menu: " << endl;
		cin >> choose;
		if (choose < ONE || choose >TWELVE)
		{
			throw GeneralExceptions("The number you choosed is invalid!");
		}

	} while (choose < ONE || choose >TWELVE);

	return choose;
}

void activateChoice(int num, Facebook& network, char* tm)
{
	Member* newUser;
	FanPage* newFanPage;
	string text;
	int userInd1, userInd2;
	int pageInd;
	int userOrPage; //when there is 2 option to activate -friend or fan page

	if (num == ONE)
	{
		newUser = network.createUser();
		network.addNewUser(*newUser);
	}
	else if (num == TWO)
	{
		newFanPage = network.createFanPage();
		network.addNewFanPage(*newFanPage);
	}

	else if (num == THREE)
	{
		cout << "Choose option 1/2 : " << endl << "1.Add status to friend."
			<< endl << "2.Add status to fan page." << endl;
		userOrPage = network.chooseUserOrPage();
		cout << "Enter the status's text: ";
		cin.ignore();
		getline(cin, text);
		Status newStatus(Date(convertDate(tm)), Clock(convertClock(tm)), text);
		if (userOrPage == ONE)
		{
			userInd1 = network.chooseUser();
			if (userInd1 != FALSE)
			{
				list<Member>::iterator itr = network.getUser().begin();
				advance(itr, userInd1);
				itr->addStatus(newStatus);
			}
		}
		else
		{
			pageInd = network.choosePage();
			if (pageInd != FALSE)
			{
				list<FanPage>::iterator itr = network.getPages().begin();
				advance(itr, pageInd);
				itr->addStatus(newStatus);
			}
		}


	}

	else if (num == FOUR)
	{
		cout << "Choose option 1/2 : " << endl << "1.Show statuses of friend."
			<< endl << "2.Show statuses of fan page." << endl;
		userOrPage = network.chooseUserOrPage();
		if (userOrPage == ONE)
		{
			userInd1 = network.chooseUser();
			if (userInd1 != FALSE)
			{
				list<Member>::iterator itr = network.getUser().begin();
				advance(itr, userInd1);
				itr->printAllStatus();
			}
		}
		else
		{
			pageInd = network.choosePage();
			if (pageInd != FALSE)
			{
				list<FanPage>::iterator itr = network.getPages().begin();
				advance(itr, pageInd);
				itr->printAllStatuses();
			}
		}
	}

	else if (num == FIVE) //need to chnage to vector
	{
		userInd1 = network.chooseUser();
		if (userInd1 != FALSE)
		{
			list<Member>::iterator itr = network.getUser().begin();
			advance(itr, userInd1);
			itr->print10LastEachFriendsStatus();
		}
	}

	else if (num == SIX)
	{
		userInd1 = network.chooseUser();
		userInd2 = network.chooseUser();
		if (userInd1 != FALSE && userInd2 != FALSE)
		{
			list<Member>::iterator itr1 = network.getUser().begin();
			advance(itr1, userInd1);
			list<Member>::iterator itr2 = network.getUser().begin();
			advance(itr2, userInd2);
			network.connectUsers((*itr1), (*itr2));
		}
	}

	else if (num == SEVEN)
	{
		userInd1 = network.chooseUser();
		userInd2 = network.chooseUser();
		if (userInd1 != FALSE && userInd2 != FALSE)
		{
			list<Member>::iterator itr1 = network.getUser().begin();
			list<Member>::iterator itr2 = network.getUser().begin();
			advance(itr1, userInd1);
			advance(itr2, userInd2);
			network.unConnectUsers(*itr1, *itr2);
		}
	}

	else if (num == EIGHT)
	{
		userInd1 = network.chooseUser();
		if (userInd1 != FALSE)
		{
			pageInd = network.choosePage();
			if (pageInd != FALSE)
			{
				list<Member>::iterator itrU = network.getUser().begin();
				list<FanPage>::iterator itrP = network.getPages().begin();
				advance(itrU, userInd1);
				advance(itrP, pageInd);

				itrU->addFanPageToFriend(*itrP);
				(*itrP)+=(*itrU);
			}
		}
	}

	else if (num == NINE)
	{
		userInd1 = network.chooseUser();
		if (userInd1 != FALSE)
		{
			pageInd = network.choosePage();
			if (pageInd != FALSE)
			{
				list<Member>::iterator itrU = network.getUser().begin();
				list<FanPage>::iterator itrP = network.getPages().begin();
				advance(itrU, userInd1);
				advance(itrP, pageInd);

				itrU->deleteFanPage(*itrP);
				itrP->deleteFans(*itrU);
			}
		}
	}

	else if (num == TEN)
	{
		network.showAllEntities();
	}

	else if (num == ELEVEN) //need to change to vector
	{
		cout << "Choose option 1/2 : " << endl << "1.Show all friends of a user."
			<< endl << "2.Show all fans of a fan page." << endl;
		userOrPage = network.chooseUserOrPage();
		if (userOrPage == ONE)
		{
			userInd1 = network.chooseUser();
			list<Member>::iterator itr = network.getUser().begin();
			advance(itr, userInd1);
			itr->printAllFriends();
		}
		else
		{
			pageInd = network.choosePage();
			list<FanPage>::iterator itr = network.getPages().begin();
			advance(itr, pageInd);
			itr->printAllFans();
		}
	}

	else if (num == TWELVE)
	{

		
		list<Member> ::iterator itrU = network.getUser().begin();
		list<Member> ::iterator itrUEnd = network.getUser().end();


		while (itrU != itrUEnd)
		{
			++itrU;
			network.getUser().pop_front();
			
		}

		list<FanPage> ::iterator itrP = network.getPages().begin();
		list<FanPage> ::iterator itrPEnd = network.getPages().end();

		while (itrP != itrPEnd)
		{
			++itrP;
			network.getPages().pop_front();
		}
	}
}