#include <stdio.h>
/* numeri */
int main() {
    int primo_numero;
    int secondo_numero;
     
    printf("digita il primo numero:");
     scanf("%d", &primo_numero);
    
    printf("digita il secondo numero:");
     scanf("%d", &secondo_numero);

    
    if (primo_numero > secondo_numero)
        printf("%d\n", primo_numero);
    else
        printf("%d\n", secondo_numero);
    
    
    return 0;
}

