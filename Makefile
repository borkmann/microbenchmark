CC=gcc
CFLAGS=-g -I. #-O2
ASFLAGS=-g

EXE=test

OBJS=test.o testb.o testw.o testl.o testq.o

all: $(EXE)
	./$(EXE)

$(EXE): $(OBJS)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJS) $(EXE)
