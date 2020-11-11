//
//  main.c
//  Esercizio 6 array
//
//  Created by Francesco Sacco on 22/02/2020.
//  Copyright © 2020 Francesco Sacco. All rights reserved.
//


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10

unsigned int i;
float a[N];
int main(void){

// inizializzazione del generatore pseudo-casuale dei numeri

    srand((unsigned int) time(NULL));
    printf("\nAdesso riempio il vettore con numeri reali tra 0 e 1");

    for (i = 0; i<N; i++) {
        a[i] = (float) rand() / RAND_MAX;
    printf("\nL'elemento di indice %u e' %f ", i, a[i]);
  }
}
