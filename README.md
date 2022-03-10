##**Heart Rates Program**

**Commands**
make
make clean
./test

**testPatient.cpp**
* This is the main. It has a helper function called _**setPatient**_ that takes in all the inputs needed to initialize a HeartRate object. This would be firstName, lastName, birthDay, birthMonth, birthYear. 
* It also takes in a boolean which determines whether the HeartRate objects should share the same inputted date or not as this would be tedious to input the same date everytime a new HeartRate object is created.

**HeartRates.h**
* Header file for the HeartRate class. Only thing special is the current date data points. Since these must be acquired from user input, they are private data with some initialized values to check for empties. 
* _**CurrentYear is by default, 2022**_.

**HeartRates.cpp**
* Where all the methods are. 
* Includes basic setters, getters, and prints.
* All int values are unsigned. We won't need to deal with negatives.
* Each date data value will have different constraints:
	* Patient year must be > 0. While the Current inputted year must be > patient year. This program only accounts for ages 1+.
	* The months will both have the same constraints [1 - 12]
	* The days are dependent on which month is used. Either current or patient's. Once the month have been established, the constraints are 
		* Month 2: Days [1 - 28] 
		* Month 1,3,5,7,8,10,12: Days [1 - 31] 
		* Month 4,6,9,11: Days [1 -30].
	* All of this is handled through the helper method isDateValid.
	* The setters for the dates all have exception handling and recursion to account for user input error.
* GetAge will call askCurrentDate() which will prompt the user to input the current day / month / year.
	* It will only call askCurrentDate() is the currentDay and currentMonth is empty (0). 	
* Evertyhgin else are either print functions or simple getters.

