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

struct column_A { //Colonna che contiene i pacchi specifici;
    package Tape_A[SIZE_TAPE]; //Nastro per i pacchi difettosi e da incenerire;
    struct column_A *next;
};

struct column_B { //Colonna che contiene i pacchi specifici;
    package Tape_B[SIZE_TAPE]; //Nastro per i pacchi in uscita dalla fabbrica;
    struct column_B *next;
};

struct column_C { //Colonna che contiene i pacchi specifici;
    package Tape_C[SIZE_TAPE]; //Nastro per i pacchi che rimangono ancora in fabbrica;
    struct column_C *next;
};

struct column_D { //Colonna che contiene i pacchi specifici;
    package Tape_D[SIZE_TAPE]; //Nastro per i pacchi in ingresso;
    struct column_D *next;
};

int create_fileManager(char pattern[]) { //Crea il file in lettura e scrittura;
    FILE *fp = fopen(pattern, "w+");
    if (fp == NULL) {
        return 400; //Non è possibile creare il file;
    }
    return 0;
}

void open_fileManager(char pattern[]) { //Apre il file in lettura e scrittura;
    FILE *fp = fopen(pattern, "r+");
    if (fp == NULL) {
        printf("404"); //Non è possibile trovare il file nel pattern selezionato;
    }
}

//void write_fileManager(FILE *fp,package *package) {
//    fprintf(fp, package->ID + package->TypePackage);
//}

int main(int argc, const char * argv[]) {
    struct column_A *first_A = NULL; //Punto iniziale della colonna A;
    struct column_B *first_B = NULL; //Punto iniziale della colonna B;
    struct column_C *first_C = NULL; //Punto iniziale della colonna C;
    struct column_D *first_D = NULL; //Punto iniziale della colonna D;
    
    create_fileManager("/Users/Francesco_Utility/Desktop/Programmazione_I/ANSI-C/UNIME/Smisto_pacchi/Smisto_pacchi/Register.txt");
    open_fileManager("/Users/Francesco_Utility/Desktop/Programmazione_I/ANSI-C/UNIME/Smisto_pacchi/Smisto_pacchi/Register.txt");
    
    
    
    
////    FILE *fp = fopen("/Users/Francesco_Utility/Desktop/Programmazione_I/ANSI-C/UNIME/Smisto_pacchi/Smisto_pacchi/Register.txt", "w+"); //Crea il file in lettura e scrittura;
//    FILE *fp = fopen("/Users/Francesco_Utility/Desktop/Programmazione_I/ANSI-C/UNIME/Smisto_pacchi/Smisto_pacchi/Register.txt", "r+"); //Apre il file in lettura e scrittura dell'inizio alla fine;
//    if (fp == NULL) {
//        printf("mario");
//    }
//    fprintf(fp, "Mario");
    
    
    return 0;
}
