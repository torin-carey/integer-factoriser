#ifndef _H_SRC_FACTORISER
#define _H_SRC_FACTORISER

typedef unsigned int unint;

typedef struct {
	unint base;
	unint exponent;
} factorterm_t;

typedef struct {
	factorterm_t *terms;
	unint nmemb;
	unint found;
} factors_t;

typedef struct {
	unint *buf;
	unint size;
} primetable_t;

void produce_prime_table(primetable_t *table, unint max);

void factorise(factors_t *factors, primetable_t *primes, unint n);

void init_factors(factors_t *factors, unint max);

void resize_factors(factors_t *factors, unint max);

#endif
