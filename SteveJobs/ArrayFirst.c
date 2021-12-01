//
//  main.c
//  Array
//
//  Created by Francesco Sacco on 21/02/2020.
//  Copyright © 2020 Francesco Sacco. All rights reserved.
//

#include <stdio.h>
#define dim 5

int main(void){
    
    unsigned long i; /*in questo modo i può assumere un qualsiasi valore che è diverso da 5 ed anche più grosso ex43783752 si usa "%lu"*/
    int v[dim];
    
    for(i=0; i<dim; i++) {
    printf("Inserisci un numero intero: ");
        scanf("%d", &v[i]);
    }
    for(i=0; i<dim; i++) {
        printf("v[%lu]=%d \n", i, v[i]);
    }
    
}


