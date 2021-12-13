//
//  main.c
//  Struct_Array_Pointer
//
//  Created by Francesco_Utility on 13/12/21.
//

#include <stdio.h>

#define N 10

typedef struct Person{
    char name[15];
    char surname[15];
    int age;
} Person;

typedef struct Employee {
    int num_badge;
    struct Person person;
}Employee;

char * List_Person(struct Person List[N]) {
    char * EXIT_SUCCESS = "";
    int i = 0;
    struct Person * element;
    element = List;
    while (i < N) {
        printf("%s\t %s\t %d\n", element->name, element->surname, element->age);
        element++;
        i++;
    }
    return EXIT_SUCCESS;
}

char * List_Employees(struct Employee List[N]) {
    char * EXIT_SUCCESS = "";
    int i = 0;
    struct Employee *attache;
    attache = List;
    while (i < N) {
        printf("%d\t %s\t %s\n", attache->num_badge, attache->person.name, attache->person.surname);
        attache++;
        i++;
    }
    return EXIT_SUCCESS;
}


int main(int argc, const char * argv[]) {

    struct Person classe[N] = {{"Mario","Rossi",33},{"Lucia","Marzia",21},{"Ettore","Marzia",21},{"Lucia","Secondo",28},{"Maria","Marzia",24},{"Alberto","Rossi",22},{"Lucia","Lupo",21},{"Lucia","Giusi",35},{"Lucia","Marzia",21},{"Lucia","Marzia",21}};
//    struct Person * element;
//    element = classe; //Prende il primo elemento dell'array;
//    printf("%s\n",element->name);
//    printf("%s\t %s\t %d\n", element->name, element->surname, element->age);
//    printf("\n\n\n");
    printf("\n\n\n List Person\n");
    printf("%s\n",List_Person(classe));

    struct Employee employees[N] ={ { 1,{"Mario","Rossi",33}}, { 2,{"Lucia","Marzia",21}}, { 3,{"Lucia","Secondo",19}} };
    printf("\n\n\n\n List Employee\n");
    printf("%s\n",List_Employees(employees));
    

    return 0;
}
