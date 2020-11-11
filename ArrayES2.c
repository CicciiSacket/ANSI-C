//
//  main.c
//  Esercizio 2 Array
//
//  Created by Francesco Sacco on 21/02/2020.
//  Copyright © 2020 Francesco Sacco. All rights reserved.
//

#include <stdio.h>

int main(void){
    
    int i;
    int dim;
    printf("inserire dimensione del vettore: \n");
    scanf("%d",&dim);
    int v[dim];
    
    for(i=0; i<dim; i++) {
    printf("Inserisci un numero intero: ");
        scanf("%d", &v[i]);
    }
    for(i=0; i<dim; i++) {
        printf("v[%d]=%d \n", i, v[i]);
    }
    
}
