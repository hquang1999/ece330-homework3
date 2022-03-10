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

void HeartRates::setPatientDay(unsigned int day) {
	// Accounting for february 
	if (monthOfBirth == 2) {
		// If the month is february, the days must be between 1 - 28
		if ((day <= 28) && (day > 0)) {
			dayOfBirth = day;	
		}
		else { 
			throw invalid_argument("Invalid DATE input");
		}
	}
	// Accounting for the months with 31 days
	else if ((monthOfBirth == 1) || (monthOfBirth == 3) || (monthOfBirth == 5) || 
			 (monthOfBirth == 7) || (monthOfBirth == 8) || (monthOfBirth == 10) ||
			 (monthOfBirth == 12)) {
		if ((day <= 31) && (day > 0)) {
			dayOfBirth = day;	
		}
		else {
			throw invalid_argument("Invalid DATE input");
		}
	}
	// Other months are accounted for from the the month setters. The months will
	// stay in scope from 1 - 12.
	else {
		// The remaining months will be between 1 - 30
		if ((day <= 30) && (day > 0)) {
			dayOfBirth = day;	
		}
		else {
			throw invalid_argument("Invalid DATE input");
		}
	}
}

unsigned int HeartRates::getPatientDay() const {
	return dayOfBirth;
}

void HeartRates::setPatientMonth(unsigned int month) {
	if ((month > 0) && (month <= 12)) {
		monthOfBirth = month;	
	}
	else {
		throw invalid_argument("Invalid MONTH Input");
	}
}

unsigned int HeartRates::getPatientMonth() const {
	return monthOfBirth;
}

void HeartRates::setPatientYear(unsigned int year) {
	if (year > 0) {
		yearOfBirth = year;
	}
	else {
		throw invalid_argument("Invalid YEAR Input");
	}
}

unsigned int HeartRates::getPatientYear() const {
	return yearOfBirth;
}

// Function to get the current year from the user
void HeartRates::deterCurrentYear() {
	unsigned int tempYear;
	cout << "Enter Current YEAR: ";
	cin >> tempYear;
	// The inputted (current) year must be greater than yearOfBirth
	if (tempYear > yearOfBirth) {
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
	// The inputted (current) month must be between 1 - 12
	if ((tempMonth > 0) && (tempMonth <= 12)) {
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
	if (currentMonth == 2) {
		if ((tempDay <= 28) && (tempDay > 0)) {
			currentDay = tempDay;
		}
		else { 
			cout << "WARNING: Current day " << tempDay 
				 << " if not valid for the month of " << monthToString(currentMonth)
				 << ", please re-enter!" << endl;
			deterCurrentDay();
		}
	}
	else if ((currentMonth == 1) || (currentMonth == 3) || (currentMonth == 5) || 
			 (currentMonth == 7) || (currentMonth == 8) || (currentMonth == 10) ||
			 (currentMonth == 12)) {
		if ((tempDay <= 31) && (tempDay > 0)) {
			currentDay = tempDay;
		}
		else {
			cout << "WARNING: Current day " << tempDay 
				 << " if not valid for the month of " << monthToString(currentMonth)
				 << ", please re-enter!" << endl;
			deterCurrentDay();
		}
	}
	else {
		if ((tempDay <= 30) || (tempDay > 0)) {
			currentDay = tempDay;
		}
		else {
			cout << "WARNING: Current day " << tempDay 
				 << " if not valid for the month of " << monthToString(currentMonth)
				 << ", please re-enter!" << endl;
			deterCurrentDay();
		}
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
void HeartRates::setCurrentDay(unsigned int day) {
	currentDay = day;		
}

unsigned int HeartRates::getCurrentDay() const {
	return currentDay;
}

void HeartRates::setCurrentMonth(unsigned int month) {
	currentMonth = month;
}

unsigned int HeartRates::getCurrentMonth() const {
	return currentMonth;
}

void HeartRates::setCurrentYear(unsigned int year) {
	currentYear = year;
}

unsigned int HeartRates::getCurrentYear() const {
	return currentYear;
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



