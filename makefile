all:
	g++ *.cpp Test/*.cpp -ITest/ -I./ -o MyApp
t:
	./MyApp test
r:
	./MyApp
