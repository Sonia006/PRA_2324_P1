bin/testListArray: testListArray.cpp ListArray.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp ListArray.h

clean:
	rm -r * .o * .gch bin
