tests: typeid

typeid: typeid.cpp.o
	g++ -o ../../bin/int_l_typeid ../../bin/int_l_typeid.cpp.o && rm ../../bin/int_l_typeid.cpp.o

typeid.cpp.o: typeid.cpp OUT_DIR
	g++ -c -std=c++11 -o ../../bin/int_l_typeid.cpp.o typeid.cpp

OUT_DIR:
	mkdir -p ../../bin

clean:
	rm ../../bin/int_l_typeid
