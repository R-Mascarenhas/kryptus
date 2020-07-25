
#include "linked.h"


void put(list_t** hRef, int data){
	list_t* newNode = (list_t*) malloc(sizeof(list_t));
	
	list_t *last = *hRef;

	newNode->num = data;
    newNode->next = NULL;
    
	if (*hRef == NULL)  
    {  
        *hRef = newNode; 
        return;
    }
    
    while (last->next != NULL){  
        last = last->next;
    }
    last->next = newNode;  
}

int get(list_t* head, int index){
	list_t* current = head; 
      
    int aux = 0; 
    while (current != NULL) 
    { 
        if (aux == index) {
            return(current->num); 
        }
        aux++; 
        current = current->next; 
    }
}

void list(list_t *node) 
{ 
  while (node != NULL) 
  { 
     printf("%d ", node->num); 
     node = node->next; 
  } 
  printf("\n");
} 

void removeNum(list_t **hRef, int index) 
{ 
   if (*hRef == NULL) 
      return; 
  
   list_t* previous = *hRef; 
  
    if (index == 0) 
    { 
        *hRef = previous->next;   
        free(previous);               
        return; 
    } 
  
    for (int i = 0; previous != NULL && i < index-1; i++){ 
         previous = previous->next; 
    }
  
    if (previous == NULL || previous->next == NULL) {
         return; 
    }
  
    list_t *next = previous->next->next; 
    
    printf("%d\n", *(previous->next));
    free(previous->next);
  
    previous->next = next;  
} 

int first(list_t* head){
	return head->num;
}

int last(list_t* head){
	list_t* current = head; 
    if (current == NULL){
        return -1;
    }
    while(current->next != NULL){
		current = current->next;
	}
    return current->num;
}

void clear(list_t *head) {
    list_t *ptr = head;

    while (ptr != NULL) {
        head = ptr;
        ptr = ptr->next;
        free(head);
    }
}
