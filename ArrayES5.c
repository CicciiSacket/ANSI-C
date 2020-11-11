//
//  main.c
//  Esercizio 5 array
//
//  Created by Francesco Sacco on 22/02/2020.
//  Copyright © 2020 Francesco Sacco. All rights reserved.


#include<stdio.h>
#include<stdlib.h>
#define N 10
unsigned int i, a[N];

int main(void){
    printf("\nRiempio il vettore con numeri casuali maggiori o uguali a zero");
    printf("\nIl massimo numero che posso generare e' = %u ", RAND_MAX);
    for (i = 0; i<N; i++) {
        a[i] = rand();
        printf("\nL'elemento di indice %u e' %u ", i, a[i]);
    }
}
 
