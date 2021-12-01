//
//  main.c
//  Puntatori
//
//  Created by Francesco_Utility on 01/12/21.
//

#include <stdio.h>

//PUNTATORI USATI COME ARGOMENTI
int max(int a[], int *max) { //si utilizza CONST invece davanti il tipo del puntatore per definire il fatto che la funzione non modificherà il valore di p;
    int i;
    int n = 10; //lunghezza array
    *max = a[0];
    for (i = 1; i < n; i++) {
        if (a[i] > *max) {
            *max = a[i];
        }
    }
    return *max;
}


//PUNTATORI USATI COME VALORI RESTITUITI
int *maxV(int *a, int *b) { //si utilizza const invece davanti il tipo del puntatore per definire il fatto che la funzione non modificherà il valore di p;
    if(*a > *b) {
        return a;
    }
    else {
        return b;
    }
}


int main(int argc, const char * argv[]) {
    
    int i = 5;
    int *p; //variabile puntatore che punta un intero;
    
    p = &i; //variabile p che punta ad i; È un assegnamento ad un puntatore
    //Dato che p punta ad i, l'espressione *p è un alias per i, qualora cambi il valore di i cambia anche il valore di *p;
    printf("%d\n",*p); //5
    printf("%d\n",i); //5
    i = 3;
    printf("%d\n",*p); //3
    printf("%d\n",i); //3
    *p = 10;
    printf("%d\n",i); //10
    printf("%d\n",*p); //10
    
    printf("\n\n\n");
    int j = 0;
    int a[] = {1,2,3,45,5,6,7,8,9,11};
    printf("%d\n",max(a, &j));
    
    printf("\n\n\n");
    int *f;
    int l = 22;
    int m = 11;
    f = maxV(&l, &m); //*a *b della firma della funzione sono alias di l e m;
    printf("%d\n",*f);
    
    printf("\n\n\n");
    return 0;
}
