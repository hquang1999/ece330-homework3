#include <iostream>
#include <string>
using namespace std;

class HeartRates { 
	private:
		string firstName;
		string lastName;
		unsigned int dayOfBirth;
		unsigned int monthOfBirth;
		unsigned int yearOfBirth;
		// Types for the current date
		unsigned int currentDay = 0;
		unsigned int currentMonth = 0;
		unsigned int currentYear = 2022;

	public:
		HeartRates(const string &, const string &, unsigned int = 1, unsigned int = 1, unsigned int = 0);

		void setFirstName(const string &);
		string getFirstName() const;
		
		void setLastName(const string &);
		string getLastName() const;

		void setDay(unsigned int);
		unsigned int getDay() const;

		void setMonth(unsigned int);
		unsigned int getMonth() const;

		void setYear(unsigned int);
		unsigned int getYear() const;

		void getPatientInformation();
		unsigned int getAge() const;
		unsigned int getMaximumHeartRate() const;
		void  getTargetHeartRate();
};
