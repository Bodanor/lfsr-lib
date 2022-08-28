#ifndef __LFSR_H__
#define __LFSR_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct lfsr_t LFSR;

LFSR *init_lfsr(char *seed, unsigned int tap);
char *show_lsfr(LFSR *lfsr);
unsigned int operation (LFSR *lfsr);
unsigned int generation(LFSR *lfsr, unsigned int k);
void destroy_lfsr(LFSR *lfsr);

#endif