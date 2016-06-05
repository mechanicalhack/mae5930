
file = main

all:
	g++ -std=c++11 -I /usr/local/include/eigen3 ${file}.cpp -o ${file}.exec

clean:
	rm ${file}.exec 

run:
	./${file}.exec
