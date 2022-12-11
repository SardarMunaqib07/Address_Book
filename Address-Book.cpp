//Name :Syed Ali Ahmed                          department: FBAS/BSSE/F-21
//Roll No :4308                                 university:International Islamic University Islamabad

//       1.save data to the book
//       2.display data of the person
//       3.search data from the address book
//       4.sort the record
//       5.print the data of people having birthday in the present month
//       6.print the details according to the association


#include <iostream>
#include <Windows.h>
using namespace std;

#define MAX 500            //limit of address book type

//menu for chosing the association to dispaly the particular associated data
void menu() {
	cout << "1.Friend" << endl;
	cout << "2.family" << endl;
	cout << "3.bussiness Associate" << endl;
}

/// menu for birthday months(option)
void menu2() {
	cout << "1.January" << endl;
	cout << "2.February" << endl;
	cout << "3.March" << endl;
	cout << "4.April" << endl;
	cout << "5.May" << endl;
	cout << "6.June" << endl;
	cout << "7.July" << endl;
	cout << "8.August" << endl;
	cout << "9.September" << endl;
	cout << "10.October" << endl;
	cout << "11.Nov" << endl;
	cout << "12.December" << endl;
}

//definning person Type class
class personType {
	string firstName;
	string lastName;
public:
	personType(string first, string second) :firstName(first), lastName(second) {}
	personType() {
		firstName = "\0";
		lastName = "\0";
	}

	void setName();
	string getFirName();
	string getLasName();
};
void personType::setName() {
	cout << "enter the first Name" << endl;
	cin >> firstName;
	cout << "enter the last Name" << endl;
	cin >> lastName;
}
string personType::getFirName() {
	return firstName;
}
string personType::getLasName() {
	return lastName;
}

//definning address Type class

class AdressType {
	string address;
	string state;
	string city;
	unsigned zip;
public:
	AdressType(string Ad, string st, string ci, unsigned int z) :address(Ad), state(st), city(ci), zip(z) {}
	AdressType() {
		address = "\0";
		state = "\0";
		city = "\0";
		zip = 0000;
	}
	void setAdress();
	void getAddress();
};
void AdressType::setAdress() {
	cout << "enter the Address" << endl;
	cin >> address;
	cout << "enter the state" << endl;
	cin >> state;
	cout << "enter the city" << endl;
	cin >> city;
	cout << "enter the zip" << endl;
	cin >> zip;
}
void AdressType::getAddress() {
	cout << "Address : " << address << endl;
	cout << "state : " << state << endl;
	cout << "city : " << city << endl;
	cout << "zip : " << zip << endl;
}

/// definning class date Type (for date of birth)
class dateType {
	int day;
	int month;
	int year;
public:
	dateType(int dd, int mm, int yy) :day(dd), month(mm), year(yy) {}
	dateType() {
		day = 00;
		month = 00;
		year = 00;
	}
	void setDate();
	int getDay();
	int getMonth();
	int getYear();
};

void dateType::setDate() {
	SYSTEMTIME curr;
	GetSystemTime (&curr);
	cout << "year : ";
	cin >> year;
	while (year > 2022) {
		cout << "enter enter the correct year" << endl;
		cin >> year;
	}

	cout << "month : ";
	cin >> month;
	while ((month < 1 || month >12) || ((year==curr.wYear &&month>curr.wMonth))) {
		cout << "enter the correct month" << endl;
		cin >> month;
	}
	cout << "Day : "; 
	cin >> day;
	while ((day < 1 || day >31) || ((year == curr.wYear && month <= curr.wMonth && day > curr.wDay))) {
		cout << "enter the correct day" << endl;
		cin >> day;
	}
	
}
int dateType::getDay() {
	return day;
}
int dateType::getMonth() {
	return month;
}
int dateType::getYear() {
	return year;
}

class extPersonType :virtual public personType, virtual public AdressType, virtual public dateType {
	string association;
	unsigned long int phNum;
public:
	extPersonType() {
		personType();
		AdressType();
		dateType();
		association = "\0";
		phNum = 0000000;
	}
	void setInfo();
	void getInfo();
	string getAssociation();
};
string extPersonType::getAssociation() {
	return association;
}
void extPersonType::setInfo() {
	setName();
	setAdress();
	cout << "enter the date of birth "<<endl;
	setDate();
	cout << "chose the association" << endl;
	axbax:
	menu();
	char option;
	cin >> option;
	if (option < 1 && option>3) {
	}
		switch (option) {
		case '1':
			association = "Friend";
			break;
		case '2':
			association = "Family";
			break;
		case '3':
			association = "Bussiness Associate";
			break;
		default:
			cout << "chose the correct option" << endl;
			goto axbax;
	}
}
void extPersonType::getInfo() {
	cout << "Name : " << getFirName() << " " << getLasName() << endl;
	getAddress();
	cout << "date of birth : " << getDay() << " / " << getMonth() << " / " << getYear() << endl;
	cout << "association : " << association << endl;
}

class addressBookType {
	extPersonType* arr;
	int n;
public:
	addressBookType() {
		n = 0;
		arr = new extPersonType[MAX];
	}
	void setBook();
	void displBook(string last);
	int search(string);
	void sort();
	void printBirthPeron();
	void printAssociation();
};

//Depending on the user’s request, print the names of all family
// members, friends, or business associates
void addressBookType::printAssociation() {
	afaxt:
	menu();
	cout << "chose the option you want to diplay the data of" << endl;
	int option;
	cin >> option;
	if (option < 1 || option >3) {
		cout << "chose the correct option" << endl;
		goto afaxt;
	}
	else {
		for (int i = 0; i < n; i++) {
			if ((arr[i].getAssociation() == "Friend") && (option ==1)) {
				arr[i].getInfo();
			}
			else {
				if ((arr[i].getAssociation() == "Family") && (option==2)) {
					arr[i].getInfo();
				}
				else {
					if ((arr[i].getAssociation() == "Bussiness Associate") && (option == 3)) {
						arr[i].getInfo();
					}
					else {
						cout << "chose the correct option" << endl;
					}
				}
			}
				
		}
	}
}

//Printing the names of the people whose birthdays are in a given month.
void addressBookType::printBirthPeron() {
	cout << "chose the option you want to find the birthday of" << endl;
	 asxa:
	menu2();
	int option;
	cin >> option;
	if (option < 1 || option >12) {
		cout << "chose the correct option" << endl;
		goto asxa;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (option == arr[i].getMonth()) {
				arr[i].getInfo();
			}
			cout << endl;
		}
	}
}

//Sorting the address book by last name
void addressBookType::sort() {
	if (n != 0) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (arr[i].getLasName() > arr[j].getLasName()) {
					swap(arr[i], arr[j]);
				}
			}
		}
	}
	else {
		cout << "sorry no data is there to sort" << endl;
	}
}

///Search for a person by last name.
int addressBookType::search(string name) {
	for (int i = 0; i < n; i++) {
		if (name == arr[i].getLasName()) {
			return i;
		}
	}
	return -1;
}

//Load the data into the address book from a disk
void addressBookType::setBook() {
	cout << "                                   enter the number of person you want to store the data of" << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "enter the data of " << i + 1 << " person" << endl;
		arr[i].setInfo();
		cout << endl;
	}
}
//Print the address, phone number, and date of birth (if it exists) of a
//given person
void addressBookType::displBook(string last) {
	int index = search(last);
	if (index != -1) {
		arr[index].getInfo();
	}
	else {
		cout << "No such name exists" << endl;
	}
}

void menu3() {
	cout << "1.save data to the book" << endl;
	cout << "2.display data of the person" << endl;
	cout << "3.search data from the address book" << endl;
	cout << "4.sort the record" << endl;
	cout << "5.print the data of people having birthday in the present month" << endl;
	cout << "6.print the details according to the association" << endl;
	cout << "7.exit" << endl;
}
int main()
{
	addressBookType P;
	char option;
	string name;
	do {
		menu3();
		cout << "chose your option" << endl;
		cin >> option;
		switch (option) {
		case '1':
			P.setBook();
			break;
		case '2':
			cout << "enter the last Name of the person you want to display the data of" << endl;
			cin >> name;
			P.displBook(name);
			break;
		case '3':
			cout << "enter the last Name of the person you want to search the data of" << endl;
			cin >> name;
			P.search(name);
			break;
		case '4':
			P.sort();
			cout << "data is now Sorted" << endl;
			break;
		case '5':
			P.printBirthPeron();
			break;
		case '6':
			P.printAssociation();
			break;
		case '7':
			exit(0);
		default:
			cout << "chose the correct option" << endl;
		}

	} while (true);

}
