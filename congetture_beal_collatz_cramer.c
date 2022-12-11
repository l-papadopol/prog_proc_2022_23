/****************************************************************/
/* Esame PP-PPL-PE_PPro-PLPr-CPro 2022/2023			                */
/*								                                              */
/* Programma per testare le congetture di Beal, Collatz, Cramèr */
/*								                                              */
/* Autori: Papadopol Lucian Ioan 	Matricola: 320648	            */
/* 	       Spaccamiglio Luca			       329999	                */
/****************************************************************/

/*****************************/
/* Inclusione delle librerie */
/*************************** */

#include <stdio.h>
#include <math.h>

/********************************/
/* Dichiarazione delle funzioni */
/****************************** */

int verifica_beal(void);
int verifica_collatz(void);

int verifica_primi(unsigned long int);

/******************************/
/* Definizione delle funzioni */
/******************************/

/* definizione della funzione main */
int main(void)
{
  /* dichiarazione delle variabili locali alla funzione */
  int congettura;          /* input: selezione congettura */
  int esito_lettura,       /* lavoro: esito della scanf */
      acquisizione_errata; /* lavoro: esito complessivo dell’acquisizione_errata */

  /* acquisizione scelta */
  do
  {
    /* visualizzazione banner/menù di scelta */
    printf(" PROGRAMMA DI TEST CONGETTURE DI BEAL - COLLATZ - CRAMÈR \n"
           "---------------------------------------------------------\n"
           "[1] Beal\n"
           "[2] Collatz\n"
           "[3] Cramèr\n"
           "----------------------------------------------------------\n"
           "Digita il numero relativo alla tua scelta e premi invio. \n");

    esito_lettura = scanf("%d",
                          &congettura);
    acquisizione_errata = esito_lettura != 1 || congettura > 3 || congettura <= 0;
    if (acquisizione_errata)
      printf("Valore non accettabile! \n \n");
    while (getchar() != '\n');
  } while (acquisizione_errata);

  switch (congettura)
  {
  case 1:
    verifica_beal();
    break;
  case 2:
    verifica_collatz();
    break;
  }
  return (0);
}

/* definizione della funzione per verificare la congettura di Beal */
int verifica_beal(void)
{
  int n[6],
      esito_lettura,       /* lavoro: esito della scanf */
      acquisizione_errata, /* lavoro: esito complessivo dell’acquisizione_errata */
      risultato = 0,
      loop_primi = 2,
      loop_input,
      lettere[6] = {'a',
                    'x',
                    'b',
                    'y',
                    'c',
                    'z'}; /* Input: array di caratteri */
  unsigned long int numero_ax,
                    numero_by,
                    numero_cz;
/* acquisire un numero 'n >= 1' per a, b, c */
  for (loop_input = 0; loop_input < 6; loop_input++)
  { 
    /* acquisire un numero 'n >= 3' per x, y, z */
    do
    {
      if (loop_input == 0 || loop_input == 2 || loop_input == 4)
        printf("Digita un valore %c >= 1: ",
               lettere[loop_input]);
      else
        printf("Digita l'esponente %c >= 3: ",
               lettere[loop_input]);

      esito_lettura = scanf("%d",
                            &n[loop_input]);

      if (loop_input == 0 || loop_input == 2 || loop_input == 4)
        acquisizione_errata = esito_lettura != 1 || n[loop_input] < 1;
      else
        acquisizione_errata = esito_lettura != 1 || n[loop_input] < 3;
      if (acquisizione_errata)
        printf("Valore non accettabile! \n");
      while (getchar() != '\n');
    } while (acquisizione_errata);
  }

  numero_ax = (int)pow(n[0], n[3]);
  numero_by = (int)pow(n[4], n[1]);
  numero_cz = (int)pow(n[2], n[5]);

  if (numero_ax + numero_by == numero_cz)
  {
    printf("Congettura verificata");
  }
  else
  {
    while (numero_ax >= loop_primi && numero_by >= loop_primi && numero_cz >= loop_primi)
    {
      if (numero_ax % loop_primi == 0 && numero_by % loop_primi == 0 && numero_cz % loop_primi == 0)
      {
        numero_ax /= loop_primi;
        numero_by /= loop_primi;
        numero_cz /= loop_primi;
        risultato++;
      }
      else
        loop_primi++;
    }
    printf("Congettura non verificata\n"
           "Vi sono %d numeri primi in comune\n",
           risultato);
  }
  return (0);
}

/* Definizione della funzione per verificare la congettura di Collatz */
int verifica_collatz(void)
{
  /* dichiarazione delle variabili locali alla funzione */
  unsigned long int n;     /* Input: numero naturale */
  int esito_lettura,       /* lavoro: esito della scanf */
      acquisizione_errata; /* lavoro: esito complessivo dell’acquisizione_errata */

  /* acquisire un numero 'n > 0' */
  do
  {
    printf("Inserire un numero 'n' intero > 0: \n");
    esito_lettura = scanf("%lu",
                          &n);
    acquisizione_errata = esito_lettura != 1 || n <= 0 || n >= 4294967295;
    if (acquisizione_errata)
      printf("Valore non accettabile! \n");
    while (getchar() != '\n')
      ;
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
  unsigned long int loop; /* lavoro: controllo ciclo */
  int risultato = 1;      /* output: inizializzo a '1' */

  /* ciclo di verifica se un primo è effettivamente tale */
  for (loop = 2; loop < numero; loop++)
  {
    if ((numero % loop) == 0)
    {
      risultato = 0;
    }
  }

  return risultato; /* restituisco il risultato della verifica */
}
