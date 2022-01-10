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
    package Tape_A[SIZE_TAPE]; //Nastro per i pacchi in ingresso;
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

void write_fileManager_IN(FILE *fp,package *package, typePackage typePackage) { //Scrittura sul file del pacco e della sua tipologia
    fprintf(fp, "IN -> ID: %s\t  Type: %u\n", package->ID, typePackage);
}

// ---------------------- //

//struct column_A *add_to_list_A(struct column_A *list, struct package package) { //Si aggiunge un pacco alla colonna A, corrispondente ad i pacchi in ingresso;
//    //non devo creare un nuovo column A come in esempio che seguivo prima ma aggiungere nell'array della colonna.....
//}

int main(int argc, const char * argv[]) {
//    FILE *fp = open_fileManager("/Users/Francesco_Utility/Desktop/Programmazione_I/ANSI-C/UNIME/Smisto_pacchi/Smisto_pacchi/Register.txt");
    

    struct column_A *first_A = NULL; //Punto iniziale della colonna A;
//    struct column_B *first_B = NULL; //Punto iniziale della colonna B;
//    struct column_C *first_C = NULL; //Punto iniziale della colonna C;
//    struct column_D *first_D = NULL; //Punto iniziale della colonna D;
    struct package *packegeTest = {"AA000A0", "0000A", 3.56, regular};
    struct package *packegeTest2 = {"AA000A2", "0000A", 3.56, regular};
    struct package *packegeTest3 = {"AA000A3", "0000A", 3.56, regular};
    first_A = add_to_list_A(first_A, *packegeTest3);
    first_A = add_to_list_A(first_A, *packegeTest2);
    first_A = add_to_list_A(first_A, *packegeTest3);

    

//    write_fileManager_IN(fp,packegeTest,regular);
    
//    for (int i = 0; i < sizeof(first_A->Tape_A)/sizeof(first_A->Tape_A[0]); i++) {
//        printf("%s\n", first_A->Tape_A[i].ID);
//    }
    printf("%s\n", first_A->Tape_A[2].ID);

    
    

    return 0;
}
