//
//  main.c
//  Esercizio 5 febbraio
//
//  Created by Francesco Sacco on 19/02/2020.
//  Copyright © 2020 Francesco Sacco. All rights reserved.
//

#include <stdio.h>

int main(void){
    int righe;
    int colonne;
    int Nmax=9;

    for (righe=1; righe<=Nmax; righe++){
        for(colonne=1; colonne <= Nmax;colonne++){
            printf("%d-%d\t",colonne,righe);
            printf("\n");
        }
    }
}

/*
 1-1 1-2 1-3 1-4 1-5
 2-1 2-2 2-3 2-4 2-5     (progressione numerica da 1 a 9 di righe e colonne)
 3-1 3-2 3-3 3-4 3-5
 */
