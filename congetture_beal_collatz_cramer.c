/****************************************************************/
/* Esame PP-PPL-PE_PPro-PLPr-CPro 2022/2023			                */
/*								                                              */
/* Programma per testare le congetture di Beal, Collatz, Cramèr */
/*								                                              */
/* Autori: Papadopol Lucian Ioan 	Matricola: 320648	            */
/* 	       Spaccamiglio Luca			           329999             */
/****************************************************************/

/*****************************/
/* Inclusione delle librerie */
/*************************** */

#include <stdio.h>
#include <math.h>

/********************************/
/* Dichiarazione delle funzioni */
/****************************** */

int congettura_beal(void);
int congettura_collatz(void);
int congettura_cramer(void);
int verifica_nprimo(unsigned long int);

/******************************/
/* Definizione delle funzioni */
/******************************/

/* definizione della funzione main */
int main(void)
{
  /* dichiarazione delle variabili locali alla funzione */
  int scelta_congettura,        /* input: selezione congettura */
      esito_acquisizione;       /* lavoro: esito della scanf */

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

    /* acquisizione scelta e validazione stretta*/
    esito_acquisizione = scanf("%d",
                          &scelta_congettura);
    esito_acquisizione = esito_acquisizione != 1 || scelta_congettura > 3 || scelta_congettura <= 0;
    if (esito_acquisizione)
      printf("Valore non accettabile! \n \n");
    while (getchar() != '\n');
  } while (esito_acquisizione);

  /* struttura di selezione della congettura*/
  switch (scelta_congettura)
  {
  case 1:
    congettura_beal();
    break;
  case 2:
    congettura_collatz();
    break;
  case 3:
    congettura_cramer();
    break;
  }
  return (0);
}

/* definizione della funzione per verificare la congettura di Beal */
int congettura_beal(void)
{
  int parametro_equazione[5],  /* array parametri della equazione*/
      esito_lettura,          /* lavoro: esito della scanf */
      risultato = 0,
      loop_primi = 2,
      loop_input,
      lettere[6] = {'a',      /* output: array messaggi per input variabili corrispondenti */
                    'b',
                    'c',
                    'x',
                    'y',
                    'z'}; 
  unsigned long int a_esponentex,
                    b_esponentey,
                    c_esponentez;

/* Banner esplicativo dei parametri da inserire*/
printf("------------------------\n"
      "Equazione a^x + b^y = c^z\n"
      "-------------------------\n");
    
/* acquisire parametri a,b,c,x,y,z e validazione stretta */
  for (loop_input = 0; loop_input < 6; loop_input++)
  { 
    do
    {
      if (loop_input <= 2 )
        printf("Digita valore letterale %c >= 1: ",
               lettere[loop_input]);
      else
        printf("Digita esponente %c >= 3: ",
               lettere[loop_input]);
      esito_lettura = scanf("%d",
                            &parametro_equazione[loop_input]);
      if (loop_input == 0 || loop_input <= 2)
        esito_lettura = esito_lettura != 1 || parametro_equazione[loop_input] < 1;
      else
        esito_lettura = esito_lettura != 1 || parametro_equazione[loop_input] < 3;
      if (esito_lettura)
        printf("Valore non accettabile! \n");
      while (getchar() != '\n');
    } while (esito_lettura);
  }

  /* esegui i calcoli */
  a_esponentex = pow(parametro_equazione[0], parametro_equazione[3]);
  b_esponentey = pow(parametro_equazione[1], parametro_equazione[4]);
  c_esponentez = pow(parametro_equazione[2], parametro_equazione[5]);

  if (a_esponentex + b_esponentey == c_esponentez)
  {
    printf("Equazione a^x + b^y = c^z verificata");
  }
  else
  {
    while (a_esponentex >= loop_primi && b_esponentey >= loop_primi && c_esponentez >= loop_primi)
    {
      if (a_esponentex % loop_primi == 0 && b_esponentey % loop_primi == 0 && c_esponentez % loop_primi == 0)
      {
        a_esponentex /= loop_primi;
        b_esponentey /= loop_primi;
        c_esponentez /= loop_primi;
        risultato++;
      }
      else
        loop_primi++;
    }

    /* avviso l'utente dell'esito */
    printf("Equazione a^x + b^y = c^z non verificata per i parametri inseriti.\n"
           "Vi sono %d numeri primi in comune\n",
           risultato);
  }
  return (0);
}

/* definizione della funzione per verificare la congettura di Collatz */
int congettura_collatz(void)
{
  /* dichiarazione delle variabili locali alla funzione */
  unsigned long int numero_in;        /* input: numero naturale scelto dall'utente*/
  int esito_lettura;                  /* lavoro: esito della scanf */

  /* acquisizione numero da testare e validazione stretta*/
  do
  {
    printf("Inserire un numero 'n' intero > 0: \n");
    esito_lettura = scanf("%lu",
                          &numero_in);
    esito_lettura = esito_lettura != 1 || numero_in <= 0;
    if (esito_lettura)
      printf("Valore non accettabile! \n");
    while (getchar() != '\n');
  } while (esito_lettura);

  /* stampare il numero se il suo valore è 1 */
  if (numero_in == 1)
    printf("%lu", numero_in);

  /* calcolare il valore del numero fino al raggiungimento del valore 1 */
  else
  {
    printf("Numeri generati:\n"     /* Banner evocativo con separatore */
           "----------------\n");
    do
    {
      if (numero_in % 2 == 0)
        numero_in = numero_in / 2;
      else
        numero_in = (numero_in  * 3) + 1;

      /* stampare ogni numero ottenuto dai calcoli */
      printf("\n%lu",numero_in);
    } while (numero_in != 1);

    /* avviso l'utente dell'esito */
    printf("\n"); /* vado a capo dalla lista dei numeri generati */
    printf("Ho raggiunto n == 1\n");
  }
  return (0);
}

/* Definizione della funzione per verificare la congettura di Collatz */
int congettura_cramer(void)
{
return(0);
}

/* Definizione della funzione per la verifica se un numero è primo */
int verifica_nprimo(unsigned long int numero_in) /* input:  valore da verificare */
{
  /* dichiarazione delle variabili locali alla funzione */
  unsigned long int i;    /* lavoro: controllo ciclo */
  int risultato = 1;      /* output: variabile risultato della verifica inizializzo a '1' ovvero 'è primo' */

  /* ciclo di verifica se un primo è effettivamente tale */
  for (i = 2; i < numero_in; i++)
  {
    if ((numero_in % i) == 0)
    {
      risultato = 0;  /* non è primo*/
    }
  }

  /* restituisco il risultato della verifica */
  return risultato; 
}
