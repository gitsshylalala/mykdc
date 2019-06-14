.PHONY:clean all

WORKDIR=.
ITEM=./item

CPP=g++
CPPFLAGS=-Wall -g -I$(WORKDIR)/include/ -std=c++11
LIBRARY=-L$(WORKDIR)/lib

BIN=client KdcApi_example

all:$(BIN)

client: $(ITEM)/*.o
	$(CPP) $(CPPFLAGS) $^ -o $@

KdcApi_example:./example/test_kdcapi.o
	$(CPP) $^ -o $@ $(LIBRARY) -lkdcapi
	rm $^

%.o:%.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN)
