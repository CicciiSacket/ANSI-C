//
//  main.c
//  Pointer&String
//
//  Created by Francesco_Utility on 09/12/21.
//

#include <stdio.h>
#include <string.h>


char * single_name(char *list[], char name[], int N){
    static char E[] = "Name not found\n";
    for (int i=0; i < N ; i++) {
        if (strcmp(list[i], name) == 0){
            return list[i];
        }
    }
    return E;
}


int main(int argc, const char * argv[]) {
    char *list[] = {"Mario","Francesco","Alberto","Lucia"};
    printf("%c \n", list[2][5]); //Lettera T
    printf("%s\n", list[1]); //Elemento 1 della lista
    printf("\n\n\n");
    if(strcmp("abc", "abcd") < 0){
        printf("abc è minore di abcd\n");
    }
    if(strcmp("abcd", "abc") > 0){
        printf("abcd è maggiore di abc\n");
    }
    if(strcmp("abc", "abc") == 0){
        printf("abc è uguale di abc\n");
    }
    printf("\n\n\n");



    for (int i=0; i < (sizeof(list)/sizeof(list[0])) ; i++) {
            printf("%s\n", list[i]); //Torna gli elementi dell'array
    }

    printf("\n\n\n");
    char name[15];
    for (int i=0; i < (sizeof(list)/sizeof(list[0])) ; i++) {
        strcpy(name, list[i]);
        printf("%s\n",name); //Torna gli elementi dell'array dopo la modifica con strcpy
    }

    printf("\n\n\n");
    char pluto[] = "Francesco" ;
    for (int i=0; i < (sizeof(list)/sizeof(list[0])) ; i++) {
        if (strcmp(list[i], pluto) == 0){
            printf("%s\t è il nome inserito\n", list[i]);
        }
    }
    printf("\n\n\n");
    
    printf("%s\n\n",single_name(list,"Lucia",10));
    
    
    
    
    
    return 0;
}
