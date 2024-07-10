#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"
Arvore cria_folha(int x){
	Arvore novo;
	novo=(Arvore)malloc(sizeof(No));
	novo->esq=NULL;
	novo->dir=NULL;
	novo->valor=x;
	return novo;
}

bool insere(Arvore* ap_arv, int x){
	if(*ap_arv==NULL){
		*ap_arv=cria_folha(x);
		return true;
	}
	if(x==(*ap_arv)->valor){
		return false;
	}
	if(x>(*ap_arv)->valor)
		return insere(&((*ap_arv)->dir),x);
	else 
		return insere(&((*ap_arv)->esq),x);
}
int maximo(No *arv){
	if((arv)->dir==NULL)return (arv)->valor;
	return maximo((arv)->dir);
}
bool remove_(Arvore* ap_arv, int x){
	if(*ap_arv==NULL)return false;
	if(x<((*ap_arv)->valor)){
		//printf("no_at%d x=%d\n",(*ap_arv)->valor,x);
		return remove_(&((*ap_arv)->esq),x);
	}else if(x>((*ap_arv)->valor)){
		//printf("no_at%d x=%d\n",(*ap_arv)->valor,x);
		return remove_(&((*ap_arv)->dir),x);
	}
	if((*ap_arv)->esq==NULL&&(*ap_arv)->dir==NULL){
		Arvore rem=(*ap_arv);
		*ap_arv=NULL;
		free(rem);
		return true;

	}else if((*ap_arv)->esq==NULL||(*ap_arv)->dir==NULL){
		//No *fil=((*ap_arv)->esq==NULL?(*ap_arv)->dir : (*ap_arv)->esq);
		Arvore fil;
		if((*ap_arv)->esq==NULL){
			(fil)=((*ap_arv)->dir);
		}else{
			(fil)=((*ap_arv)->esq);
		}
		No* rem=(*ap_arv);
		(*ap_arv)=fil;
		free(rem);
		return true;
	}else{
		int val_max_esq=maximo((*ap_arv)->esq);
		(*ap_arv)->valor=val_max_esq;
		remove_(&((*ap_arv)->esq),val_max_esq);
}
return true;
}

bool busca(Arvore arv, int x){
	if(arv==NULL){
		return false;
	}

	if(arv->valor==x){
		return true;
	}
	
	if(arv->valor<x)
		return busca(arv->dir,x);
	else
		return busca(arv->esq,x);
}
	
void imprime_rec(Arvore arv) {
  if (arv == NULL) {
    printf(".");
    return;
  }
  printf("[%d:e=", arv->valor);
  imprime_rec(arv->esq);
  printf(",d=");
  imprime_rec(arv->dir);
  printf("]");
}
/** Imprime a árvore de busca binária */
void imprime(Arvore arv) {
  imprime_rec(arv);
  printf("\n");
}		
		


