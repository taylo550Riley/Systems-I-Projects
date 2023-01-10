# you and the graders will be able to compile and run as follows
# to compile task1, type the command: make task1
# to run task1, type the command: make run-task1
# ...and so on for task2 and task3
# Please implement only two tasks.

task1: crypto.o
	g++ -Wall -o cryptoapp cryptoapp.cpp crypto.o
crypto.o: crypto.cpp crypto.h
	g++ -Wall -c crypto.cpp

task2: currencyconverter.o
	g++ -Wall -o currencyconverterapp currencyconverterapp.cpp currencyconverter.o
currencyconverter.o: currencyconverter.cpp cconverter.h
	g++ -Wall -c currencyconverter.cpp

clean:
	rm *.o

cpplint-task1: cryptoapp
	cpplint --filter=-build/include_subdir crypto.h crypto.cpp cryptoapp.cpp

cpplint-task2: currencyconverterapp
	cpplint --filter=-build/include_subdir cconverter.h currencyconverter.cpp currencyconverterapp.cpp

run-task1: cryptoapp
	./cryptoapp

run-task2: currencyconverterapp
	./currencyconverterapp
