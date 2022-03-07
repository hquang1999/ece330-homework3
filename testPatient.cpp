#include "HeartRates.h"

void test (int xd) {
	xd = 2;
}

int main() {
	HeartRates patient ("Johnny", "Sins", 31, 12, 1978);

	patient.getPatientInformation();
	patient.getAge();
	patient.getMaximumHeartRate();
	patient.getTargetHeartRate();

	/*
	int lmao = 0;
	cout << "Enter lmao: ";
	cin >> lmao;
	cout << lmao << endl;
*/
	
	return 0;
}
