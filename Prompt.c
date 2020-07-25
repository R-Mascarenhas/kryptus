/*
 ============================================================================
 Name        : Prompt.c
 Author      : Rafael Mascarenhas Costa
 Version     : 0.1
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked.h"


void print_entry(char *entry) {
	//printf("You entered: %s\n", entry);
}

int main(int argc, char *argv[]) {
	char input[201];
	list_t* head = NULL;

	while(1) {
		printf("prompt> ");
		if (fgets(input, 200, stdin) == NULL) {
			printf("An error ocurred.\n");
			break;
		}

		if (strncmp(input, "exit\n", 5) == 0) {
			printf("Leaving. Good bye.\n");
			break;
		}
		
		if(strncmp(input,"put", 3) == 0){
			put(&head, input[4] - '0');
			list(head);
		}

		if(strncmp(input,"get", 3) == 0){
			int index = input[4] - '0' - 1;
			printf("%d\n",get(head, index));
		}

		if(strncmp(input,"first", 5) == 0){
			printf("%d\n",first(head));
		}

		if(strncmp(input,"last", 4) == 0){
			printf("%d\n",last(head));
		}

		if(strncmp(input,"list", 4) == 0){
			list(head);
		}

		if(strncmp(input,"clear", 5) == 0){
			clear(head);
		}

		if(strncmp(input,"remove", 6) == 0){
			int index = input[7] - '0' - 1;
			removeNum(&head, index);
			list(head);
		}

		print_entry(input);
	}

	return EXIT_SUCCESS;
}
