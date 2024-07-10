#include <stdio.h>
#include <stdlib.h>

typedef struct no_aux{
	int val;
	int col;
	int lin;
	no_aux *up;
	no_aux *dawn;
	no_aux *left;
	no_aux *right;
}No;

typedef No *Matrice;

void create_matrice(Matrice *mat){



