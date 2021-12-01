//
//  main.c
//  altezza
//
//  Created by Francesco Sacco on 31/01/2020.
//  Copyright © 2020 Francesco Sacco. All rights reserved.
//

#include <stdio.h>

int main(){
    
    int età;
    int altezza;
    
    printf("inserire età: \n");
    scanf("%d", &età);
    printf("inserire altezza: \n");
    scanf("%d", &altezza);
    printf("la tua altezza\n");
    
//    if (età <= 0 || altezza <= 0){
//        printf("ERRORE");
//    }
    
    if ((altezza >= 250) |  (età >= 6 & altezza <80)){
        printf("non");}
    printf(" è nella norma \n");
    
    return 0;
}
//||non valuta il secondo argomento se verifica 1//



