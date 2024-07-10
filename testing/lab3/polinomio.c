#include <stdio.h>
#include <stdlib.h>
#include "polinomio.h"

/* Inicializa um polinômio vazio. */
void inicializa_polinomio(Polinomio * ap_pol){
    No* cab = (No*) malloc (sizeof(No));

    cab -> prox = cab;
    cab -> antec = cab;
    *ap_pol = cab;
}

/* Define que o coeficiente de grau grau do polinomio pol eh igual a coef. Deve manter os
 * coeficientes ordenados por grau. */
void define_coeficiente(Polinomio pol, int grau, int coef){
    No* novo = (No*) malloc (sizeof(No));
    No* atual = pol -> prox;
    No* antec = pol;

    if (novo) {
        novo -> valor.grau = grau;
        novo -> valor.coef = coef;

    while (atual != pol && atual -> valor.grau < grau) {
        antec = atual;
        atual = atual -> prox;
    }
    if (atual == pol || atual -> valor.grau != grau) {
        novo -> prox = atual;
        novo -> antec = antec;
        antec -> prox = novo;
        atual -> antec = novo;
    }
      else {
        atual -> valor.coef = coef;
        free(novo);
      }
    }
}

/* Zera o polinomio, tornando-o um polinomio inicializado, mas igual a zero. Desaloca a memória liberada. */
void zera(Polinomio pol){
    No* atual = pol -> prox;
    No* cab = pol;

    while (atual != cab) {
        No* aux = atual -> prox;
        free(atual);
        atual = aux;
    }
    pol -> prox = pol;
    pol -> antec = pol;
}

/* Computa a soma dos polinomios a e b colocando o resultado em res.
 * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void soma(Polinomio res, Polinomio a, Polinomio b){
    No* coef_a = a -> prox;
    No* coef_b = b -> prox;

    while(coef_a != a && coef_b != b) {
        if (coef_a -> valor.grau < coef_b -> valor.grau) {
            define_coeficiente(res, coef_a -> valor.grau, coef_a -> valor.coef);
            coef_a = coef_a -> prox;
        }
        else if (coef_a -> valor.grau > coef_b -> valor.grau) {
            define_coeficiente(res, coef_b -> valor.grau, coef_b -> valor.coef);
            coef_b = coef_b -> prox;
        }
        else {
            int soma = coef_a -> valor.coef + coef_b -> valor.coef;
            define_coeficiente(res, coef_a -> valor.grau, soma);
            coef_a = coef_a -> prox;
            coef_b = coef_b -> prox;
        }
    }
    while (coef_a != a) {
        define_coeficiente(res, coef_a -> valor.grau, coef_a -> valor.coef);
        coef_a = coef_a -> prox;
    }
     while (coef_b != b) {
        define_coeficiente(res, coef_b -> valor.grau, -(coef_b -> valor.coef));
        coef_b = coef_b -> prox;
    }
}

/* Computa a subtracao dos polinomios a e b colocando o resultado em res.
 * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void subtrai(Polinomio res, Polinomio a, Polinomio b){
    No* coef_a = a -> prox;
    No* coef_b = b -> prox;

    while(coef_a != a && coef_b != b) {
        if (coef_a -> valor.grau < coef_b -> valor.grau) {
            define_coeficiente(res, coef_a -> valor.grau, coef_a -> valor.coef);
            coef_a = coef_a -> prox;
        }
        else if (coef_a -> valor.grau > coef_b -> valor.grau) {
            define_coeficiente(res, coef_b -> valor.grau, -coef_b -> valor.coef);
            coef_b = coef_b -> prox;
        }
        else {
            int subtracao = coef_a -> valor.coef - coef_b -> valor.coef;
            if(subtracao != 0) {
            define_coeficiente(res, coef_a -> valor.grau, subtracao);
            }
            coef_a = coef_a -> prox;
            coef_b = coef_b -> prox;
        }
    }
    while (coef_a != a) {
        define_coeficiente(res, coef_a -> valor.grau, coef_a -> valor.coef);
        coef_a = coef_a -> prox;
    }
     while (coef_b != b) {
        define_coeficiente(res, coef_b -> valor.grau, -(coef_b -> valor.coef));
        coef_b = coef_b -> prox;
    }
}


/* Imprime o polinomio pol no formato do exemplo abaixo
 * [(0,2),(3,-2),(10,5)]
 * onde este polinomio tem 3 coeficientes, o de grau 0 com valor 2, o de grau 3 com valor -2 e o de
 * grau 10 com valor 5.
 */
void imprime(Polinomio pol){
    No* atual = pol -> prox;
    int inicio = 1;

    printf("[");
    while (atual != pol) {
        if (atual -> valor.coef != 0) {
            if(!inicio) {
                printf(",");
            }
        printf("(%d,%d)", atual -> valor.grau, atual -> valor.coef);
        inicio = 0;
        }
        atual = atual -> prox;
    }
    printf("]\n");
}

/* Desaloca toda a memória alocada da lista.
 */
void desaloca_polinomio(Polinomio *ap_pol){
    No* atual = (*ap_pol) -> prox;
    No* cab = *ap_pol;
    No* aux;

    while (atual != cab) {
        aux = atual -> prox;
        free(atual);
        atual = aux;
    }
    free(cab);
    *ap_pol = NULL;
}
