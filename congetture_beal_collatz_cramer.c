/****************************************************************/
/* Esame PP-PPL-PE_PPro-PLPr-CPro 2022/2023			*/
/*								*/
/* Programma per testare le congetture di Beal, Collatz, Cramèr */
/*								*/
/* Autori: Papadopol Lucian Ioan 	Matricola: 320648	*/
/* 	   Spaccamiglio Luca			   329999	*/
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

/******************************/
/* Definizione delle funzioni */
/******************************/

/* Definizione della funzione main */
int main(void)
{
  /* dichiarazione delle variabili locali alla funzione */
  int congettura; /* input: selezione congettura */

  /* visualizzazione interfaccia menù di scelta */
  printf("Quale congettura vuoi considerare?\n"
         "-Digita 1 per la congettura di Beal\n"
         "-Digita 2 per la congettura di Collatz\n"
         "-Digita 3 per la congettura di Cramer\n");

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
  int n;                   /* input: numero naturale */
  int esito_lettura,       /* lavoro: esito della scanf */
      acquisizione_errata; /* lavoro: esito complessivo dell’acquisizione_errata */

  /* acquisire un numero 'n > 0' */
  do
  {
    printf("inserire un numero magggiore di 0: \n");
    esito_lettura = scanf("%d",
                          &n);
    acquisizione_errata = esito_lettura != 1 || n <= 0;
    if (acquisizione_errata)
      printf("Valore non accettabile! \n");
    while (getchar() != '\n')
      ;
  } while (acquisizione_errata);

  /* stampare il numero se il suo valore è 1 */
  if (n == 1)
    printf("%d", n);

  /* calcolare il valore del numero fino al raggiungimento del valore 1 */
  else
  {
    printf("numeri generati:");
    do
    {
      if (n % 2 == 0)
        n = n / 2;
      else
        n = (n * 3) + 1;

      /* stampare ogni numero ottenuto dai calcoli */
      printf("\n%d",
             n);
    } while (n != 1);
  }
  return (0);
}

/* Definizione della funzione per la verifica se un numero è primo */
int verifica_primi(unsigned long int numero) /* input:  valore da verificare */
{
  /* dichiarazione delle variabili locali alla funzione */
  unsigned long int loop; /* lavoro: controllo ciclo */
  int risultato = 1;      /* output: inizializzo a '1' */

  for (loop = 2; loop < numero; loop++)
  { /* ciclo di verifica se un primo è effettivamente tale */
    if ((numero % loop) == 0)
    {
      risultato = 0;
    }
  }

  return risultato; /*restituisco il risultato della verifica */
}
