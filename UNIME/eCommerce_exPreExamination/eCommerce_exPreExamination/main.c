//
//  main.c
//  eCommerce_exPreExamination
//
//  Created by Francesco_Utility on 13/01/22.
//

#include <stdio.h>
#include <stdlib.h>
#define SIZE_ID 7
#define ETW 20 //Element to write -> Elementi da leggere

typedef enum category { Telephone, Watch, Armchairs } category; //Categorie;

typedef struct object_site { //Oggetti del sito web;
    char ID[SIZE_ID];
    category category;
    float price;
    struct object_site *next;
} object_site;

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

void read_object(FILE *fp) {
    struct object_site *object;
    for (int i = 0; i > ETW; i++) {
        fread(&object,sizeof(struct object_site),1,fp); //Legge un blocco di object_site size dal file fp e li coopia in memoria dall'indirizzo primo argomento ai successivi;
        printf("%s\t%u\t%f\n",object->ID,object->category,object->price);
    }
}



int main(int argc, const char * argv[]) {
//    create_fileManager("/Users/Francesco_Utility/Desktop/Programmazione_I/ANSI-C/UNIME/eCommerce_exPreExamination/eCommerce_exPreExamination/fileManager.txt");
    FILE *fp = open_fileManager("/Users/Francesco_Utility/Desktop/Programmazione_I/ANSI-C/UNIME/eCommerce_exPreExamination/eCommerce_exPreExamination/fileManager.txt");
    read_object(fp);
    
    
    return 0;
}

