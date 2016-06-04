
all:
	g++ -std=c++11 -I /usr/local/include/eigen3 main.cpp -o main.exec

clean:
	rm main.exec 

run:
	./main.exec
