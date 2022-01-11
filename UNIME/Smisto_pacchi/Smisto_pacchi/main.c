//
//  main.c
//  Smisto_pacchi
//
//  Created by Francesco_Utility on 08/01/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_TAPE 1000

typedef enum typePackage { defective , regular } typePackage; //Stabilisce se il pacco è da incenerire o meno;

typedef struct package { //Etichetta del singolo pacco;
    char ID[7];
    char ID_Destination[5];
    float Weight;
    typePackage TypePackage;
} package;

struct Tape { //Nastro per i pacchi;
    package TapePackage;
    struct Tape *next;
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

void write_fileManager_OUT(FILE *fp,package *package, typePackage typePackage) { //Scrittura sul file del pacco e della sua tipologia
    fprintf(fp, "OUT -> ID: %s\t  Type: %u\n", package->ID, typePackage);
}
// ---------------------- //

struct Tape *add_to_tape(struct Tape *list, struct package *package) { //Aggiunge il pacco al nastro specifico
    struct Tape *new_node;
    new_node = malloc(sizeof(struct Tape));
    if (new_node == NULL) {
        printf("%s","Error");
        exit(EXIT_FAILURE);
    }
    new_node->TapePackage = *package;
    new_node->next = list;
    return new_node;
}

struct Tape *search_in_list(struct Tape *list, struct package *package) {
    for (; list != NULL; list = list->next) {
        if (strcmp(list->TapePackage.ID, package->ID) == 0) {
            return list;
        }
    }
    return NULL;
}

void all_packages_Tape(struct Tape *list) {
    struct Tape *i;
    for (i = list; i != NULL; i = i->next) {
        printf("%s\n", i->TapePackage.ID);
    }
}

int get_in_category(struct Tape *list, struct package category[], struct package *package,char IdPackage[7]) { //Sposto un pacco dal nastro opportuno alla categoria opportuna
    struct Tape *search = search_in_list(list, package);
    if (search == NULL) {
        return 404;
    }
}

void all_package_in_category(struct package category[]) { //Visualizza i pacchi nella categoria;
        for (int i = 0; i > SIZE_TAPE; i++) {
            printf("%s\n",category[i].ID);
        }
}



int main(int argc, const char * argv[]) {
//    FILE *fp = open_fileManager("/Users/Francesco_Utility/Desktop/Programmazione_I/ANSI-C/UNIME/Smisto_pacchi/Smisto_pacchi/Register.txt");
    
    struct package *packageTest = {"AA000AA","000A",3.59,defective};

//    struct package category_A[SIZE_TAPE]; //Categoria con i pacchi in spedizione; [ Non colonna perchè non sono spediti in ordine di arrivo al magazzino i pacchi :| ]
//    struct package category_B[SIZE_TAPE]; //Categoriacon i pacchi in attesa di;
    struct package *category_C[SIZE_TAPE]; //Categoria con i pacchi da incenerire;

    struct Tape *Tape_A = NULL; //Lista corrispondente al nastro A;
    struct Tape *Tape_D = NULL; //Lista corrispondente al nastro D;

    Tape_A = add_to_tape(Tape_A, packageTest); //Aggiungo il pacco sul nastro A;
//    write_fileManager_IN(fp,packageTest,regular); //Scrivo che è entrato un nuovo pacco;
    printf("%s\n","I pacchi in ingresso sono:\n");
    all_packages_Tape(Tape_A); //Visualizzo i pacchi presenti sul nastro A;
    Tape_D = add_to_tape(Tape_D,packageTest);//Sposto nel nastro dell'inceneritore il pacco difettoso;
    printf("%s\n","Il pacco selezionato è stato spostato nel nastro D");
    printf("%s\n","I pacchi nel nastro D sono:\n");
    all_packages_Tape(Tape_D); //Visualizzo i pacchi sul nastro dell'inceneritore;

    printf("\n\n\n");
    printf("%d\n",get_in_category(Tape_D, category_C, packageTest,"AA000AA"));//sposto il pacco nella categoria da incenerire
    printf("%s\n","Il pacco selezionato sarà presto incenerito");
    printf("\n%s\n", "I pacchi da incenerire sono:");

        


    return 0;
}
//All'arrivo del pacco print delle specifiche - porlo nella colonna corrispondente(scrivendo che il pacco è OUT se deve uscire o Fire se deve bruciare) e di conseguenza prima nel nastro corrispondente - registrare l'ingresso del pacco sul file
// ....... continue
