test: testPatient.o HeartRates.o
	g++ -o test testPatient.o HeartRates.o

testPatient.o: testPatient.cpp
	g++ -c testPatient.cpp

HeartRates.o: HeartRates.cpp
	g++ -c HeartRates.cpp

clean:
	-rm *.o test

