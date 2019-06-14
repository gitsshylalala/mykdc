.PHONY:clean all

WORKDIR=.
VPATH=./src

CPP=g++
CPPFLAGS=-Wall -g -I$(WORKDIR)/inc/ -std=c++11
CPPFLAGSSO=-I$(WORKDIR)/inc/ -L$(WORKDIR)/lib/ -lkdcapi -Wl,-rpath $(WORKDIR)/lib/ -std=c++11

BIN=client test_kdcapi

all:$(BIN)

#client: log.o send_and_recv.o cfg_op.o cli_socket.o msg_corr.o method.o cli_main.o
client:
	$(CPP) $(CPPFLAGS) $^ -o $@ $(WORKDIR)/lib/libclientmake.a

test_kdcapi: $(WORKDIR)/example/test_kdcapi.cpp
	$(CPP) $(CPPFLAGSSO) $^ -o $@ 

clean:
	rm -rf $(BIN)
