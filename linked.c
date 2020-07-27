
#include "linked.h"

void analyze(char *input, list_t **start){
    
    char function[10];
    memset(function, '\0', sizeof(function));

    int num = 0;
    int i = 0;

    for(i = 0; input[i] != '\0' && input[i] != ' '; i++){
        function[i] = input[i];
	}

    if(input[i] == ' '){
        for(++i; input[i] != '\n'; i++){
            num = num*10 + (input[i] - '0');
        }
    }

	command(function, num, start);
    
}

void command(char * function, int num, list_t **start){
	
	if(strncmp(function,"put", 3) == 0){
			put(start, num);
			list(*start);

		} else if(strncmp(function,"get", 3) == 0){
			int index = num - 1;
			printf("%d\n",get(*start, index));

		} else if(strncmp(function,"first", 5) == 0){
			printf("%d\n",first(*start));

		} else if(strncmp(function,"last", 4) == 0){
			printf("%d\n",last(*start));

		} else if(strncmp(function,"list", 4) == 0){
			list(*start);

		} else if(strncmp(function,"clear", 5) == 0){
			clear(start);

		} else if(strncmp(function,"remove", 6) == 0){
			int index = num - 1;
			removeNum(start, index);
			list(*start);
		}
}


void put(list_t **start, int data){
	
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

int get(list_t* start, int index){
	list_t* current = start; 
      
    int aux = 0; 
    while (current != NULL) 
    { 
        if (aux == index) 
            return(current->num); 
    
        aux++; 
        current = current->next; 
    }

    return -1;
}

void list(list_t *start) 
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

void removeNum(list_t **start, int index) 
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

int first(list_t* start){
	return start->num;
}

int last(list_t* start){
	list_t* current = start; 
    if (current == NULL){
        return -1;
    }
    while(current->next != NULL){
		current = current->next;
	}
    return current->num;
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
