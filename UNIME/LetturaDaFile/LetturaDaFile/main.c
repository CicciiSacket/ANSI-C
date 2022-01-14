//
//  main.c
//  LetturaDaFile
//
//  Created by Francesco_Utility on 14/01/22.
//

#include <stdio.h>
#include <stdlib.h>


int create_fileManager(char pattern[]) { //Crea il file in lettura e scrittura;
    FILE *fp = fopen(pattern, "w+");
    if (fp == NULL) {
        return 400; //Non è possibile creare il file;
    }
    return 0;
}

FILE * open_fileManager(char pattern[]) { //Apre il file in lettura;
    FILE *fp = fopen(pattern, "r");
    if (fp == NULL) {
        printf("404"); //Non è possibile trovare il file nel pattern selezionato;
    }
    return fp;
}

void reading_1(FILE * fp) { //Lettura di 1234567  e di "nome cognome sesso anno";
    int c;
    while ((c=fgetc(fp))!= EOF) putchar(c);
    fclose(fp);
}

typedef struct persona {
    char * cognome, * nome, * sesso;
    int anno;
}persona;

typedef struct list_name {
    persona persona;
    struct list_name *next;
}lista_name;

struct list_name *add_to_list(struct list_name *list, char * cognome, char * nome, char * sesso, int anno) {
    struct list_name *new_node;
    new_node = malloc(sizeof(struct list_name));
    if (new_node == NULL) {
        printf("%s","Error");
        exit(EXIT_FAILURE);
    }
    new_node->persona.cognome = cognome;
    new_node->persona.nome = nome;
    new_node->persona.sesso = sesso;
    new_node->persona.anno = anno;
    new_node->next = list;
    return new_node;
}

int main(int argc, const char * argv[]) {
    char * pattern = "/Users/Francesco_Utility/Desktop/Programmazione_I/ANSI-C/UNIME/LetturaDaFile/LetturaDaFile/fileManager.txt";
//    create_fileManager(pattern);
    FILE * fp = open_fileManager(pattern);
    reading_1(fp);
    printf("\n\n\n");
//    reading_2(fp);
    
    struct list_name *list_name = NULL;
    persona v[5];
    int k = 0;
    while(fscanf(fp,"%s%s%s%d\n", v[k].cognome,
        v[k].nome, v[k].sesso, &(v[k].anno)) != EOF)
    k++;
    for (int i=0; i<k; i++){
//        printf("%s %s %s %d\n", v[i].cognome, v[i].nome, v[i].sesso, v[i].anno);
        list_name = add_to_list(list_name, v[i].cognome, v[i].nome, v[i].sesso, v[i].anno);
    }
    
    for (; list_name != NULL; list_name = list_name->next) {
            printf("%s\t%s\t%s\t%d\n",list_name->persona.cognome,list_name->persona.nome,list_name->persona.sesso, list_name->persona.anno);
        }
    
    
    
    
    
    
    
    return 0;
}
