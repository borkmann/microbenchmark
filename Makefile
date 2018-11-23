CC=gcc
CFLAGS=-g -I.
CFLAGS+=-O2 -mindirect-branch=thunk
ASFLAGS=-g

EXE=test

OBJS=test.o switch-no-table.o switch.o

switch-no-table.o switch-no-table.s: CFLAGS += -fno-jump-tables

all: $(EXE)
	./$(EXE)

$(EXE): $(OBJS)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJS) $(EXE)
