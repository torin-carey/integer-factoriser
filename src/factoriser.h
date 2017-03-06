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

primetable_t global_primetable;

void produce_prime_table_t(primetable_t *table, unint max);
void produce_prime_table(unint max);
void free_prime_table_t(primetable_t *table);
void free_prime_table(void);

void factorise_t(factors_t *factors, primetable_t *primes, unint n);
void factorise(factors_t *factors, unint n);

void init_factors(factors_t *factors, unint max);
void resize_factors(factors_t *factors, unint max);
void free_factors(factors_t *factors);

unint totient_t(primetable_t *primes, unint n);
unint totient(unint n);

#endif
