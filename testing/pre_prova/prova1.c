#include<stdio.h>
#include<stdlib.h>

typedef struct no_aux{
	struct no_aux* next;
	int value;
}No;
typedef No *Lst;

void iniciate_list(Lst *head){
	*head=(Lst)malloc(sizeof(No));
	(*head)->next=NULL;
	return;
}

void insert_start(Lst *head,int x){
	Lst new=(Lst)malloc(sizeof(No));
	new->value=x;
	new->next=(*head)->next;
	(*head)->next=new;
	printf("inserido\n");
	return;
}

void remove_start(Lst *head){
	Lst rem=(*head)->next;
	(*head)->next=rem->next;
	free(rem);
	return;
}

void list_print(Lst listAux){
		listAux=listAux->next;
	while(listAux){
		printf("(%d) ",listAux->value);
		listAux=listAux->next;
	}
	return;
}

void desaloca(Lst *head){
	Lst aux=*head,rem;
	while(aux){
		rem=aux;
		aux=aux->next;
		free(rem);
	}
	*head=NULL;
	return;
} 
int main(){
	int choice=0;
	Lst a;
	iniciate_list(&a);
	while(choice!=4){
		scanf("%d",&choice);
		if(choice==1){
			scanf("%d",&choice);
			printf("%d",choice);
			insert_start(&a,choice);
			choice=0;
			continue;
		}
		if(choice==2){
			remove_start(&a);
			continue;
		}
		if(choice==3){
			list_print(a);
			continue;
		}
	}
	desaloca(&a);
}
