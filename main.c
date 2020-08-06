#include <stdio.h>
#include <stdlib.h>
#define DIMENSIONE_ARRAY_MASCHERA_BINARIA 32

int *F_ottieni_bit(int n);

int main() {
    int *k=F_ottieni_bit(11);

    int i=0;
    for(;i<DIMENSIONE_ARRAY_MASCHERA_BINARIA;i++)
    printf("%d",k[i]);

    return 0;
}


int *F_ottieni_bit(int n)
{
    int *bits = malloc(sizeof(int)* DIMENSIONE_ARRAY_MASCHERA_BINARIA);

    int k;
    for(k=0;k<DIMENSIONE_ARRAY_MASCHERA_BINARIA;k++)
    {
        int mask = 1 << k;
        int mask_n = n & mask;
        int bit_preso = mask_n >> k;

        bits[k] = bit_preso;
    }
    return bits;
}