#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "factoriser.h"

static unint delete_entries(char *buf, unint size, unint n) {
	unint deleted = 0;
	for (unint k = 2*n; k < size + 2; k += n) {
		if (buf[k - 2]) {
			buf[k - 2] = 0;
			deleted++;
		}
	}
	return deleted;
}

// buf[k] <=> k + 2;

unint sieve(char *buf, unint size) {
	unint primes = size;
	unint i;
	for (i = 0; i < size; i++)
		buf[i] = 1;
	for (unint i = 0; i < ((int)sqrt(size + 1)) + 1; i++) {
		if (!buf[i])
			continue;
		primes -= delete_entries(buf, size, i + 2);
	}
	return primes;
}

void produce_prime_table_t(primetable_t *table, unint max) {
	char *tmp = malloc(max - 1);
	if (!tmp) {
		fputs("ERROR: Could not allocate sieve\n", stderr);
		exit(-1);
	}
	unint tmpnum = sieve(tmp, max - 1);
	unint *tab = calloc(tmpnum, sizeof(unint));
	if (!tab) {
		fputs("ERROR: Could not allocate table\n", stderr);
		exit(-1);
	}
	unint i = 0;
	for (unint k = 0; k < max - 1; k++)
		if (tmp[k])
			tab[i++] = k + 2;
	free(tmp);
	table->buf = tab;
	table->size = tmpnum;
}

void produce_prime_table(unint max) {
	produce_prime_table_t(&global_primetable, max);
}

void free_prime_table_t(primetable_t *table) {
	free(table->buf);
	table->buf = NULL;
}

void free_prime_table(void) {
	free(global_primetable.buf);
	global_primetable.buf = NULL;
}
