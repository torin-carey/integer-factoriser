#include "factoriser.h"

static inline unint intpow(unint base, unint exponent) {
	unint product = 1;
	for (unint k = 0; k < exponent; k++)
		product *= base;
	return product;
}

unint totient_t(primetable_t *primes, unint n) {
	factors_t factors;
	init_factors(&factors, 64);
	factorise(&factors, n);
	
	unint tot = 1;
	for (unint i = 0; i < factors.found; i++) {
		factorterm_t term = factors.terms[i];
		tot *= intpow(term.base, term.exponent - 1) * (term.base - 1);
	}

	free_factors(&factors);
	return tot;
}

unint totient(unint n) {
	return totient_t(&global_primetable, n);
}
