#include<stdio.h>
#include<stdlib.h>
#include "lista.h"




/* Inicializa a lista como lista vazia. */
void inicializa_lista(Lista * ap_lista){
  Lista cabeca= (Lista)malloc(sizeof (No));
  (cabeca)->prox=cabeca;
  (cabeca)->antec=cabeca;




  *ap_lista=cabeca;
}
/* Insere valor no fim da lista apontada por ap_lista. ap_lista aponta para o no cabeca da lista. */
void insere_fim(Lista ap_lista, TipoDado valor){
  Lista novo= (Lista)malloc(sizeof (No));
  Lista final= (ap_lista)->antec;
     novo->valor=valor;
     novo->prox=ap_lista;
     novo->antec=final;
     ap_lista->antec=novo;
     final->prox=novo;
}
/* Imprime a lista na saida padrao, no formato:
 [(1,3),(2,3),(4,2),(3,1),(4,17)]
 em uma linha separada. */
void imprime(Lista lista){
  if(lista->prox==lista){
     printf("[]\n");
     return;
  }
  printf("[");
  Lista atual=lista->prox;
  while(atual!=lista)
  {
     printf("(%d,%d)",atual->valor.grau,atual->valor.coef);
     if(atual->prox!=lista){
        printf(",");
     }
     atual=(atual)->prox;
  }
     printf("]\n");
}
/* Insere valor no inicio da lista apontada por ap_lista. ap_lista aponta para o no cabeca da lista. */
void insere_inicio(Lista ap_lista, TipoDado valor){
  Lista primeiro= ap_lista->prox;
  Lista novo=(Lista)malloc(sizeof (No));
  novo->valor=valor;
  novo->prox=primeiro;
  novo->antec=ap_lista;
  ap_lista->prox=novo;
  primeiro->antec=novo;
}
/* Remove valor do fim da lista apontada por ap_lista e retorna este valor. */
TipoDado remove_fim(Lista ap_lista){
  Lista ultimo=ap_lista->antec;
  Lista penultimo=ultimo->antec;
  TipoDado resposta;
  penultimo->prox= ap_lista;
  ap_lista->antec= penultimo;
  resposta.coef= ultimo->valor.coef;
  resposta.grau= ultimo->valor.grau;
  free(ultimo);
  return resposta;
}
/* Remove valor do inicio da lista apontada por ap_lista e retorna este valor. */
TipoDado remove_inicio(Lista ap_lista){
  Lista primeiro=ap_lista->prox;
  Lista segundo=primeiro->prox;
  TipoDado resposta;
  segundo->antec=ap_lista;
  ap_lista->prox=segundo;
  resposta.coef=primeiro->valor.coef;
  resposta.grau=primeiro->valor.grau;
  free(primeiro);
  return resposta;
}
/* Remove todas as ocorrencias de valor da lista apontada por ap_lista.
* Retorna o numero de ocorrencias removidas. */
int remove_ocorrencias(Lista ap_lista, TipoDado valor){
  Lista atual=ap_lista->prox;
  Lista anterior;
  Lista seguinte;
  int contador=0;
  while (atual!=ap_lista)
  {
     if(atual->valor.grau==valor.grau && atual->valor.coef==valor.coef){
        anterior=atual->antec;
        seguinte=atual->prox;
        anterior->prox=seguinte;
        seguinte->antec=anterior;
        free(atual);
        contador++;
        atual=seguinte;
     }
     else atual=atual->prox;
  }
  return contador;
}
/* Busca elemento valor na lista.
  Retorna a posição da primeira ocorrencia de valor na lista, comecando de 0=primeira posicao.
  Retorna -1 caso nao encontrado. */
int busca(Lista lista, TipoDado valor){
  Lista atual= lista->prox;
  int posicao=0;
  while (atual!=lista)
  {
     if(atual->valor.grau==valor.grau && atual->valor.coef==valor.coef){
        return posicao;
     }
     atual=atual->prox;
     posicao++;
  }
  return -1;
}
/* Retorna o campo coef do primeiro no que contenha grau igual ao parametro grau,
  e 0 (zero) caso nao encontre um tal no.  */
int coeficiente_do_grau(Lista lista, int grau){
  Lista atual= lista->prox;
  while (atual!=lista)
  {
     if(atual->valor.grau==grau){
        return  atual->valor.coef;
     }
     atual=atual->prox;
  }
  return 0;
}
/* Desaloca toda a memória alocada da lista.
*/
void desaloca_lista(Lista *ap_lista){
  Lista atual= (*ap_lista)->prox;
  while (atual!=*ap_lista)
  {
     Lista remove= atual;   
     atual=atual->prox;
     free (remove); 
  }
  free (*ap_lista);
}
////////////////////////////////////////////////////////////////////////////////































