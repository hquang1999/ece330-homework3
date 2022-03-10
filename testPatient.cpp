#include "HeartRates.h"

unsigned int prevCurrentDay = 0;
unsigned int prevCurrentMonth = 0;
unsigned int prevCurrentYear = 0;

void setPatient(string firstName, string lastName, 
		unsigned int birthDay, unsigned int birthMonth, unsigned int birthYear,
		bool shareDates) {

	HeartRates patient (firstName, lastName, birthDay, birthMonth, birthYear);
	// Fail safe if statement. If the previous global variables are still empty,
	// the program should not share the previous date
	if ((prevCurrentDay != 0) && (prevCurrentMonth != 0) 
			&& (prevCurrentYear != 0)){
		// If it's not, check if the patients want to share the dates
		if (shareDates) {
			patient.setCurrentDay(prevCurrentDay);
			patient.setCurrentMonth(prevCurrentMonth);
			patient.setCurrentYear(prevCurrentYear);
		}
	}
	
	patient.getAge();
	patient.getPatientInformation();

	// If the current day, month, year are changed, update the
	// global variables so they can be possibly be used for the next patient.
	if ((prevCurrentDay != patient.getCurrentDay()) 
			&& (prevCurrentMonth != patient.getCurrentMonth()) 
			&& (prevCurrentYear != patient.getCurrentYear())){
		prevCurrentDay = patient.getCurrentDay(); 
		prevCurrentMonth = patient.getCurrentMonth(); 
		prevCurrentYear = patient.getCurrentYear(); 
	}
} 

int main() {

	setPatient("Johnny", "Sins", 31, 12, 1978, false);
	setPatient("Hieu", "Quang", 30, 8, 1999, true);
	setPatient("Ron", "Jeremy", 12, 3, 1953, true);
	setPatient("James", "Dean", 2, 7, 1986, true);
	
	return 0;
}
