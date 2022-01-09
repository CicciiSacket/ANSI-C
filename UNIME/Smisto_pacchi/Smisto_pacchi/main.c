//
//  main.c
//  Smisto_pacchi
//
//  Created by Francesco_Utility on 08/01/22.
//

#include <stdio.h>
#include <stdlib.h>
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
    package Tape_D[SIZE_TAPE]; //Nastro per i pacchi difettosi e da incenerire;
    struct column_D *next;
};

int create_fileManager(char pattern[]) { //Crea il file in lettura e scrittura;
    FILE *fp = fopen(pattern, "w+");
    if (fp == NULL) {
        return 400; //Non è possibile creare il file;
    }
    return 0;
}

FILE * open_fileManager(char pattern[]) { //Apre il file in lettura e scrittura;
    FILE *fp = fopen(pattern, "a+");
    if (fp == NULL) {
        printf("404"); //Non è possibile trovare il file nel pattern selezionato;
    }
    return fp;
}

void write_fileManager(FILE *fp,package *package) { //Scrittura sul file del contenuto specifico
    fprintf(fp, "ID: %s\t  Type: %u\n", package->ID,package->TypePackage);
}

// ---------------------- //

struct column_A *add_to_list(struct column_A *list, struct package package) { //Si aggiunge un pacco alla colonna A, corrispondente ad i pacchi in ingresso;
    struct column_A *new_pack;
    new_pack = malloc(sizeof(struct column_A));
    if (new_pack == NULL) {
        printf("%s","Error");
        exit(EXIT_FAILURE);
    }
    new_pack->Tape_A[SIZE_TAPE - 1] = package; //Ogni pacco che arriva finisce in fondo al nastro;
    new_pack->next = list;
    return new_pack;
}

void all_values_list_A(struct column_A *list) {
    struct column_A *i;
    for (i = list; i != NULL; i = i->next) {
        for (int j = SIZE_TAPE;j == 0; j--) {
            printf("%s\n", i->Tape_A[j].ID);
        }
    }
}



int main(int argc, const char * argv[]) {
//    struct column_A *first_A = NULL; //Punto iniziale della colonna A;
//    struct column_B *first_B = NULL; //Punto iniziale della colonna B;
//    struct column_C *first_C = NULL; //Punto iniziale della colonna C;
//    struct column_D *first_D = NULL; //Punto iniziale della colonna D;
    
            
//    FILE *fp = open_fileManager("/Users/Francesco_Utility/Desktop/Programmazione_I/ANSI-C/UNIME/Smisto_pacchi/Smisto_pacchi/Register.txt");
    
    
//    struct package *packegeTest = {"AA000A0", "0000A", 3.56, regular};
//    first_A = add_to_list(first_A, *packegeTest);
//    printf("%s", first_A->Tape_A[SIZE_TAPE - 1].ID);
//    printf("%u\n", packegeTest->TypePackage);
//    write_fileManager(fp,packegeTest);
    

    
    

    return 0;
}
