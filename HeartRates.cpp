#include "HeartRates.h"
using namespace std;

HeartRates::HeartRates(const string &first, const string &last
		, unsigned int day, unsigned int month, unsigned int year) {
	firstName = first;
    lastName = last;
	if (year <= currentYear) {
		if (month == 2) {
			if ((day <= 28) && (day > 0)) {
				dayOfBirth = day;	
				monthOfBirth = month;
				yearOfBirth = year;
			}
			else { 
				cout << "Invalid DATE input" << endl;
			}
		}
		else if ((month == 1) || (month == 3) || (month == 5) || 
				 (month == 7) || (month == 8) || (month == 10) ||
				 (month == 12)) {
			if ((day <= 31) && (day > 0)) {
				dayOfBirth = day;	
				monthOfBirth = month;
				yearOfBirth = year;
			}
			else {
				cout << "Invalid DATE input" << endl;
			}
		}
		else if ((month == 4) || (month == 6) || (month == 9) || 
				 (month == 11)) {
			if ((day <= 30) && (day > 0)) {
				dayOfBirth = day;	
				monthOfBirth = month;
				yearOfBirth = year;

			}
			else {
				cout << "Invalid DATE input" << endl;
			}
		}
		else {
				cout << "Invalid MONTH input" << endl;
		}
	} 
	else {
		cout << "Invaid YEAR input" << endl;
	}

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

void HeartRates::setDay(unsigned int day) {
	if (monthOfBirth == 2) {
		if ((day <= 28) && (day > 0)) {
			dayOfBirth = day;	
		}
		else { 
			cout << "Invalid DATE input" << endl;
		}
	}
	else if ((monthOfBirth == 1) || (monthOfBirth == 3) || (monthOfBirth == 5) || 
			 (monthOfBirth == 7) || (monthOfBirth == 8) || (monthOfBirth == 10) ||
			 (monthOfBirth == 12)) {
		if ((day <= 31) && (day > 0)) {
			dayOfBirth = day;	
		}
		else {
			cout << "Invalid DATE input" << endl;
		}
	}
	else if ((monthOfBirth == 4) || (monthOfBirth == 6) || (monthOfBirth == 9) || 
			 (monthOfBirth == 11)) {
		if ((day <= 30) && (day > 0)) {
			dayOfBirth = day;	
		}
		else {
			cout << "Invalid DATE input" << endl;
		}
	}
	else if (monthOfBirth == 0) {
		cout << "Month has not been added yet" << endl;
	}
}

unsigned int HeartRates::getDay() const {
	return dayOfBirth;
}

void HeartRates::setMonth(unsigned int month) {
	if ((month > 0) && (month <= 12)) {
		monthOfBirth = month;	
	}
	else {
		cout << "Invalid MONTH Input" << endl;
	}
}

unsigned int HeartRates::getMonth() const {
	return monthOfBirth;
}

void HeartRates::setYear(unsigned int year) {
	if (year <= currentYear) {
		yearOfBirth = year;
	}
	else {
		cout << "Invalid YEAR Input" << endl;
	}
}

unsigned int HeartRates::getYear() const {
	return yearOfBirth;
}

void HeartRates::getPatientInformation() { 
	cout << "Patient: " << lastName << ", "<< firstName << endl;
	cout << "Birthday: " << monthOfBirth << " / " << dayOfBirth << " / " << yearOfBirth << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Maximum Heart Rate: " << getMaximumHeartRate() << endl;
	getTargetHeartRate();
}
void HeartRates::deterCurrentMonth() {
	unsigned int tempMonth;
	cout << "Enter Current Month: ";
	cin >> tempMonth;
	if ((tempMonth > 0) && (tempMonth <= 12)) {
		currentMonth = tempMonth;
	} 
	else {
		cout << "Invalid MONTH, please re-enter" << endl;
		deterCurrentMonth();
	}
}

void HeartRates::deterCurrentDay() { 
	unsigned int tempDay;
	cout << "Enter Current Date: ";
	cin >> tempDay;
	if (currentMonth == 2) {
		if ((tempDay <= 28) && (tempDay > 0)) {
			currentDay = tempDay;
		}
		else { 
			cout << "Invalid DATE input" << endl;
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
			cout << "Invalid DATE input" << endl;
			deterCurrentDay();
		}
	}
	else {
		if ((tempDay <= 30) || (tempDay > 0)) {
			currentDay = tempDay;
		}
		else {
			cout << "Invalid DATE input" << endl;
			deterCurrentDay();
		}
	}

}

unsigned int HeartRates::getAge() {
	if (currentDay == 0) {
		deterCurrentMonth();
		deterCurrentDay();
	}
	// Checking if patient is younger than the current day
	if (currentMonth < monthOfBirth) {
		return currentYear - yearOfBirth - 1;
	} 
	else if (currentMonth == monthOfBirth) {
		if (currentDay < dayOfBirth) {
			return currentYear - yearOfBirth - 1;
		}
	}
	// if fails check, then do current - year of birth
	return currentYear - yearOfBirth;
}

unsigned int HeartRates::getMaximumHeartRate() {
	return 220 - getAge();	
}

void HeartRates::getTargetHeartRate() {
	cout << "Ideal Heart Rate: " 
		 << getMaximumHeartRate() * 0.5 << " - " 
		 << getMaximumHeartRate()  * 0.85 << endl;
}

