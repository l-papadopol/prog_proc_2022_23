/****************************************************************/
/* Esame PP-PPL-PE_PPro-PLPr-CPro 2022/2023			                */
/*								                                              */
/* Programma per testare le congetture di Beal, Collatz, Cramèr */
/*								                                              */
/* Autori: Papadopol Lucian Ioan 	Matricola: 320648	            */
/* 	       Spaccamiglio Luca			           329999	            */
/****************************************************************/

/*****************************/
/* Inclusione delle librerie */
/*************************** */

#include <stdio.h>

/********************************/
/* Dichiarazione delle funzioni */
/****************************** */

int verifica_collatz(void);
int verifica_primi(unsigned long int);
int fattori_primi(unsigned long int,
                  unsigned long int,
                  unsigned long int);

/******************************/
/* Definizione delle funzioni */
/******************************/

/* Definizione della funzione main */
int main(void)
{
  /* dichiarazione delle variabili locali alla funzione */
  int congettura; /* input: selezione congettura */

  /* visualizzazione interfaccia menù di scelta */
  printf(" PROGRAMMA DI TEST CONGETTURE DI BEAL - COLLATZ - CRAMÈR \n"
         "---------------------------------------------------------\n"
         "[1] Beal\n"
         "[2] Collatz\n"
         "[3] Cramèr\n"
         "----------------------------------------------------------\n"
         "Digita il numero relativo alla tua scelta e premi invio. \n"
         );

  /* acquisizione scelta */
  scanf("%d",
        &congettura);

  switch (congettura)
  {
  case 2:
    verifica_collatz();
    break;
  }
}

/* Definizione della funzione per verificare la congettura di Collatz */
int verifica_collatz(void)
{
  /* dichiarazione delle variabili locali alla funzione */
  unsigned long int n;           /* input: numero naturale */
  int esito_lettura,             /* lavoro: esito della scanf */
      acquisizione_errata;       /* lavoro: esito complessivo dell’acquisizione_errata */

  /* acquisire un numero 'n > 0' */
  do
  {
    printf("Inserire un numero 'n' intero > 0: \n");
    esito_lettura = scanf("%lu",
                          &n);
    acquisizione_errata = esito_lettura != 1 || n <= 0 || n >= 4294967295;
    if (acquisizione_errata)
      printf("Valore non accettabile! \n");
    while (getchar() != '\n');
  } while (acquisizione_errata);

  /* stampare il numero se il suo valore è 1 */
  if (n == 1)
    printf("%lu", n);

  /* calcolare il valore del numero fino al raggiungimento del valore 1 */
  else
  {
    printf("Numeri generati:\n");
    printf("----------------\n");
    do
    {
      if (n % 2 == 0)
        n = n / 2;
      else
        n = (n * 3) + 1;

      /* stampare ogni numero ottenuto dai calcoli */
      printf("\n%lu",
             n);
    } while (n != 1);
    printf("\n"); /* vado a capo dalla lista dei numeri generati */
    printf("Congettura verificata, raggiunto n == 1\n");
  }
  return (0);
}

/* Definizione della funzione per la verifica se un numero è primo */
int verifica_primi(unsigned long int numero) /* input:  valore da verificare */
{
  /* dichiarazione delle variabili locali alla funzione */
  unsigned long int loop;         /* lavoro: controllo ciclo */
  int risultato = 1;              /* output: inizializzo a '1' */

  /* ciclo di verifica se un primo è effettivamente tale */
  for (loop = 2; loop < numero; loop++)
  {
    if ((numero % loop) == 0)
    {
      risultato = 0;
    }
  }

  return risultato; /*restituisco il risultato della verifica */
}

/* Definizione della funzione per verificare quanti fattori primi vi sono in comune in una tripla */
/* di numeri naturali positivi composti >2 */
int fattori_primi(unsigned long int numero_a,
                  unsigned long int numero_b,
                  unsigned long int numero_c)
{
  /* dichiarazione delle variabili locali alla funzione */
  int loop = 2,       /* lavoro: controllo ciclo*/
      primi_comuni;   /* output: numero di numeri primi in comune ad numero_a, numero_b e numero_c */

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
