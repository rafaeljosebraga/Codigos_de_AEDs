#include <stdio.h>
#include <stdlib.h>
//void insere(int *heap,int tam,int val){
//	realloc()
//	tam++;
	
int main(){
	int *heap;
	int tam;
	//init-heap
	tam=1;
	*heap=(int*)malloc(sizeof(int));
	
	heap[0]=60;
	tam++;
	*heap=(int*)realloc(sizeof(int)*tam,);
	heap[1]=10;
	for(int x=0;x<=tam;x++){
		printf("%d",heap[x]);
	}

