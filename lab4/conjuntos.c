#include <stdio.h>
#include <stdlib.h>
typedef long long int conjunto;
typedef struct {
	conjunto conj;
	int tam;
}grupoConj;


void insere(conjunto *conj,int x){
	(*conj)=(*conj)|(1<<x);
	return;
}

conjunto onion(conjunto conjA,conjunto conjB){
	conjunto conjR=(conjA|conjB);
	return conjR;
}

conjunto intersecao(conjunto conjA,conjunto conjB){
	conjunto conjR=(conjA&conjB);
	return conjR;
}
void imprime(conjunto conj,int quant_elem)
{
	for(int counter=0;counter<quant_elem;counter++){
		if(intersecao(conj,(1<<counter))>0){
			printf("%d",counter);
		}
	}
	printf("\n");
}
/*
int verif_repeticao(conjunto conjA,conjunto conjB,int quant_elem){
	int counter=0;
*/

if((A&B)==0){
	A=onion(A,B);
}

conjunto findConj(conj *grupo_conj,conj targ,conj ant,conj atual,int quant_subconj,int counter){
	if(counter==quant_subconj){
		return -1;
	}
	
	if((atual|grupo_conj[counter])==targ){
		return (atual|grupo_conj[counter]);
	}
	return findConj(*grupo_conj,targ,ant,(atual|*grupo_conj[counter]),quant_subconj,counter+1);
}
int main(){
	//Declarações
	int counter=0,quant_elem,quant_subconj,tam_subconj;
	int pivot;
	scanf("%d",&quant_elem);
	//Criando conjunto universo
	conjunto U=0;
	
	for(;counter<quant_elem;counter++){
		insere(&U,counter);
	}
	//Recebendo entradas
	scanf("%d",&quant_subconj);
	grupoConj x[quant_subconj];
	counter=0;
	for(;counter<quant_subconj;counter++){
		scanf("%d",&tam_subconj);
		x[counter].tam=pivot;
		x[counter].conj=0;
		for(int counter2=0;counter2<tam_subconj;counter2++){
			scanf("%d",&pivot);
			insere(&x[counter].conj,pivot);
		}
	imprime(x[counter].conj,quant_elem);
	}
	return 0;
}

