//
//  main.c
//  Esercizio 4 array
//
//  Created by Francesco Sacco on 22/02/2020.
//  Copyright © 2020 Francesco Sacco. All rights reserved.
//

#include <stdio.h>
#define N 6
int main(void){
unsigned int i;
int a[N]={8,5,23,4,7,0};
    float somma = 0.0;

    for(i=0; i<N; i++)
        somma+=a[i];
    printf("\nIl valore medio e’ %f ",somma/N);
}

