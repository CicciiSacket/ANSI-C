//
//  main.c
//  Esercizio febbraio 3
//
//  Created by Francesco Sacco on 17/02/2020.
//  Copyright © 2020 Francesco Sacco. All rights reserved.
//

#include <stdio.h>

int main(void){

    int n;
    int max=0;
    int i = 0;

    printf("inserire numero di interi \n");
    scanf("%d", &n);

    while (n>0) {
            printf("inserire numeri \n");
            scanf("%d", &i);
        if (max<i) max=i;
        n--;}

    printf("il valore massimo è %d \n",max);
}

//    int n;
//    int max;
//    int i = 0;
//
//        printf("inserire numero di interi \n");
//        scanf("%d", &n);
//
//    max=0;
//    while (max <i ) {
//        <#statements#>
//    }
//
//}
