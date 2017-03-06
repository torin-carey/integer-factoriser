#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "factoriser.h"

void factorise_t(factors_t *factors, primetable_t *primes, unint n) {
//	assert(primes->buf[primes->size - 1] >= n);
	
	unint lprime = 0;
	unint prime = primes->buf[0];
	unint primei = 0;
	factors->found = 0;
	while (prime <= n) {
		if (!(n % prime)) {
			if (prime == lprime) {
				factors->terms[factors->found - 1].exponent++;
			} else {
				if (factors->found == factors->nmemb) {
					resize_factors(factors, factors->nmemb * 2);
				}
				lprime = prime;
				factors->terms[factors->found].base = prime;
				factors->terms[factors->found++].exponent = 1;
			}
			n /= prime;
		} else {
			prime = primes->buf[++primei];
		}
	}
}

void factorise(factors_t *factors, unint n) {
	factorise_t(factors, &global_primetable, n);
}

void init_factors(factors_t *factors, unint max) {
	factors->nmemb = max;
	factors->found = 0;
	factors->terms = calloc(max, sizeof(factorterm_t));
}

void resize_factors(factors_t *factors, unint max) {
	void *ptr = realloc(factors->terms, max * sizeof(factorterm_t));
	if (!ptr) {
		fputs("ERROR: Could not reallocate term list\n", stderr);
		exit(-1);
	}
	factors->nmemb = max;
	factors->terms = ptr;
}

void free_factors(factors_t *factors) {
	free(factors->terms);
	factors->terms = NULL;
}
