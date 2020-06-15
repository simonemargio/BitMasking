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
        /*
         * Maschera.
         * Vengono nascosti alcuni bit mentre vengono selezionati altri.
         * 1 << k sposta il valore 1 di k posizioni.
         *
         * Quindi:
         * n=0.  ..00001.
         * n=1.  ..00010.
         * n=2.  ..00100.
         *
         */
        int mask = 1 << k;


        /*
         * Prendo il valore 11 (binario 1011) e faccio l'AND bit a bit della maschera.
         *
         * mask:     ..00001
         * 11:         01011
         * mask_n:     00001  *
         *
         * mask:     ..00010
         * 11:         01011
         * mask_n:     00010  *
         *
         * mask:     ..00100
         * 11:         01011
         * mask_n:     00000  *
         *
         * mask:     ..01000
         * 11:         01011
         * mask_n:     01000  *
         *
         * mask:     ..10000
         * 11:         01011
         * mask_n:     00000  *
         *
         * Tutti gli * rappresentato proprio il valore 11 in binario
         * 00001
         * 00010
         * 00000
         * 01000
         * 00000
         * -----
         * 01011
         *
         */
        int mask_n = n & mask;


        int bit_preso = mask_n >> k;

        bits[k] = bit_preso;
        printf("Metto|%d| in K|%d|\n",bits[k],k);
        /*
            Metto|1| in K|0|
            Metto|1| in K|1|
            Metto|0| in K|2|
            Metto|1| in K|3|
            Metto|0| in K|4|
            Metto|0| in K|5|
            Metto|0| in K|6|
            Metto|0| in K|7|
            Metto|0| in K|8|
            Metto|0| in K|9|
            Metto|0| in K|10|
            Metto|0| in K|11|
            Metto|0| in K|12|
            Metto|0| in K|13|
            Metto|0| in K|14|
            Metto|0| in K|15|
            Metto|0| in K|16|
            Metto|0| in K|17|
            Metto|0| in K|18|
            Metto|0| in K|19|
            Metto|0| in K|20|
            Metto|0| in K|21|
            Metto|0| in K|22|
            Metto|0| in K|23|
            Metto|0| in K|24|
            Metto|0| in K|25|
            Metto|0| in K|26|
            Metto|0| in K|27|
            Metto|0| in K|28|
            Metto|0| in K|29|
            Metto|0| in K|30|
            Metto|0| in K|31|
            Stampa finale: 11010000000000000000000000000000 <- lettura
         */
    }
    return bits;
}