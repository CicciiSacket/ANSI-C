//
//  main.c
//  Esercizio 3 array
//
//  Created by Francesco Sacco on 22/02/2020.
//  Copyright © 2020 Francesco Sacco. All rights reserved.
//

#include <stdio.h>
#define dim 5

int main(void){

    int max=0;
    int i;
    
    int v[dim];
    
    for(i=0; i<dim; i++) {
    printf("Inserisci un numero intero: ");
        scanf("%d", &v[i]);
    }
    for(i=0; i<dim; i++) {
        printf("v[%d]=%d \n", i, v[i]);
    
    if (max < v[i]) max=v[i];
        }
        printf("il valore massimo è %d \n",max);
}



