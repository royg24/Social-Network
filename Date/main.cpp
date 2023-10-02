#include <vector>
#include <list>

#include <iostream>
#include <ctime>
using namespace std;

#include "funcs.h"
#include "facebook.h"

int main(void)
{
	time_t currTime;
	currTime = time(NULL);
	char* tm = ctime(&currTime);


	Status s1(Date(1, 3, 2020), Clock(18, 33), "Hello");
	Status s2(Date(6, 7, 2021), Clock(13, 45), "Shalom");
	Status s3(Date(12, 5, 2022), Clock(19, 45), "Bye Bye");
	Status s4(Date(23, 9, 2022), Clock(21, 00), "Nice to meet you");
	Status s5(Date(16, 11, 2022), Clock(14, 15), "Blah Blah");
	Status s6(Date(31, 7, 2022), Clock(9, 10), "Fifa world cup 2022");

	Member f1("Roy", Date(24, 2, 1997));
	f1.addStatus(s1);
	f1.addStatus(s2);
	Member f2("Noa", Date(8, 2, 1998));
	f2.addStatus(s3);
	f2.addStatus(s4);
	Member f3("Ido", Date(7, 1, 1998));
	f3.addStatus(s5);
	f3.addStatus(s6);

	FanPage p1("Weddings");
	p1.addStatus(s3);
	p1.addStatus(s5);
	FanPage p2("World Cup");
	p2.addStatus(s1);
	p2.addStatus(s6);
	FanPage p3("Rami");
	p3.addStatus(s2);
	p3.addStatus(s4);

	Facebook system;
	system.addNewUser(f1);
	system.addNewUser(f2);
	system.addNewUser(f3);
	system.addNewFanPage(p1);
	system.addNewFanPage(p2);
	system.addNewFanPage(p3);

	list<Member>::iterator itrU = system.getUser().begin();
	list<FanPage>::iterator itrP = system.getPages().begin();

	system.addFanToPage((*itrP), (*itrU));
	advance(itrU, 1);
	advance(itrP, 1);
	system.addFanToPage((*itrP), (*itrU));
	advance(itrU, 1);
	advance(itrP, 1);
	system.addFanToPage((*itrP), (*itrU));

	list<Member>::iterator itr1 = system.getUser().begin();
	list<Member>::iterator itr2 = system.getUser().begin();
	list<Member>::iterator itr3 = system.getUser().begin();
	advance(itr2, 1);
	advance(itr3, 2);

	system.connectUsers((*itr1), (*itr2));
	system.connectUsers((*itr2), (*itr3));
	system.connectUsers((*itr3), (*itr1));


	int choosen = ZERO;
	while (choosen != TWELVE)
	{
		try
		{
			choosen = showMenuAndChooseOption();
			activateChoice(choosen, system, tm);
		}
		catch (const exception& e)
		{
			cout << "Exception Thrown:" << endl << e.what() << endl;
		}
		catch (...)
		{
			cout << "Unknown Error!" << endl;
		}
	}
	return ZERO;
}