//
//  main.c
//  LetturaDaFile
//
//  Created by Francesco_Utility on 14/01/22.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct {
char cognome[11], nome[11], sesso; int anno;
} persona;
FILE * open_fileManager(char pattern[]) { //Apre il file in lettura;
    FILE *fp = fopen(pattern, "r");
    if (fp == NULL) {
        printf("404"); //Non è possibile trovare il file nel pattern selezionato;
    }
    return fp;
}

main() {
    char * pattern = "/Users/Francesco_Utility/Desktop/Programmazione_I/ANSI-C/UNIME/LetturaDaFile/LetturaDaFile/fileManager.txt";
    FILE * fp = open_fileManager(pattern);
  persona v[DIM];
  int k=0;
  FILE* f;
{ if ((f=fopen(fp, "r"))==NULL)
perror("Il file non esiste!");
exit(1); }
while(fscanf(f,"%10c%10c%c%d\n", v[k].cognome, v[k].nome, &v[k].sesso, &v[k].anno ) != EOF){
     v[k].cognome[10]=v[k].nome[10]='\0';
    k++;
}
    for (int i=0; i<k; i++){
        printf("%s %s %c %d\n", v[i].cognome, v[i].nome, v[i].sesso);
}
       }
