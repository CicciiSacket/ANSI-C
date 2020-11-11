//
//  main.c
//  Prg4
//
//  Created by Francesco Sacco on 18/12/2019.
//  Copyright © 2019 Francesco Sacco. All rights reserved.

/* dati in input mese ed anno calcola il mese ed anno successivo [1=codice di errore]*/

#include <stdio.h>

int main() {
     
    int mese;
    int anno;
    
    
    printf("inserire il mese: \n");
    scanf("%d", &mese);
    
    if(mese >12) {
        printf("Attenzione i mesi del calendario sono 12. \n");
        return 1;
    }
    
    if (mese <1){
        printf("Attenzione i mesi del calendario sono 12. \n");
        return 1;
        
    }
    
    printf("inserire l'anno: \n");
    scanf("%d", &anno);
    
    if (mese == 12) {
        printf("il mese é: %d \n", 1);
        printf("l'anno é: %d \n", anno+1);
    } else {
        printf("il mese é: %d \n", mese+1);
        printf("l'anno é: %d \n", anno);
    }
    
    return 0;
}

