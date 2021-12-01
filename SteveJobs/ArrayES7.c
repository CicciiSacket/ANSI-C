//
//  main.c
//  Esericizio 6 array
//
//  Created by Francesco Sacco on 22/02/2020.
//  Copyright © 2020 Francesco Sacco. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
#include<time.h> 
#define N 50
#define MAX 10
unsigned int i, a[N];
int main(void){

// inizializzazione del generatore pseudo-casuale dei numeri
    srand((unsigned int) time(NULL));
    printf("\nAdesso riempio il vettore con numeri tra 0 e %u", MAX - 1);
    for (i = 0; i<N; i++) {
        a[i] = rand() % MAX;
    printf("\nL'elemento di indice %u e' %u ", i, a[i]);
    }
}
