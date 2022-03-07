#include "HeartRates.h"

int main() {
	HeartRates patient ("Johnny", "Sins", 31, 12, 1978);

	patient.getPatientInformation();
	patient.getAge();
	patient.getMaximumHeartRate();
	patient.getTargetHeartRate();

	
	return 0;
}
