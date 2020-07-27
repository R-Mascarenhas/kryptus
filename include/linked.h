
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
void append(list_t** start, int data);
list_t *getElement(list_t* start, int index);
void printList(list_t* node);
void removeElement(list_t** start, int index);
void clear(list_t **start);
void analyze(char *input, list_t **start);
void command(char *function, int num, list_t **start);
void sortList(list_t **start);
void insertIntoSort(list_t **list, list_t *newNode);


#endif // ! __LINKED_H__
