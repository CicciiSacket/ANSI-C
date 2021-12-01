//
//  main.c
//  PrimoCiclo
//
//  Created by Francesco Sacco on 10/02/2020.
//  Copyright © 2020 Francesco Sacco. All rights reserved.
//

#include <stdio.h>

int main(void){
    
    int i, n;
    int somma=0;
    
    printf("quanti i numeri da sommare: \n");
    scanf("%d",&n);
    
    while (n > 0) {
        printf("inserire numeri: \n");
        scanf("%d", &i);
        somma+=i;
        n--;
    }
    printf("la somma dei numeri è %d \n",somma);
}

