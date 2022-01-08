//
//  main.c
//  Smisto_pacchi
//
//  Created by Francesco_Utility on 08/01/22.
//

#include <stdio.h>
#define SIZE_TAPE 1000

typedef enum typePackage { defective , regular } typePackage; //Stabilisce se il pacco è da incenerire o meno;

typedef struct package { //Etichetta del singolo pacco;
    char ID[7];
    char ID_Destination[5];
    float Weight;
    typePackage TypePackage;
} package;

struct column_A { //Colonna che contiene i pacchi specifici
    package Tape_A[SIZE_TAPE]; //Nastro per i pacchi difettosi e da incenerire;
    struct column_A *next;
};

struct column_B { //Colonna che contiene i pacchi specifici
    package Tape_B[SIZE_TAPE]; //Nastro per i pacchi in uscita dalla fabbrica;
    struct column_B *next;
};

struct column_C { //Colonna che contiene i pacchi specifici
    package Tape_C[SIZE_TAPE]; //Nastro per i pacchi che rimangono ancora in fabbrica;
    struct column_C *next;
};

struct column_D { //Colonna che contiene i pacchi specifici
    package Tape_D[SIZE_TAPE]; //Nastro per i pacchi in ingresso;
    struct column_D *next;
};


int main(int argc, const char * argv[]) {
    struct column_A *first_A = NULL; //Punto iniziale della colonna A;
    struct column_B *first_B = NULL; //Punto iniziale della colonna B;
    struct column_C *first_C = NULL; //Punto iniziale della colonna C;
    struct column_D *first_D = NULL; //Punto iniziale della colonna D;
    
//    FILE *fp = fopen("Register.txt", "r+"); //Apre il file in lettura e scrittura dell'inizio alla fine;
//    if (fp == NULL) {
//        printf("mario");
//    }
//    fprintf(fp, "Mario");
    
    
    return 0;
}
