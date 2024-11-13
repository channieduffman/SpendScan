CXX = g++
CXXVERSION = -std=c++2b
CXXFLAGS = -Wall -g

OBJS = main.o Transaction.o FieldsError.o Print.o Types.o

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

Types.o: Types.cpp Types.h
	$(CXX) $(CXXVERSION) $(CXXFLAGS) -c Types.cpp

clean:
	rm -f *.o spendscan
