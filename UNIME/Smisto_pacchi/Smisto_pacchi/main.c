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

typedef struct Package { //Etichetta del singolo pacco;
    char ID[7];
    char ID_Destination[5];
    float Weight;
    typePackage TypePackage;
} package;

typedef struct Tape { //Nastro per i pacchi;
    package TapePackage;
    struct Tape *next;
} Tape;

typedef struct Column { //Colonna per i pacchi;
    package Package;
    struct Column *next;
} Column;


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

void write_fileManager_IN(FILE *fp,package *package, typePackage typePackage) { //Scrittura sul file del pacco e della sua tipologia quando arriva in ingresso
    fprintf(fp, "IN -> ID: %s\t  Type: %u\n", package->ID, typePackage);
}

void write_fileManager_OUT(FILE *fp,package *package, typePackage typePackage) { //Scrittura sul file del pacco e della sua tipologia quando in spedizione
    fprintf(fp, "OUT -> ID: %s\t  Type: %u\n", package->ID, typePackage);
}

void write_fileManager_F(FILE *fp,package *package, typePackage typePackage) { //Scrittura sul file del pacco da incenerire
    fprintf(fp, "FIRE -> ID: %s\t  Type: %u\n", package->ID, typePackage);
}
// ---------------------- //

struct Tape *search_in_list(struct Tape *list, struct Package *package) { //Cerca il pacco sul nastro
    for (; list != NULL; list = list->next) {
        if (strcmp(list->TapePackage.ID, package->ID) == 0) {
            return list;
        }
    }
    return NULL;
}

struct Tape *add_to_tape(struct Tape *list, struct Package *package) { //Aggiunge il pacco al nastro specifico
    struct Tape *duplicate = search_in_list(list, package);
    struct Tape *new_node;
    if (duplicate) {
        printf("%s","Already exist\n");
        return duplicate;
    }
    new_node = malloc(sizeof(struct Tape));
    if (new_node == NULL) {
        printf("%s","Error");
        exit(EXIT_FAILURE);
    }
    new_node->TapePackage = *package;
    new_node->next = list;
    return new_node;
}

void all_packages_tape(struct Tape *list) { //View per tutti i pacchi presenti su nastro
    struct Tape *i;
    for (i = list; i != NULL; i = i->next) {
        printf("%s\n", i->TapePackage.ID);
    }
}

struct Column *get_in_category(struct Tape *list, struct Column *column, struct Package *package) { //Sposto un pacco dal nastro opportuno alla colonna opportuna
    struct Tape *search = search_in_list(list,package);
    if (search == NULL) {
        exit(404); //Se non esiste il pacco sul nastro;
    }
    struct Column *new_node;
    new_node = malloc(sizeof(struct Column));
    if (new_node == NULL) {
        printf("%s","Error");
        exit(EXIT_FAILURE);
    }
    new_node->Package = *package;
    new_node->next = column;
    return new_node;
}

void all_package_in_column(struct Column *list) { //Visualizza i pacchi nella colonna;
    struct Column *i;
    for (i = list; i != NULL; i = i->next) {
        printf("%s\n", i->Package.ID);
    }
}

struct Package *generate_package (char ID[], char id_destination[], float weight, typePackage typePackage) { //Inizializzazione pacco
    struct Package *package = {ID,id_destination,weight,typePackage};
    return package;
}

struct Tape *delete_in_tape(struct Tape *list, struct Package *package) {
    struct Tape *prev,*cur;
    for (cur = list, prev = NULL; cur != NULL && strcmp(cur->TapePackage.ID, package->ID) != 0 ; prev = cur, cur = cur->next);
    if (cur == NULL) {
        return list; // Non esiste un nodo con data;
    }
    if (prev == NULL) {
        list = list->next; // Data si trova nel primo nodo; [con questa istruzione si altera il nodo precedente in modo da bypassare il nodo eliminato]
    }
    else
        prev->next = cur->next; // Data si trova in un qualunque altro nodo della lista;
    free(cur); // Si rilascia lo spazio di memoria occupato dal nodo eliminato;
    return list;
}


/* MAIN */
int main(int argc, const char * argv[]) {
//    FILE *fp = open_fileManager("/Users/Francesco_Utility/Desktop/Programmazione_I/ANSI-C/UNIME/Smisto_pacchi/Smisto_pacchi/Register.txt");

    struct Package *packageTest = generate_package("AA000AA","000A",3.59,defective);

    struct Column *Column_A = NULL; //Colonna con i pacchi in spedizione;
    struct Column *Column_B = NULL;; //Colonna i pacchi in attesa di;
    struct Column *Column_C = NULL;; //Colonna con i pacchi da incenerire;

    struct Tape *Tape_A = NULL; //Lista corrispondente al nastro A; [In ingresso]
    struct Tape *Tape_B = NULL; //Lista corrispondente al nastro B; [In spedizione]
    struct Tape *Tape_C = NULL; //Lista corrispondente al nastro C; [Da incenerire]
    struct Tape *Tape_D = NULL; //Lista corrispondente al nastro D; [In attesa di..]

    
    
    Tape_A = add_to_tape(Tape_A, packageTest); //Aggiungo il pacco sul nastro A;
    all_packages_tape(Tape_A);
    printf("\n");
    Tape_A = add_to_tape(Tape_A, packageTest); //Aggiungo il pacco sul nastro A;
    all_packages_tape(Tape_A);
    printf("\n\n\n");
    
//    write_fileManager_IN(fp,packageTest,defective); //Scrivo che è entrato un nuovo pacco;
//    all_packages_tape(Tape_A); //Visualizzo i pacchi presenti sul nastro A;
//    Tape_D = add_to_tape(Tape_D,packageTest);//Sposto nel nastro verso l'inceneritore il pacco difettoso;
//    Tape_A = delete_in_tape(Tape_A, packageTest); //Rimuovo dal nastro A;
//    all_packages_tape(Tape_D); //Visualizzo i pacchi sul nastro dell'inceneritore;
//    Column_C = get_in_category(Tape_D, Column_C, packageTest); //Sposto il pacco nella colonna da incenerire;
//    write_fileManager_F(fp, packageTest, defective); //Scrivo che il pacco si sposta dal nastro alla colonna dell'inceneritore;
//    all_package_in_column(Column_C); //Visualizzo tutti i pacchi presenti nella colonna da incenerire;
    
    return 0;
}
//All'arrivo del pacco print delle specifiche - porlo nella colonna corrispondente(scrivendo che il pacco è OUT se deve uscire o Fire se deve bruciare) e di conseguenza prima nel nastro corrispondente - registrare l'ingresso del pacco sul file
// ....... continue
