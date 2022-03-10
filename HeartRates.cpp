#include "HeartRates.h"
using namespace std;

HeartRates::HeartRates(const string &first, const string &last
		, unsigned int day, unsigned int month, unsigned int year) {
	firstName = first;
    lastName = last;
	setPatientYear(year);
	setPatientMonth(month);
	setPatientDay(day);
}

void HeartRates::setFirstName(const string &first) {
	firstName = first;
} 

string HeartRates::getFirstName() const {
	return firstName;
}
	
void HeartRates::setLastName(const string &last) {
	lastName = last;
}

string HeartRates::getLastName() const {
	return lastName;
}

void HeartRates::setPatientYear(unsigned int year) {
	if (isDateValid(year,1,0)) {
		yearOfBirth = year;
	}
	else {
		throw invalid_argument("Invalid YEAR Input");
	}
}

unsigned int HeartRates::getPatientYear() const {
	return yearOfBirth;
}

void HeartRates::setPatientMonth(unsigned int month) {
	if (isDateValid(month,3,0)) {
		monthOfBirth = month;	
	}
	else {
		throw invalid_argument("Invalid MONTH Input");
	}
}

unsigned int HeartRates::getPatientMonth() const {
	return monthOfBirth;
}

void HeartRates::setPatientDay(unsigned int day) {
	if (isDateValid(day,4,0)) {
		dayOfBirth = day;	
	}
	else {
		throw invalid_argument("Invalid DATE input");
	}
}

unsigned int HeartRates::getPatientDay() const {
	return dayOfBirth;
}
/* 
	Function that checks if the input is valid corresponding
   	to its respective day/month/year.

  	Case 1: Checking if the input x is valid for the year constraints of the patient
  	Case 2: Checking if the input x is valid for the year constraints of current
 	Case 3: Checking if the input x is valid for the month constraints
   	Case 4: Checking if the input x is valid for the day constraints 
   		   	that corresponds to the month

   	This function is to aid in cleaning up the boiler plate functions

   	whichMonth determines which month will be used.

   	0 = patient's month
   	1 = current's month
*/
bool HeartRates::isDateValid(unsigned int x, unsigned int type, unsigned int whichMonth) {
	int month;
	if (whichMonth == 0) {
		month = monthOfBirth; 
	}
	else if (whichMonth == 1) {
		month = currentMonth;
	}
	else {
		throw invalid_argument("Invalid input of which month type is used");
	}

	switch (type) {
		// Case 1, check the year constraint of the patient
		// It must be more than 0
		case 1:
			if (x > 0) {
				return true;
			} 
			else {
				return false;
			}
		// Case 2, check the year constraint for the current year
		// It must be more than the year of the patient
		case 2:
			if (x > yearOfBirth) {
				return true;
			} 
			else {
				return false;
			}	
		// Case 3, check the general month constraints [1 - 12]
		case 3:
			if ((x > 0) && (x <= 12)) {
				return true;
			} 
			else {
				return false;
			}
		// Case 4, check the general day constraints. This is dependent on the month
		case 4:
			// Accounting for february 
			if (month == 2) {
				// If the month is february, the days must be between 1 - 28
				if ((x <= 28) && (x > 0)) {
					return true;
				}
				else { 
					return false;
				}
			}
			// Accounting for the months with 31 days
			else if ((month == 1) || (month == 3) || (month == 5) || 
					 (month == 7) || (month == 8) || (month == 10) ||
					 (month == 12)) {
				if ((x <= 31) && (x > 0)) {
					return true;
				}
				else {
					return false;
				}
			}
			// No need to check if the other months are valid as months
			// the setters for both respective months should have been called
			else {
				// Check for the monoths with 30 days
				if ((x <= 30) || (x > 0)) {
					return true;
				}
				else {
					return false;
				}
			}
	}
}

// Function to get the current year from the user
void HeartRates::deterCurrentYear() {
	unsigned int tempYear;
	cout << "Enter Current YEAR: ";
	cin >> tempYear;
	if (isDateValid(tempYear,2,1)) {
		currentYear = tempYear;
	}
	else {
		// Otherwise, recursively call function and ask again
		cout << "Current year "  << tempYear << " is not greater than " 
			 << yearOfBirth << ", please re-enter!" << endl;
		deterCurrentYear();
	}
}

// Function to get the current month from the user
void HeartRates::deterCurrentMonth() {
	unsigned int tempMonth;
	cout << "Enter Current MONTH: ";
	cin >> tempMonth;
	if (isDateValid(tempMonth,3,1)) {
		currentMonth = tempMonth;
	}
	else {
		// Otherwise, recursively call function and ask again
		cout << "WARNING: Current month " << tempMonth 
			 << " is not in the range of [1 - 12], please re-enter!" << endl;
		deterCurrentMonth();
	}
}

// Function to get the current date from the user
void HeartRates::deterCurrentDay() { 
	unsigned int tempDay;
	cout << "Enter Current Date: ";
	cin >> tempDay;
	if (isDateValid(tempDay,4,1)) {
		currentDay = tempDay;
	}
	else { 
		cout << "WARNING: Current day " << tempDay 
			 << " if not valid for the month of " << monthToString(currentMonth)
			 << ", please re-enter!" << endl;
		deterCurrentDay();
	}
}

// case function to read out the month
string HeartRates::monthToString(unsigned int month) {
	switch (month) {
		case 1:
			return "January";
		case 2:
			return "February";
		case 3:
			return "March";
		case 4:
			return "April";
		case 5:
			return "May";
		case 6:
			return "June";
		case 7:
			return "July";
		case 8:
			return "August";
		case 9:
			return "September";
		case 10:
			return "October";
		case 11:
			return "November";
		case 12:
			return "December";
	}
}
// Setters and getters for the current date 
void HeartRates::setCurrentYear(unsigned int year) {
	currentYear = year;
}

unsigned int HeartRates::getCurrentYear() const {
	return currentYear;
}

void HeartRates::setCurrentMonth(unsigned int month) {
	currentMonth = month;
}

unsigned int HeartRates::getCurrentMonth() const {
	return currentMonth;
}


void HeartRates::setCurrentDay(unsigned int day) {
	currentDay = day;		
}

unsigned int HeartRates::getCurrentDay() const {
	return currentDay;
}

// Simple function that combines all the other determine functions
void HeartRates::askCurrentDate() {
	cout << "Getting the current date, enter INTS only!" << endl;
	deterCurrentYear();
	deterCurrentMonth();
	deterCurrentDay();
	cout << "Current Date: " << monthToString(currentMonth) 
		 << " " << currentDay << ", " << currentYear << endl;
}

// Get age
unsigned int HeartRates::getAge() {
	if ((currentDay == 0) && (currentMonth == 0)) {
		askCurrentDate();
	}
	// Checking if patient is younger than the current month
	if (currentMonth < monthOfBirth) {
		// If the patient is younger than the month,
		// then it's not their birtday yet.
		return currentYear - yearOfBirth - 1;
	} 
	// If the patient is the same as the current month
	else if (currentMonth == monthOfBirth) {
		if (currentDay < dayOfBirth) {
			// If they are younger than the current day, then
			// their birthday has not come yet.
			return currentYear - yearOfBirth - 1;
		}
	}
	// If the patient is older or equla to the current date, 
	// do current year - year of birth normally
	return currentYear - yearOfBirth;
}

unsigned int HeartRates::getMaximumHeartRate() {
	return 220 - getAge();	
}

void HeartRates::getTargetHeartRate() {
	cout << "Ideal Heart Rate: " 
		 << getMaximumHeartRate() * 0.5 << " - " 
		 << getMaximumHeartRate()  * 0.85 
		 << " bpm" << endl;
}

void HeartRates::getPatientInformation() { 
	cout << endl;
	cout << "Patient: " << lastName << ", "<< firstName << endl;
	cout << "Birthday: " << monthToString(monthOfBirth) 
		 << " " << dayOfBirth << ", " << yearOfBirth << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Maximum Heart Rate: " << getMaximumHeartRate() << " bpm" << endl;
	getTargetHeartRate();
	cout << endl;
}



