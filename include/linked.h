
#ifndef  __LINKED_H__
#define __LINKED_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct list{
    int num;
    struct list *next;
} list_t;

void put(list_t** hRef, int data);
int get(list_t* head, int index);
void list(list_t* node);
void removeNum(list_t** hRef, int index);
int first(list_t* head);
int last(list_t* head);
void clear(list_t* head);


#endif // ! __LINKED_H__
