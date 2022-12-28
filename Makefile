# Makefile congetture_beal_collatz_cramer #

congetture_beal_collatz_cramer: congetture_beal_collatz_cramer.c Makefile
		gcc -ansi -Wall -O congetture_beal_collatz_cramer.c -o congetture_beal_collatz_cramer -lm

pulisci:
		rm -f congetture_beal_collatz_cramer.o

pulisci_tutto:
		rm -f congetture_beal_collatz_cramer congetture_beal_collatz_cramer.o