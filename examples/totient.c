#include <stdio.h>
#include <stdlib.h>

#include "factoriser.h"

#define MAX(a, b) (a) > (b) ? (a) : (b)

int main(int argc, char **argv) {
	if (argc == 1) {
		puts("Usage: totient [integer] ...");
		return -1;
	}
	
	unint inputs[argc - 1];
	unint ninputs = argc - 1;
	unint largest = 0;

	for (unint i = 1; i < argc; i++) {
		inputs[i - 1] = (unint)strtol(argv[i], NULL, 10);
		largest = MAX(largest, inputs[i - 1]);
	}

	puts("Producing prime table...");
	produce_prime_table(largest);
	puts("done\n");
	
	for (unint k = 0; k < ninputs; k++) {
		unint n = inputs[k];
		unint tot = totient(n);
		printf("phi( %u ) = %u\n", n, tot);
	}
	
	free_prime_table();
}
