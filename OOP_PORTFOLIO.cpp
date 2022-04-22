#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <algorithm>
using namespace std;


class clsActivities {
private:
	string _sLocation;
	double _iPrice;
	string _availableDestinations;

public:
	//code get and set + friend XD functions
};

class clsEditHoliday {
private:
	int _totalDestinations;
public:
	void setTotalDestinations(int totalDestinations) { _totalDestinations = totalDestinations; }
	int getTotalDestinations() { return _totalDestinations; }
	clsEditHoliday();
};

clsEditHoliday::clsEditHoliday()
{
	_totalDestinations = 4;
}

class clsVacationer {
private:
	string _sName;
public:

};

class clsHoliday
{
private:
	int _iBudget;
	int _iTravellers;
	int _iChildren;

public:
	void setBudget(int iBudget) { _iBudget = iBudget; }
	int getBudget() { return _iBudget; }

	void setTravellers(int iTravellers) { _iTravellers = iTravellers; }
	int getTravellers() { return _iTravellers; }

	void setChildren(int iChildren) { _iChildren = iChildren; }
	int getChildren() { return _iChildren; }
};

class clsDestinations {
private:
	string _sHolidayDestination;
	int _iPrice;
	int _iMinimumTravellers;

public:
	void setDestination(string sHolidayDestination) { _sHolidayDestination = sHolidayDestination; }
	string getHolidayDestination() { return _sHolidayDestination; }

	void setPrice(int iPrice) { _iPrice = iPrice; }
	int getPrice() { return _iPrice; }

	void setMinTravellers(int iMinimumTravellers) { _iMinimumTravellers = iMinimumTravellers; }
	int getMinTravellers() { return _iMinimumTravellers; }

	/*static void lambdaBudget(vector<clsDestinations>& objDestinations)
	{
		vector<int> budgetLessThanUser;
		copy_if(objDestinations.begin(), objDestinations.end(), std::back_inserter(budgetLessThanUser), [](int n) { return n > 5; });
		
	}*/

	clsDestinations();
};

clsDestinations::clsDestinations()
{
	_sHolidayDestination = "";
	_iPrice = 0;
	_iMinimumTravellers = 0;
}

void holidayDestinations(vector<clsDestinations> *objDestinations)
{
	objDestinations->at(0).setDestination("Florida");
	objDestinations->at(0).setPrice(1300);
	objDestinations->at(0).setMinTravellers(4);

	objDestinations->at(1).setDestination("Paris");
	objDestinations->at(1).setPrice(600);
	objDestinations->at(1).setMinTravellers(2);

	objDestinations->at(2).setDestination("Milan");
	objDestinations->at(2).setPrice(950);
	objDestinations->at(2).setMinTravellers(2);

	objDestinations->at(3).setDestination("Tokyo");
	objDestinations->at(3).setPrice(1800);
	objDestinations->at(3).setMinTravellers(4);
}

int initialiseBudget()
{
	int iUserBudget = 0;
	cout << "How much would you like to pay for this holiday?\n";
	cin >> iUserBudget;
	return (iUserBudget);
}

int initialiseTravellers()
{
	int iUserParty = 0;
	cout << "What is the size of your party?\n";
	cin >> iUserParty;
	return(iUserParty);
}

int initialiseChildren()
{
	int iChildren = 0;
	cout << "How many children are in your party?\n";
	cin >> iChildren;
	return(iChildren);
}

vector <clsDestinations> filterBudget(vector<clsDestinations> &objDestinations, int &iUserBudget, vector <clsDestinations> &objAvailableDestinations)
{	
	for (int x = 0; x < objDestinations.size(); x++)
	{
		if (objDestinations[x].getPrice() < iUserBudget)
		{
			objAvailableDestinations.push_back(clsDestinations());

			string sTempDest = objDestinations[x].getHolidayDestination();
			objAvailableDestinations[x].setDestination(sTempDest);

			int sTempPrice = objDestinations[x].getPrice();
			objAvailableDestinations[x].setPrice(sTempPrice);

			int sTempTravellers = objDestinations[x].getMinTravellers();
			objAvailableDestinations[x].setMinTravellers(sTempTravellers);
		}
	}
	return(objAvailableDestinations);
}

void returnAvailableBudget(vector <clsDestinations> &objAvailableDestinations)
{
	for ()
}

//Tried to use lambda notation to create an algorithm, unfortunately it didnt work but here is the code
//vector<int> lambdaBudgetSort(vector<clsDestinations> &objDestinations, int iUserBudget)
//{
//	std::sort(objDestinations.begin(), objDestinations.end(), [](clsDestinations& a, clsDestinations& b) {
//		return a.getPrice() < b.getPrice();
//}

void menuBook()
{
	clsEditHoliday holidays;
	vector<clsDestinations> objDestinations(holidays.getTotalDestinations());
	holidayDestinations(&objDestinations);
	clsHoliday userExp;

	cout << "Before I can show you holidays - I will need to ask some questions from you!";

	int iUserBudget = initialiseBudget();
	int iTravellers = initialiseTravellers();
	int iChildren = initialiseChildren();

	vector <clsDestinations> objAvailableDestinations(0);

	cout << "======================================\n";
	cout << "======================================\n";
	cout << "====   __  __                     ====\n";
	cout << "====  |  \\/  |                    ====\n";
	cout << "====  | \\  / | ___ _ __  _   _    ====\n";
	cout << "====  | |\\/| |/ _ \\ '_ \\| | | |   ==== \n";
	cout << "====  | |  | |  __/ | | | |_| |   ====\n";
	cout << "====  |_|  |_|\\___|_| |_|\\__,_|   ====\n";
	cout << "====                              ====\n";
	cout << "======================================\n";
	cout << "======================================\n";
	cout << "\n";
	cout << "We have " << objDestinations.size() << " destinations available!\n";

	for (int x = 0; x < holidays.getTotalDestinations(); x++)
	{
		cout << "Destination" << x + 1 << ": " << objDestinations[x].getHolidayDestination() << "\n";
		cout << "Price" << ": " << objDestinations[x].getPrice() << "\n";
		cout << "Minimum Travellers" << ": " << objDestinations[x].getMinTravellers() << "\n";
		cout << "\n";
		Sleep(1500);
	}

	string filterInput = "";
	bool filter = true;
	do
	{
		cout << "Would you like to filter by available budget - or minimum travellers? Type budget, minimum, both or no accordingly \n";
		cin >> filterInput;

		if (filterInput == "budget")
		{
			objAvailableDestinations = filterBudget(objAvailableDestinations, iUserBudget, objDestinations);

			
		}
		else if (filterInput == "minimum")
		{

		}
		else if (filterInput == "both")
		{

		}
		else if (filterInput == "no")
		{
			filter = false;
		}
		else
		{
			cout << "That is an invalid input!";
		}
	} while (filter == true);

	bool bHolidayChoice = true;
	do
	{
		int iHolidayChoice = 0;
		cout << "What holiday would you like to go on? Please select the option numerically \n";
		cin >> iHolidayChoice;

		if (iHolidayChoice < 1 || iHolidayChoice > objDestinations.size() + 1)
		{
			cout << "That isn't a correct option! Please try again!\n";
		}
		else
		{
			bHolidayChoice = false;
		}

	} while (bHolidayChoice == true);

}

void menuReview()
{
	cout << "menu book";
}

void menuBundles()
{
	cout << "menu bundles";
}

void menu1()
{
	int iMenuChoice = 0;

	cout << "======================================\n";
	cout << "======================================\n";
	cout << "====   __  __                     ====\n";
	cout << "====  |  \\/  |                    ====\n";
	cout << "====  | \\  / | ___ _ __  _   _    ====\n";
	cout << "====  | |\\/| |/ _ \\ '_ \\| | | |   ==== \n";
	cout << "====  | |  | |  __/ | | | |_| |   ====\n";
	cout << "====  |_|  |_|\\___|_| |_|\\__,_|   ====\n";
	cout << "====                              ====\n";
	cout << "======================================\n";
	cout << "======================================\n";
	cout << "Option 1: Book a holiday\n";
	cout << "Option 2: Review Existing Holidays Booked\n";
	cout << "Option 3: View and Compare Bundles\n";
	cout << "What would you like to do today! Please select a number accordingly\n";
	cin >> iMenuChoice;

	switch (iMenuChoice)
	{
		case 1:
			system("cls");
			menuBook();
			break;

		case 2: 
			system("cls");
			menuReview();
			break;

		case 3:
			system("cls");
			menuBundles();
			break;
	}

}

int main()
{
	menu1();
}
