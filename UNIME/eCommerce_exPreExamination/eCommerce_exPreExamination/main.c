//
//  main.c
//  eCommerce_exPreExamination
//
//  Created by Francesco_Utility on 13/01/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_ID 7
#define ETW 20 //Element to write -> Elementi da leggere

typedef enum category { Telephone, Watch, Armchairs } category; //Categorie;

typedef struct object_site { //Oggetti del sito web;
    char * ID;
    category category;
    float price;
    struct object_site *next;
} object_site;

typedef struct objs {
    object_site object_site;
    struct objs *next;
}objs;

struct objs *add_to_site(struct objs *head_list, char id[SIZE_ID], enum category category, float price) { //Aggiunta di un elemento in maniera ordinata in base al prezzo;
    struct objs *r = head_list, *q = head_list; //predecessore e successore del nuovo elemento;
    struct objs *new_node;
    new_node = malloc(sizeof(struct object_site));
    if (new_node == NULL) {
        printf("%s","Error");
        exit(EXIT_FAILURE);
    }
    new_node->object_site.ID = id;
    new_node->object_site.category = category;
    new_node->object_site.price = price;
    while ((q != NULL) && (q->object_site.price < new_node->object_site.price)) { //Prezzo in ordine crescente;
        r = q;
        q = q->next;
    }
    if (r == q) {
        head_list = new_node;
    }
    else
        r->next = new_node;
    new_node->next = q;
    return head_list;
}

void all_products_in_category(struct objs *list) {
    struct objs *head;
    for (head = list; head != NULL; head = head->next) {
        printf("ID: %s\t Type: %u\t Price: %f\n",head->object_site.ID, head->object_site.category, head->object_site.price);
    }
}


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


int main(int argc, const char * argv[]) {
//    create_fileManager("/Users/Francesco_Utility/Desktop/Programmazione_I/ANSI-C/UNIME/eCommerce_exPreExamination/eCommerce_exPreExamination/fileManager.txt");
//    FILE *fp = open_fileManager("/Users/Francesco_Utility/Desktop/Programmazione_I/ANSI-C/UNIME/eCommerce_exPreExamination/eCommerce_exPreExamination/fileManager.txt");
    
    
    struct objs *list_site = NULL;
    list_site = add_to_site(list_site, "AA000AA", Watch, 89.90);
    list_site = add_to_site(list_site, "AA001AA", Telephone, 999.99);
    list_site = add_to_site(list_site, "AA001AA", Telephone, 19.99);
    list_site = add_to_site(list_site, "AA001AA", Telephone, 1999.99);

    all_products_in_category(list_site);
    return 0;
}

