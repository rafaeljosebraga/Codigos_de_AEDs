#include <stdio.h>
#include "lista.h"
#include <stdlib.h>

/* Inicializa a lista como lista vazia. */
void inicializa_lista(Lista * ap_lista) {
	*ap_lista=NULL;
}

/* Insere valor no fim da lista apontada por ap_lista. ap_lista aponta para o inicio da lista. */
void insere_fim(Lista * ap_lista, int valor) {
	Lista novo=(No*)malloc(sizeof(No));
	novo->valor=valor;
	if(*ap_lista==NULL)
	{	
		novo->proximo=NULL;
		*ap_lista=novo;
		return;
	}
	Lista aux=*ap_lista;
	while(aux->proximo !=NULL)
	{
		aux=aux->proximo;
	}
	aux->proximo=novo;
	novo->proximo=NULL;
}

/* Insere valor no inicio da lista apontada por ap_lista. */
void insere_inicio(Lista * ap_lista, int valor){
	Lista novo=(Lista)malloc(sizeof(No));
	novo->proximo=*ap_lista;
	novo->valor=valor;
	*ap_lista=novo;
}

/* Remove valor do fim da lista apontada por ap_lista e retorna este valor. */
int remove_fim(Lista * ap_lista){
	if(*ap_lista==NULL){return -1;}
	if((*ap_lista)->proximo==NULL)
	{
		int x=(*ap_lista)->valor;
		free (*ap_lista);
		*ap_lista=NULL;
		return x;
	}
	Lista aux,rem=*ap_lista;
	while(rem->proximo!=NULL){
		aux=rem;
		rem=rem->proximo;
	}
	int val=rem->valor;
	free(rem);
	aux->proximo=NULL;
	return val;
}

/* Remove valor do inicio da lista apontada por ap_lista e retorna este valor. */
int remove_inicio(Lista * ap_lista) {
	if(*ap_lista==NULL){
		return -1;
	}
	Lista rem=*ap_lista;
	int val=rem->valor;
	*ap_lista=rem->proximo;
	free(rem);
	return val;
}


/* Remove todas as ocorrencias de valor da lista apontada por ap_lista. 
 * Retorna o numero de ocorrencias removidas.
 */
int remove_ocorrencias(Lista *ap_lista, int valor){
	if(*ap_lista==NULL)
	{
	return 0;
	}
	Lista aux=*ap_lista;
	int x=0;
	while(*ap_lista!=NULL&&(*ap_lista)->valor==valor)
	{
		*ap_lista=(*ap_lista)->proximo;
		free(aux);
		aux=*ap_lista;
		x++;
	}
	Lista rem;
	if(*ap_lista==NULL)
	{
	return x;
	}
	while(aux->proximo!=NULL)
	{
//fprintf(stderr,"erro A:%p %p\n",(void*)aux,(void*)aux->proximo);
		if(aux->proximo->valor==valor)
		{
//fprintf(stderr,"erro B:%p %p\n",(void*)aux,(void*)aux->proximo);
		x++;
		rem=aux->proximo;
		aux->proximo=aux->proximo->proximo;
		free(rem);
		continue;
		}
		aux=aux->proximo;
//fprintf(stderr,"erro C:%p %p\n",(void*)aux,(void*)aux->proximo);
	}
	return x;
}
/* Busca elemento valor na lista. 
   Retorna a posição na lista, comecando de 0=primeira posicao.
   Retorna -1 caso nao encontrado.
   */
int busca(Lista lista, int valor) {
	int x;
	for(x=0;lista!=NULL;x++){
		if(lista->valor==valor){return x;}
		lista=lista->proximo;
	}
	return -1;
}

/* Imprime a lista na saida padrao, no formato:
   (1,3,2,3,4,2,3,1,4)
   em uma linha separada.
   */
void imprime(Lista lista){
	printf("(");
	while(lista!=NULL)
	{
		if(lista->proximo==NULL)
		{
			printf("%d",lista->valor);
		}else
		{
			printf("%d,",lista->valor);
		}
		lista=lista->proximo;
	}
	printf(")\n");
	return;
}

/* Desaloca toda a memória alocada da lista.
*/
void desaloca_lista(Lista *ap_lista) {
	Lista rem;
	while(*ap_lista!=NULL)
	{
		rem=*ap_lista;
		*ap_lista=(*ap_lista)->proximo;
		free(rem);
	}
}


/* Remove o i-ésimo elemento da lista, caso ele exista. Retorna se o elemento 
   foi removido. As posições são contadas a partir de 1, sendo 1 a primeira posição. */
bool remove_i_esimo(Lista * ap_lista, int i) {
	if(*ap_lista==NULL){return false;}
	Lista aux=*ap_lista;
	if(i==1){
		*ap_lista=aux->proximo;
		free (aux);
		return true;
	}
	int x=2;
	while(aux->proximo!=NULL&&x!=i)
	{
		aux=aux->proximo;
		x++;
	}
	if(aux->proximo==NULL)
	{
	return false;
	}
	Lista rem=aux->proximo;
	aux->proximo=rem->proximo;
	free(rem);
	return true;
}

/* Retorna o valor do i-ésimo elemento da lista, caso ele exista. 
   Retorna -1 caso contrário. As posições são contadas a partir de 1, sendo 1 a primeira posição. */
int recupera_i_esimo(Lista lista, int i) {
	if(lista==NULL){return -1;}
	if(i==1){return lista->valor;}
	int x=2;
	while(lista->proximo!=NULL&&x!=i){x++;lista=lista->proximo;}
	if(lista->proximo==NULL){return -1;}
	return lista->proximo->valor;
}

/* Retorna o tamanho da lista. */
int tamanho(Lista lista) {
	int x;
	for(x=0;lista!=NULL;x++)
	{
		lista=lista->proximo;
	}
	return x;
}

