
#ifndef  __LINKED_H__
#define __LINKED_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct list{
    int num;
    struct list *next;
} list_t;

list_t *createNode(int num);
void put(list_t** start, int data);
int get(list_t* start, int index);
void list(list_t* node);
void removeNum(list_t** start, int index);
int first(list_t* start);
int last(list_t* start);
void clear(list_t **start);
void analyze(char *input, list_t **start);
void command(char *function, int num, list_t **start);


#endif // ! __LINKED_H__
