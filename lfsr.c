#include "lfsr.h"

struct lfsr_t
{
    unsigned int bits_n;
    char *seed;
    unsigned int tap;

};

static void left_shift_string(LFSR *lfsr, int value)
{
    unsigned int i;
    char tmp;

    for (i = 1; i <= lfsr->bits_n - 1; i++){
        tmp = lfsr->seed[i];
        lfsr->seed[i - 1] = tmp;
    }
    lfsr->seed[lfsr->bits_n - 1] = value + 48;

}
LFSR *init_lfsr(char *seed, unsigned int tap)
{   
    int i;

    assert(seed != NULL);
    assert(tap >= 0);

    LFSR *lfsr = (LFSR*)malloc(sizeof(LFSR));
    if (lfsr == NULL)
        return NULL;
    
    lfsr->bits_n = strlen(seed);

    for (i = 0; i < lfsr->bits_n; i++){
        if (seed[i] != '1' && seed[i] != '0'){
            printf("Bad seed character in position %d\n", i);
            free(lfsr);
            return NULL;
        }
    }

    if (lfsr->bits_n >= tap){
        lfsr->seed = (char*)malloc(sizeof(char)*lfsr->bits_n + 1);
        if (lfsr->seed == NULL){
            free(lfsr);
            return NULL;
        }
        strcpy(lfsr->seed, seed);
        lfsr->tap = tap;
    }
    else{
        printf("Tap exceeds seed length !\n");
        free(lfsr);
        return NULL;
    }
    
    return lfsr;
}

char *show_lsfr(LFSR *lfsr)
{
    assert(lfsr != NULL);
    assert(lfsr->seed != NULL);

    return (lfsr->seed);
}
unsigned int operation (LFSR *lfsr)
{
    assert(lfsr != NULL);
    assert(lfsr->seed != NULL);
    unsigned int msb, result_bit;

    msb = *lfsr->seed;
    result_bit = msb ^ lfsr->seed[(lfsr->bits_n - 1) - lfsr->tap];
    left_shift_string(lfsr, result_bit);
    return result_bit;

}

unsigned int generation(LFSR *lfsr, unsigned int k)
{
    assert(lfsr != NULL);
    assert(lfsr->seed != NULL);

    unsigned int result = 0;

    while (k > 0){
        result *= 2;
        result += operation(lfsr);
        k--;
    }

    return result;
}

void destroy_lfsr(LFSR *lfsr)
{
    assert(lfsr != NULL);
    assert(lfsr->seed != NULL);

    free(lfsr->seed);
    free(lfsr);
    
    

}