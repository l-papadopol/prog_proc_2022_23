/*****************************/
/* Inclusione delle librerie */
/*************************** */

#include <stdio.h>

/********************************/
/* Dichiarazione delle funzioni */
/****************************** */

int fattori_primi(unsigned long int,
                  unsigned long int,
                  unsigned long int);

/* Definizione della funzione main */
int main()
{
    int a = 315,    /* 3*3*5*7 */
        b = 15,     /* 3*5 */
        c = 6375,   /* 3*5*5*5*17 */
        risultato;

    risultato = fattori_primi(a, b, c);
    printf("Vi sono %d numeri primi in comune tra %d,%d e %d\n", risultato, a, b, c);
    return (0);
}

int fattori_primi(unsigned long int numero_a,
                  unsigned long int numero_b,
                  unsigned long int numero_c)
{
    /* dichiarazione delle variabili locali alla funzione */
    int loop = 2,     /* lavoro: controllo ciclo*/
        primi_comuni; /* output: numeri primi in comune ad numero_a, numero_b e numero_c */

    while (numero_a >= loop && numero_b >= loop && numero_c >= loop)
    {
        if (numero_a % loop == 0 && numero_b % loop == 0 && numero_c % loop == 0)
        {
            numero_a /= loop;
            numero_b /= loop;
            numero_c /= loop;
            primi_comuni++;
        }
        else
            loop++;
    }
    return (primi_comuni);
}
