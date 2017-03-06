#include <stdio.h>
#include <stdlib.h>

#include "factoriser.h"

#define MAX(a, b) (a) > (b) ? (a) : (b)

#define output(str) fputs(str, stdout)

int main(int argc, char **argv) {
	if (argc == 1)
		return -1;
	
	unint inputs[argc - 1];
	unint ninputs = argc - 1;
	unint largest = 0;

	for (unint i = 1; i < argc; i++) {
		inputs[i - 1] = (unint)strtol(argv[i], NULL, 10);
		largest = MAX(largest, inputs[i - 1]);
	}

	puts("Producing prime table...");
	primetable_t table;
	produce_prime_table(&table, largest);
	puts("done\n");
	
	factors_t factors;
	init_factors(&factors, 256); // Probably wont need to go over this

	for (unint k = 0; k < ninputs; k++) {
		unint n = inputs[k];
		factorise(&factors, &table, n);
		printf("%u = ", n);
		for (unint j = 0; j < factors.found; j++) {
			factorterm_t term = factors.terms[j];
			if (j)
				output(" * ");

			printf("%u", term.base);
			if (term.exponent != 1)
				printf("^%u", term.exponent);
			
		}
		putchar('\n');
	}

}
