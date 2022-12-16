/****************************************************************/
/* Esame PP-PPL-PE_PPro-PLPr-CPro 2022/2023		                  */
/*							                                                */
/* Programma per testare le congetture di Beal, Collatz, Cramèr */
/*							                                                */
/* Autori: Papadopol Lucian Ioan 	Matricola: 320648	            */
/* 	       Spaccamiglio Luca		             322270             */
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
int verifica_nprimo(int);

/******************************/
/* Definizione delle funzioni */
/******************************/

/* definizione della funzione main */
int main(void)
{
  /* dichiarazione delle variabili locali alla funzione */
  int scelta_congettura,   /* input: selezione congettura */
      esito_acquisizione,  /* lavoro: esito della scanf */
      acquisizione_errata; /* lavoro: esito complessivo dell' acquisizione_errata */

  /* acquisizione scelta */
  do
  {
    /* visualizzazione banner/menù di scelta */
    printf("\n PROGRAMMA DI TEST CONGETTURE DI BEAL - COLLATZ - CRAMÉR\n\n"
           "[1] Beal\n"
           "[2] Collatz\n"
           "[3] Cramér\n"
           "[4] Esci dal software\n\n"
           "Digita il numero relativo alla tua scelta e premi 'Invio'. \n");

    /* acquisizione scelta e validazione stretta*/
    esito_acquisizione = scanf("%d",
                               &scelta_congettura);
    acquisizione_errata = esito_acquisizione != 1 || scelta_congettura > 4 || scelta_congettura <= 0;
    if (acquisizione_errata)
      printf("Valore fuori range! \n");
    while (getchar() != '\n')
      ;
  } while (acquisizione_errata);

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
  case 4:
    printf("Arrivederci.\n");
    break;
  }
  return (0);
}

/* definizione della funzione per verificare la congettura di Beal */
int congettura_beal(void)
{
  int par_equ[5],          /* array parametri della equazione*/
      esito_lettura,       /* lavoro: esito della scanf */
      acquisizione_errata, /* lavoro: esito complessivo dell' acquisizione_errata */
      i_primi = 2,         /* lavoro: indice ciclo calcolo fattori primi comuni */
      i,                   /* lavoro: indice ciclo aquisizione parametri*/
      n_fprimi = 0;        /* output: esito calcolo fattori primi comuni */
  char scelta[6] = {'a',   /* output: array messaggi per input variabili corrispondenti */
                    'b',
                    'c',
                    'x',
                    'y',
                    'z'};
  long double a_esponentex,
      b_esponentey,
      c_esponentez;

  /* Banner esplicativo dei parametri da inserire*/
  printf("Equazione A^x + B^y = C^z\n\n");

  /* acquisire parametri a,b,c,x,y,z e validazione stretta */
  for (i = 0; i < 6; i++)
  {
    do
    {
      if (i <= 2)
        printf("Digita valore letterale %c ≥ 1: ",
               scelta[i]);
      else
        printf("Digita esponente %c ≥ 3: ",
               scelta[i]);
      esito_lettura = scanf("%d",
                            &par_equ[i]);
      if (i == 0 || i <= 2)
        acquisizione_errata = esito_lettura != 1 || par_equ[i] < 1;
      else
        acquisizione_errata = esito_lettura != 1 || par_equ[i] < 3;
      if (acquisizione_errata)
        printf("Valore non accettabile! \n");
      while (getchar() != '\n')
        ;
    } while (acquisizione_errata);
  }

  /* esegui il calcolo delle potenze */
  a_esponentex = pow(par_equ[0], par_equ[3]);
  b_esponentey = pow(par_equ[1], par_equ[4]);
  c_esponentez = pow(par_equ[2], par_equ[5]);

  /* calcolo quanti primi in comune vi sono tra a, b, c*/
  while (par_equ[0] >= i_primi && par_equ[1] >= i_primi && par_equ[2] >= i_primi)
  {
    if (par_equ[0] % i_primi == 0 && par_equ[1] % i_primi == 0 && par_equ[2] % i_primi == 0)
    {
      par_equ[0] /= i_primi;
      par_equ[1] /= i_primi;
      par_equ[2] /= i_primi;
      n_fprimi++;
    }
    else
      i_primi++;
  }

  /* avviso l'utente dell'esito */
  if (a_esponentex + b_esponentey == c_esponentez)
  {
    printf("\nEquazione verificata per i parametri inseriti.\n");
  }
  else
  {
    printf("\nEquazione non verificata per i parametri inseriti.\n");
  }

  /* indico all'utente quanti fattori primi in comune vi sono tra i parametri a,b,c */
  printf("Vi sono %d fattori primi in comune tra quelli dei parametri A, B e C\n\n",
         n_fprimi);
  return (0);
}

/* definizione della funzione per verificare la congettura di Collatz */
int congettura_collatz(void)
{
  /* dichiarazione delle variabili locali alla funzione */
  int numero_in;           /* input: numero naturale scelto dall'utente*/
  int esito_lettura,       /* lavoro: esito della scanf */
      acquisizione_errata; /* lavoro: esito complessivo dell' acquisizione_errata */

  /* acquisizione numero da testare e validazione stretta*/
  do
  {
    printf("Digita un numero 'n' intero > 0: \n");
    esito_lettura = scanf("%d",
                          &numero_in);
    acquisizione_errata = esito_lettura != 1 || numero_in <= 0;
    if (acquisizione_errata)
      printf("Valore fuori range! \n");
    while (getchar() != '\n')
      ;
  } while (acquisizione_errata);

  /* calcolare il valore del numero fino al raggiungimento del valore 1 */
  printf("Numeri generati:\n\n");
  do
  {
    if (numero_in % 2 == 0)
      numero_in = numero_in / 2;
    else
      numero_in = (numero_in * 3) + 1;

    /* stampare ogni numero ottenuto dai calcoli */
    printf("\n %d", numero_in);
  } while (numero_in != 1);

  /* avviso l'utente dell'esito */
  printf("\n"); /* vado a capo dalla lista dei numeri generati */
  printf("Ho raggiunto n == 1\n\n");

  return (0);
}

/* Definizione della funzione per verificare la congettura di Collatz */
int congettura_cramer(void)
{
  int esito_lettura,       /* lavoro: esito della scanf */
      acquisizione_errata, /* lavoro: esito complessivo dell' acquisizione_errata */
      i,
      differenza,
      valori[]={0,0},
      a_esito;
  double log_quadrato,
         rapporto;

  printf("\nDigita un numero primo ≥ 11 e premere 'Invio'. \n"
         "Successivamente digitare un altro numero primo consecutivo al precedente e premere 'Invio'.\n\n");

  for (i = 0; i < 2; i++)
  {
    do
    {
      esito_lettura = scanf("%d",
                            &valori[i]);
      acquisizione_errata = esito_lettura != 1 || valori[i] < 11;
      if (acquisizione_errata)
        printf("Valore fuori range! \n");
      else
      {
        a_esito = verifica_nprimo(valori[i]);
        if (a_esito == 0)
        {
          acquisizione_errata = 1;
          printf("Non è un numero primo! \n");
        }
      }
    } while (acquisizione_errata);
  }
if (valori[0] >= valori[1])
    printf("Valori non accettabili, non sono primi consecutivi.\n");
else
  {
    differenza = valori[1]-valori[0];
    printf("Differenza tra i due numeri primi: %d\n", differenza);
    log_quadrato = pow(log(valori[0]),2);
    printf("Quadrato del Logaritmo naturale del primo minore: %0.2lf\n", log_quadrato);
    rapporto = differenza/log_quadrato;
    printf("Rapporto tra la differenza dei due primi ed il quadrato del Logaritmo naturale del minore: %0.2lf\n\n", rapporto);
  }
  return (0);
}

/* Definizione della funzione per la verifica se un numero è primo */
int verifica_nprimo(int numero_in) /* input:  valore da verificare */
{
  /* dichiarazione delle variabili locali alla funzione */
  int i;             /* lavoro: controllo ciclo */
  int risultato = 1; /* output: variabile risultato della verifica inizializzo a '1' ovvero 'è primo' */

  /* ciclo di verifica se un primo è effettivamente tale */
  for (i = 2; i < numero_in; i++)
  {
    if ((numero_in % i) == 0)
    {
      risultato = 0; /* non è primo*/
    }
  }

  return risultato;
}
