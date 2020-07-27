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


int main() {
	
	char input[201];
	list_t* start = NULL;

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
		
		analyze(input, &start);

	}

	return EXIT_SUCCESS;
}
