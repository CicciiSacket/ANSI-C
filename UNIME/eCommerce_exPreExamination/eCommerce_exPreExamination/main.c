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

struct objs *add_to_site(struct objs *head_list, char * id, enum category category, float price) { //Aggiunta di un elemento in maniera ordinata in base al prezzo;
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

struct objs *delete_to_site (struct objs *list, char * ID) { //Si rimuove il prodotto che viene acquistato
    struct objs *prev,*cur;
        for (cur = list, prev = NULL; cur != NULL && strcmp(cur->object_site.ID ,ID) != 0 ; prev = cur, cur = cur->next);
        if (cur == NULL) {
            return list; // Non esiste un nodo con data;
        }
        if (prev == NULL) {
            list = list->next; // Data si trova nel primo nodo;
        }
        else
            prev->next = cur->next; // Data si trova in un qualunque altro nodo della lista;
        free(cur);
        return list;
}

void all_products_in_site(struct objs *list) { //Lista di tutti i prodotti
    struct objs *head;
    for (head = list; head != NULL; head = head->next) {
        printf("ID: %s\t Type: %u\t Price: %f\n",head->object_site.ID, head->object_site.category, head->object_site.price);
    }
}

void all_products_in_category(struct objs *list, enum category category) { //Lista prodotti in una categoria specifica
    struct objs *head;
    for (head = list; head != NULL; head = head->next) {
        if (head->object_site.category == category) {
            printf("ID: %s\t Type: %u\t Price: %f\n",head->object_site.ID, head->object_site.category, head->object_site.price);
        }
    }
}

void search_product(struct objs *list, char * ID) { //Ricerca di un prodotto tramite id
    for (; list != NULL; list = list->next) {
        if (strcmp(list->object_site.ID,ID) == 0) {
            printf("ID: %s\t Type: %u\t Price: %f\n",list->object_site.ID, list->object_site.category, list->object_site.price);
        }
    }
}

struct objs * all_products_reverse_price(struct objs *list) { //Ritorna la lista in ordine decrescente
    objs* new_root = 0;
    while (list) {
        objs* next = list->next;
        list->next = new_root;
        new_root = list;
        list = next;
    }
    return new_root;
}

void print_reverse(struct objs *list,category category) {
    struct objs *list_site = all_products_reverse_price(list);
    all_products_in_category(list_site, category);
}
void pre_shop(struct objs *list) {
    char c;
    printf("%s\t%s\n", "Press C for all products", "EXIT - 9");
    scanf("%c",&c);
    if (c == 'c' || c == 'C') {
        all_products_in_site(list);
    }
    if (c == '9') {
        exit(0);
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

struct objs * reading_and_compile(char pattern[],struct objs *list_file) { //Lettura dei prodotti dal file e aggiunta in una nuova lista;
    FILE *fp = open_fileManager(pattern);
    char * id;
    char * category;
    float price;
    while(fscanf(fp, "%s %s %f",id,category,&price)!= EOF) {
        if (strcmp(category, "Watch") == 0) {
            list_file = add_to_site(list_file, id, Watch,price);
        }
        if (strcmp(category, "Telephone") == 0) {
            list_file = add_to_site(list_file, id, Telephone,price);
        }
        if (strcmp(category, "Armchairs") == 0 ) {
            list_file = add_to_site(list_file, id, Armchairs,price);
        }
    }
        return list_file;
}




int main(int argc, const char * argv[]) { //Main per le gestione sito senza affidarsi al file;
    char pattern [] = "/Users/Francesco_Utility/Desktop/Programmazione_I/ANSI-C/UNIME/eCommerce_exPreExamination/eCommerce_exPreExamination/fileManager.txt";
    //    create_fileManager("/Users/Francesco_Utility/Desktop/Programmazione_I/ANSI-C/UNIME/eCommerce_exPreExamination/eCommerce_exPreExamination/fileManager.txt");
    
    struct objs *list_site = NULL;
    list_site = add_to_site(list_site, "AA000AA", Watch, 89.90);
    list_site = add_to_site(list_site, "AA001AA", Telephone, 79.99);
    list_site = add_to_site(list_site, "AA002AA", Watch, 19.99);
    list_site = add_to_site(list_site, "AA003AA", Armchairs, 1999.99);
    list_site = add_to_site(list_site, "AA004AA", Telephone, 1.99);
    list_site = add_to_site(list_site, "AA005AA", Watch, 9.99);
//
//    all_products_in_site(list_site);
//    printf("\n\n");
//    all_products_in_category(list_site, Armchairs);
//    printf("\n\n");
//    all_products_in_category(list_site, Watch);
//    printf("\n\n");
//    all_products_in_category(list_site, Telephone);
//    printf("\n\n");
//    search_product(list_site, "AA003AA");
//    printf("\n\n");
//    list_site = all_products_reverse_price(list_site);
//    printf("\n\n");
//    all_products_in_site(list_site);
//    printf("\n\n");
//    list_site = delete_to_site(list_site,"AA004AA");
//    printf("\n\n");
//    all_products_in_site(list_site);
//    printf("\n\n");
//    list_site = all_products_reverse_price(list_site);
//    printf("\n\n");
//    all_products_in_site(list_site);
//    printf("\n\n");
//    printf("\n\n");
    
    struct objs * list_file = NULL;
    list_file = reading_and_compile(pattern, list_file);
    all_products_in_site(list_file);
    printf("\n\n");
    return 0;
}

