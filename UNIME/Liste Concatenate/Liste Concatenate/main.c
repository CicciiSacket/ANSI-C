//
//  main.c
//  Liste Concatenate, catena di nodi contenente dati e puntatore al nodo successivo;
//
//  Created by Francesco_Utility on 16/12/21.
//

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *add_to_list(struct node *list, int data) {
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("%s","Error");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = list;
    return new_node;
}

struct node *add_to_list_order(struct node *head_list, int data) { //Aggiunta di un elemento in maniera ordinata
    struct node *r = head_list, *q = head_list; //predecessore e successore del nuovo elemento;
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("%s","Error");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    while ((q != NULL) && (q->data < new_node->data)) {
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

void all_values_list(struct node *list) {
    struct node*i;
    for (i = list; i != NULL; i = i->next) {
        printf("%d\n", i->data);
    }
}

struct node *search_in_list(struct node *list, int data) {
    for (; list != NULL; list = list->next) {
        if (list->data == data) {
            return list;
        }
    }
    return NULL;
}

struct node *delete_in_list(struct node *list, int data) {
    
    // 1-Localizzare il nodo da eliminare
    struct node *prev,*cur;
    for (cur = list, prev = NULL; cur != NULL && cur->data != data; prev = cur, cur = cur->next);
    //Trascinamento del puntatore, un puntatore al nodo precedente e uno al nodo successivo; QUANDO IL CICLO TERMINA CUR PUNTA AL NODO DA ELIMINARE MENTRE PREV AL PRECEDENTE(se esiste). { [cur = list, prev = NULL;] => questa istruzione fa si che cur punti al primo nodo della lista, [cur != NULL && cur->value != data] => con questa istruzione si cerca il nodo contenente il dato che si ha come parametro;
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

int main(int argc, const char * argv[]) {
    struct node *first = NULL;
    first = add_to_list_order(first, 10);
    first =  add_to_list_order(first, 14);
    first =  add_to_list_order(first, 24);
    first = add_to_list_order(first, 22);
    printf("%d\n", first->data); //ultimo, che in realtà è primo, valore della lista;
    
    printf("\n\n");
    all_values_list(first);
    
    printf("\n\n");
    struct node *search = (search_in_list(first, 14));
    printf("%d\n",search->data);
    
    printf("\n\n");
    delete_in_list(first, 14);
    printf("\n\n");
    all_values_list(first);
    
    return 0;
}

