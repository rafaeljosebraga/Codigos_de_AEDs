#include <stdio.h>
#include <stdlib.h>
#include "polinomio.h"

void aloca(Polinomio *alocando,int grau,int coef){
	(*alocando)=(Polinomio)malloc(sizeof(No));
	(*alocando)->antec=(*alocando);
	(*alocando)->prox=(*alocando);
	(*alocando)->valor.coef=coef;
	(*alocando)->valor.grau=grau;
}
/* Inicializa um polinômio vazio. */
void inicializa_polinomio(Polinomio * ap_pol){
	*ap_pol=(Polinomio)malloc(sizeof(No));
	(*ap_pol)->prox=*ap_pol;
	(*ap_pol)->antec=*ap_pol;
}

/* Define que o coeficiente de grau grau do polinomio pol eh igual a coef. Deve manter os 
 * coeficientes ordenados por grau. */
void define_coeficiente(Polinomio pol, int grau, int coef){
	if(coef==0){return;}
	Polinomio aux=pol,novo;
	if(pol->prox==pol){
		aloca(&novo,grau,coef);
		pol->prox=novo;
		pol->antec=novo;
		novo->prox=pol;
		novo->antec=pol;
	}
	while(aux->prox!=pol){
		if (aux->prox->valor.grau==grau){
			aux->prox->valor.coef=coef;
			return;
		}
		aux=aux->prox;
	}
	aloca(&novo,grau,coef);
	aux->prox=novo;
	novo->antec=aux;
	novo->prox=pol;
	pol->antec=novo;
	return;
}

/* Imprime o polinomio pol no formato do exemplo abaixo
 * [(0,2),(3,-2),(10,5)]
 * onde este polinomio tem 3 coeficientes, o de grau 0 com valor 2, o de grau 3 com valor -2 e o de
 * grau 10 com valor 5. 
 */
void imprime(Polinomio pol){
	Polinomio aux=pol->prox;
	printf("[");
	while(aux->prox!=pol){
		printf("(%d,%d),",aux->valor.grau,aux->valor.coef);
		aux=aux->prox;
	}

	if(aux!=pol){
		printf("(%d,%d)",aux->valor.grau,aux->valor.coef);
	}
	printf("]\n");
	return;
}

/* Desaloca toda a memória alocada da lista.
*/
void desaloca_polinomio(Polinomio *ap_pol){
	Polinomio aux=(*ap_pol)->prox,rem;
	while(aux!= *ap_pol){
		rem=aux;
		aux=aux->prox;
		free(rem);
	}
	free(aux);
	*ap_pol=NULL;
	return;
}

/* Zera o polinomio, tornando-o um polinomio inicializado, mas igual a zero. Desaloca a memória liberada. */
void zera(Polinomio pol){
	Polinomio aux=pol->prox,rem;
	while(aux!=pol){
		rem=aux;
		free(rem);
		aux=aux->prox;
	}
	pol->prox=pol;
	pol->antec=pol;
	return;
}
void insere_prox(Polinomio *atualC,int grau,int coef){
	Polinomio novo;
	aloca(&novo,grau,coef);
	(*atualC)->prox=novo;
	novo->antec=*atualC;
	*atualC=(*atualC)->prox;
}
/* Computa a soma dos polinomios a e b colocando o resultado em res. 
 * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void soma(Polinomio res, Polinomio a, Polinomio b){
	int ABvalor = 0;
	Polinomio auxA=a->prox,auxB=b->prox,atualC=res;
	while(auxB!=b&&auxA!=a){
		if(auxB->valor.grau==auxA->valor.grau){
			ABvalor=(auxA->valor.coef+auxB->valor.coef);
			if(ABvalor==0){
				auxA=auxA->prox;
				auxB=auxB->prox;
				continue;
			}
			insere_prox(&atualC,auxB->valor.grau,ABvalor);
			auxB=auxB->prox;
			auxA=auxA->prox;
			continue;
		}
		if(auxA->valor.grau>auxB->valor.grau){
			insere_prox(&atualC,auxB->valor.grau,auxB->valor.coef);
			auxB=auxB->prox;
		}else{
			insere_prox(&atualC,auxA->valor.grau,auxA->valor.coef);
			auxA=auxA->prox;
		}
	}
	if(auxA==a){
		while(auxB!=b){
			insere_prox(&atualC,auxB->valor.grau,auxB->valor.coef);

			auxB=auxB->prox;
		}
	}else{
		while(auxA!=a){
			insere_prox(&atualC,auxA->valor.grau,auxA->valor.coef);
			auxA=auxA->prox;
		}
	}
	atualC->prox=res;
	res->antec=atualC;
	return;
}

/* Computa a subtracao dos polinomios a e b colocando o resultado em res. 
 * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void subtrai(Polinomio res, Polinomio a, Polinomio b){
	int ABvalor = 0;
	Polinomio auxA=a->prox,auxB=b->prox,atualC=res;
	while(auxB!=b&&auxA!=a){
		if(auxB->valor.grau==auxA->valor.grau){
			ABvalor=(auxA->valor.coef-auxB->valor.coef);
			if(ABvalor==0){
				auxA=auxA->prox;
				auxB=auxB->prox;
				continue;
			}
			insere_prox(&atualC,auxB->valor.grau,ABvalor);
			auxB=auxB->prox;
			auxA=auxA->prox;
			continue;
		}
		if(auxA->valor.grau>auxB->valor.grau){
			insere_prox(&atualC,auxB->valor.grau,-auxB->valor.coef);
			auxB=auxB->prox;
		}else{
			insere_prox(&atualC,auxA->valor.grau,auxA->valor.coef);
			auxA=auxA->prox;
		}}
	if(auxA==a){
		while(auxB!=b){
			insere_prox(&atualC,auxB->valor.grau,-auxB->valor.coef);
			auxB=auxB->prox;
		}
	}else{
		while(auxA!=a){
			insere_prox(&atualC,auxA->valor.grau,auxA->valor.coef);
			auxA=auxA->prox;
		}
	}
	atualC->prox=res;
	res->antec=atualC;
	return;
}
