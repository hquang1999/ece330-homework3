#include <iostream>
#include <string>
using namespace std;

class HeartRates { 
	private:
		// Patient's data types
		string firstName;
		string lastName;
		unsigned int dayOfBirth;
		unsigned int monthOfBirth;
		unsigned int yearOfBirth;
		
		// Data types for the current date
		unsigned int currentDay = 0;
		unsigned int currentMonth = 0;
		unsigned int currentYear = 2022;
	
	public:
		HeartRates(const string &, const string &, unsigned int = 1, unsigned int = 1, unsigned int = 0);

		// Functions for setting and getting attributes of the patient
		void setFirstName(const string &);
		string getFirstName() const;
		
		void setLastName(const string &);
		string getLastName() const;

		void setPatientYear(unsigned int);
		unsigned int getPatientYear() const;
	
		void setPatientMonth(unsigned int);
		unsigned int getPatientMonth() const;
	
		void setPatientDay(unsigned int);
		unsigned int getPatientDay() const;
	
		// Function that checks if the input is valid corresponding
		// to its respective day/month/year (more details in .cpp)
		bool isDateValid(unsigned int, unsigned int, unsigned int);

		// Functions to get input of the current date from the user
		void deterCurrentYear();
		void deterCurrentMonth();
		void deterCurrentDay();
		string monthToString(unsigned int);
		void askCurrentDate();
		
		// Setters and getters for the current date 
		void setCurrentDay(unsigned int);
		unsigned int getCurrentDay() const;

		void setCurrentMonth(unsigned int);
		unsigned int getCurrentMonth() const;

		void setCurrentYear(unsigned int);
		unsigned int getCurrentYear() const;

		// Functions for displaying patient 
		unsigned int getAge();
		unsigned int getMaximumHeartRate();
		void  getTargetHeartRate();
		void getPatientInformation();
};
