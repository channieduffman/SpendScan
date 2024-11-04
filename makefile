CXX = g++
CXXVERSION = -std=c++17
CXXFLAGS = -Wall -g

OBJS = main.o Transaction.o FieldsError.o Print.o

spendscan: $(OBJS)
	$(CXX) $(CXXVERSION) $(CXXFLAGS) -o spendscan $(OBJS)


main.o: main.cpp Transaction.h FieldsError.h Print.h
	$(CXX) $(CXXVERSION) $(CXXFLAGS) -c main.cpp


Transaction.o: Transaction.cpp Transaction.h
	$(CXX) $(CXXVERSION) $(CXXFLAGS) -c Transaction.cpp


FieldsError.o: FieldsError.cpp FieldsError.h
	$(CXX) $(CXXVERSION) $(CXXFLAGS) -c FieldsError.cpp


Print.o: Print.cpp Print.h
	$(CXX) $(CXXVERSION) $(CXXFLAGS) -c Print.cpp


clean:
	rm -f *.o spendscan
