CC=gcc
CFLAGS=-g -I.
CFLAGS+=-O2
ASFLAGS=-g

EXE=test

OBJS=test.o switch-no-table.o switch.o switch-no-retpol.o

switch.o switch.s:                   CFLAGS += -mindirect-branch=thunk
switch-no-table.o switch-no-table.s: CFLAGS += -mindirect-branch=thunk --param=case-values-threshold=20

all: $(EXE)
	taskset 1 ./$(EXE)

$(EXE): $(OBJS)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJS) $(EXE)

prep:
	apt update
	apt install -y build-essential tuned
	tuned-adm profile latency-performance
