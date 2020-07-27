
#include "linked.h"

void analyze(char *input, list_t **start){
    
    char function[10];
    int neg = 1;
    memset(function, '\0', sizeof(function));

    int num = 0;
    int i = 0;

    for(i = 0; input[i] != '\0' && input[i] != ' '; i++){
        function[i] = input[i];
	}

    if(input[i] == ' '){
        for(++i; input[i] != '\n'; i++){
            if(input[i] == '-'){
                i++;
                neg = -1;
            }
            num = num*10 + (input[i] - '0');
        }
    }
    num *= neg;

	command(function, num, start);
    
}

void command(char * function, int num, list_t **start){
	
	if(strncmp(function,"put", 3) == 0){
			append(start, num);
			printList(*start);

		} else if(strncmp(function,"get", 3) == 0){
			int index = num - 1;
            printList(getElement(*start, index));

		} else if(strncmp(function,"first", 5) == 0){
			printList(getElement(*start, 0));

		} else if(strncmp(function,"last", 4) == 0){
			printList(getElement(*start, -1));

		} else if(strncmp(function,"list", 4) == 0){
			printList(*start);

		} else if(strncmp(function,"clear", 5) == 0){
			clear(start);

		} else if(strncmp(function,"remove", 6) == 0){
			int index = num - 1;
			removeElement(start, index);
			printList(*start);

		} else if(strncmp(function,"sort", 4) == 0){
            sortList(start);
            printList(*start);
        }
}


void append(list_t **start, int data){
	
    list_t *newNode = createNode(data);
	list_t *last = *start;

    if(*start == NULL)
        *start = newNode;
        
    else{ 
        
        while (last->next != NULL)
            last = last->next;
    
    last->next = newNode;  

    }
}

list_t *getElement(list_t* start, int index){
	list_t* current = start; 
      
    int aux = 0;

    if(start == NULL){
        return NULL;
    }

    if(index == -1){

        while(current->next != NULL)
		    current = current->next;
	    
        return createNode(current->num); 

    } else {
        while (current != NULL) 
        { 
            if (aux == index) 
                return createNode(current->num); 
        
            aux++; 
            current = current->next; 
        }
    }

    return NULL;
}

void printList(list_t *start) 
{ 
    list_t *node = start;

    while (node != NULL) 
    { 
        printf("%d ", node->num); 
        node = node->next; 
    }

    if(start == NULL)
        printf("The list is empty.");
    printf("\n");

    free(node);
} 

void removeElement(list_t **start, int index) 
{ 
   if (*start == NULL) 
      return; 
  
   list_t* previous = *start; 
  
    if (index == 0) 
    { 
        *start = previous->next;  
        printf("%d\n", (previous->num)); 
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
    
    printf("%d\n", (previous->next->num));
    free(previous->next);
  
    previous->next = next;  
} 

void clear(list_t **start) {
    list_t *ptr = *start;

    while (ptr != NULL) {
        *start = ptr;
        ptr = ptr->next;
        free(*start);
    }

    *start = NULL;
}

list_t *createNode(int num){
    list_t *newNode = (list_t *)malloc(sizeof(list_t));
    newNode->num = num;
    newNode->next = NULL;
    return newNode;
}

void sortList(list_t **start){
    
    list_t *ptr = *start;
    list_t *sortedList = createNode(ptr->num);
    list_t *newNode = NULL;
    
    ptr = ptr->next;

    while(ptr != NULL){
        newNode = createNode(ptr->num);
        insertIntoSort(&sortedList, newNode);
        ptr = ptr->next;
    }

    *start = sortedList;

}

void insertIntoSort(list_t **list, list_t *newNode){

    list_t *ptr = *list;
    list_t *prev = NULL;

    while(ptr != NULL && ptr->num < newNode->num){
        prev = ptr;
        ptr = ptr->next;
    }

    if(prev == NULL){
        newNode->next = *list;
        *list = newNode;
    } else {
        prev->next = newNode;
        newNode->next = ptr;
    }
}
