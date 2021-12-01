//
//  main.c
//  Prg3
//
//  Created by Francesco Sacco on 16/12/2019.
//  Copyright © 2019 Francesco Sacco. All rights reserved.
//
/*il gruppo finale é dato dagli alunni spaiati*/
#include <stdio.h>

int main(){

    int numero_studenti;
    int numero_gruppi;
    int gruppi_realizzabili;
    int alunni_esclusi;

    printf("digitare numero di studenti: \n");
    scanf("%d", &numero_studenti);
    
    printf("digitare numero gruppi: \n");
    scanf("%d", &numero_gruppi);
    
    gruppi_realizzabili = (numero_studenti / numero_gruppi);
    alunni_esclusi = (numero_studenti % numero_gruppi);
    
    printf("il numero di gruppo realizzabili é: \n");
   
    printf("%d \n", gruppi_realizzabili);
    
    printf("gli alunni spaiati sono: \n");
    
    printf("%d \n", alunni_esclusi);
    
    if(alunni_esclusi > 4)
        printf("É possibile creare un gruppo con gli alunni rimanenti. \n");
    else
        printf("il numero di alunni che rimangono spaiati non é sufficiente per creare nessun altro gruppo. \n");

    return 0;

}

