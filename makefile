
INC 	= -I include
CC 		= gcc
LIB 	= linked

SOURCES = linked.c \
		  Prompt.c

CFLAGS 	= -Wall -std=c11 -g

LFLAGS = -L.

OBJS:=$(SOURCES:.c=.o)

TARGET = Prompt

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
	$(CC) $(CFLAGS) $(LFLAGS) -l$(LIB) -o $(TARGET)

run: build
	@echo "\nRUNNING..."
	./$(TARGET)

clean:
	rm -f *.out *.a *.o $(TARGET)

	