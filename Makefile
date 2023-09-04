all:
	g++ main.cpp Connect.cpp md5.cpp -o client -lcryptopp

test:
	g++ unit_test.cpp md5.cpp Connect.cpp -o unit_test -lcryptopp -lUnitTest++ 
clean:
	rm -f client, unit_test

