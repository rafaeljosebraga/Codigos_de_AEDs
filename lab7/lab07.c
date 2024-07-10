#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//Pilha
descobre_op(int x){
	switch(x)
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
}
typedef struct{
	int val;
	char op;//to-be-altered
	bool Num;
}Tdado;
typedef struct no_auxp{
	Tdado val;
	struct no_auxp *prox;
}Nopil;

typedef Nopil *Pil;
//Arvore
typedef struct no_auxa{
	Tdado val;
	struct no_auxa *dir;
	struct no_auxa *esq;
}Noarv;

typedef Noarv *Arv;

void insere_pil(Pil *no_pil,Tdado x){
	Pil novo=(Pil)malloc(sizeof(Nopil));
	novo->val=x;
	novo->prox=(*no_pil)->prox;
	(*no_pil)->prox=novo;
}

bool remove_pil(Pil *no_pil){
	if((*no_pil)->prox==NULL){
		return false;
	}
	Pil rem=(*no_pil)->prox;
	(*no_pil)->prox=(*no_pil)->prox->prox;
	free(rem);
	return true;
}

Arv *cresce_folha(Tdado x){
	Arv novo=(Arv)malloc(sizeof(Noarv));
	novo->dir=novo->esq=NULL;
	novo->val=x;
	return &novo;
}
Tdado busca_pil(Pil *no_pil){
	return = (*no_pil)->prox->val;
}
Arv *cria_galho(Arv *pon_arv,Pil *pon_pil){
	if(*pon_pill==NULL){
		return NULL;
	}
	Tdado dir;
	Arv novo=(Arv)malloc(sizeof(Noarv));
	novo->dir=cresce_folha(busca_pil(*pon_pil));
	remove_pil(*pon_pil);
	novo->val=busca_pil(*pon_pil);
	switch(novo->val){
		case '%':
			break;
		case '+':
		case '-':

			break;
		case '/':
		case '*':
			break;
		
	}
}
void main(){
	Arv arvere=NULL;
	Tdado aux;
	Pil pil;
	Tdado opera,numero;
	char operador[2];
	int x=0;
	scanf("%d",&x);
	while(2==scanf("%s %d",operador,&x)){
		opera.op=operador;opera.Num=false;
		numero.val=x;numero.Num=true
	insere_pil(pil,numero);
	insere_pil(pil,opera);
	}
	
	//while(remove_pil(&pil)==true){}//O tomba pilhas
}
	
			
