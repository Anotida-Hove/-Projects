CC = g++
CFLAGS = -Wall -std=c++14


account_management: bank_management.o management.o transaction.o account.o
	$(CC) $(CFLAGS) bank_management.o management.o transaction.o account.o -o account_management


bank_management.o: bank_management.cpp management.hpp account.hpp transaction.hpp
	$(CC) $(CFLAGS) -c bank_management.cpp

management.o: management.cpp management.hpp account.hpp transaction.hpp
	$(CC) $(CFLAGS) -c management.cpp

transaction.o: transaction.cpp transaction.hpp
	$(CC) $(CFLAGS) -c transaction.cpp

account.o: account.cpp account.hpp
	$(CC) $(CFLAGS) -c account.cpp


clean: 
	rm *.o account_management output.txt