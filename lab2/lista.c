#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
void inicializa_lista(Lista *ap_lista){
	Lista head=(Lista)malloc(sizeof(No));
	head->prox=head;
	head->antec=head;
	*ap_lista=head;
}

void insere_fim(Lista ap_lista,	TipoDado valor){
	Lista novo=(Lista)malloc(sizeof(No));
	novo->valor=valor;
	novo->prox=ap_lista;
	novo->antec=ap_lista->antec;
	ap_lista->antec->prox=novo;
	ap_lista->antec=novo;
	if(ap_lista->prox==ap_lista){ap_lista->prox=novo;}
}

void insere_inicio(Lista ap_lista,TipoDado valor){
	Lista novo=(Lista)malloc(sizeof(No));
	novo->valor=valor;
	novo->antec=ap_lista;
	novo->prox=ap_lista->prox;
	ap_lista->prox->antec=novo;
	ap_lista->prox=novo;
	if(ap_lista->antec==ap_lista){
		ap_lista->antec=novo;
	}
}

TipoDado remove_fim(Lista ap_lista){
	TipoDado valor;
	if(ap_lista->prox==ap_lista||ap_lista->antec==ap_lista){
		valor.grau=-1;
		valor.coef=-1;
		return valor;
	}
	Lista aux;
	aux=ap_lista->antec;
	aux->antec->prox=aux->prox;
	ap_lista->antec=aux->antec;
	valor=aux->valor;
	free(aux);
	return valor;
}
TipoDado remove_inicio(Lista ap_lista){
	TipoDado valor;
	if(ap_lista->prox==ap_lista||ap_lista->antec==ap_lista){
		valor.grau=-1;
		valor.coef=-1;
		return valor;
	}
	Lista aux;
	aux=ap_lista->prox;
	aux->prox->antec=ap_lista;
	ap_lista->prox=aux->prox;
	valor=aux->valor;
	free(aux);
	return valor;
}

int remove_ocorrencias(Lista ap_lista,TipoDado valor){
	Lista aux=ap_lista,rem;
	int counter=0;
	while(aux->prox!=ap_lista){
		while(aux->prox!=ap_lista&&aux->prox->valor.coef==valor.coef&&aux->prox->valor.grau==valor.grau){
			counter++;
			rem=aux->prox;
			aux->prox=rem->prox;
			rem->prox->antec=aux;
			aux=rem->prox;
			free(rem);
		}
		aux=aux->prox;
	}
	return counter;
}

int busca(Lista lista,TipoDado valor){
	Lista aux=lista;
	int counter=0;
	while(aux->prox!=lista){
		if(aux->prox->valor.coef==valor.coef&&aux->prox->valor.grau==valor.grau){
			return counter;
		}	
		aux=aux->prox;
		counter++;
	}
	return -1;
}
int coeficiente_do_grau(Lista lista,int grau)
{
	Lista aux=lista;
	while(aux->prox!=lista){
		if(aux->prox->valor.grau==grau){
			return aux->prox->valor.coef;
		}
		aux=aux->prox;
	}
	return 0;
}

void imprime(Lista lista){
	if(lista->prox==lista){printf("[]\n");return;}
	Lista aux=lista->prox;
	printf("[");
	while(aux->prox!=lista){
		printf("(%d,%d),",aux->valor.grau,aux->valor.coef);
		aux=aux->prox;
	}
	printf("(%d,%d)]\n",aux->valor.grau,aux->valor.coef);
	return;
}

void desaloca_lista(Lista *ap_lista){
	Lista rem,aux=(*ap_lista)->antec;
	while(aux!=*ap_lista){
		rem=aux;
		aux=aux->antec;
		free(rem);
	}	
	free(aux);
	return;
}

