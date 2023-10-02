#ifndef _FUNCS_H
#define _FUNCS_H

enum eNums { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, ELEVEN, TWELVE, THIRTEEN, FOURTEEN, FIFTEEN };
constexpr int FALSE = -1, TWENTY = 20, TWENTY_ONE = 21, TWENTY_TWO = 22, TWENTY_THREE = 23;
constexpr int HUNDRED = 100, THOUSEND = 1000;
constexpr char NULL_CHAR = '\0', ZERO_ASCII = '0';

#include<list>
#include <vector>
#include "facebook.h"
#include "fan_page.h"
#include "member.h"


class Facebook;

class GeneralExceptions : public std::exception
{
private:
	std::string msg;
public:
	GeneralExceptions(const std::string& txt)
	{
		msg = txt;
	}
	char const* what() const
	{
		return msg.c_str();
	}
};

//search
int searchFanPages(std::vector<FanPage*>& pages, const FanPage& pageToFind);
int searchUser(std::vector<Member*>& users, const Member& friendToFind);

//convert string to clock
const Clock& convertClock(char* arr);
//convert string to date
const Date& convertDate(char* arr);

//the system facebook menu
int showMenuAndChooseOption();

void activateChoice(int num, Facebook& netWork, char* tm);




#endif // !_FUNCS_H
