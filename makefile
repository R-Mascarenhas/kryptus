
INC 	= -I include
CC 		= gcc
LIB 	= linked

SOURCES = linked.c \
		  Prompt.c

CFLAGS 	= -Wall -Wextra -std=c11

LFLAGS = -L.

OBJS:=$(SOURCES:.c=.o)

TARGET = program

all: build

%.o: %.c
	@echo "\nMAKING OBJECT FILES"
	$(CC) $(CFLAGS) $(INC)/ -c $< -o $@

%.a: $(OBJS)
	@echo "\nCREATING STATIC LIBRARY"
	ar rcs lib$(LIB).a $^

.PHONY: build clean run

build: lib$(LIB).a
	@echo "\nBUILDING FILES"
	$(CC) $(CFLAGS) $(LFLAGS) -l$(LIB) -o $(TARGET).out

run: build
	@echo "\nRUNNING..."
	./$(TARGET).out

clean:
	rm -f *.out *.a
	rm -f *.o

	