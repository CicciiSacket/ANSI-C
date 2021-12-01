
//  Created by Francesco Sacco on 24/01/2020.
//  Copyright © 2020 Francesco Sacco. All rights reserved.
//

#include <stdio.h>

int main() {
    
    int lato_a;
    int lato_b;
    int lato_c;
    
    printf("Inserire lato a: \n");
    scanf("%d", &lato_a);
    printf("Inserire lato b: \n");
    scanf("%d", &lato_b);
    printf("Inserire lato c: \n");
    scanf("%d", &lato_c);
     
    if (lato_a <= 0 || lato_b <= 0 || lato_c <= 0) {
         printf("Non esistono triangoli con lati negativi o nulli \n");
         return 1;
    }

    if ((lato_b+lato_c) <= lato_a){
        printf("Non è possibile formare un triangolo \n");
        return 1;
    }
    if ((lato_c+lato_a) <= lato_b){
        printf("Non è possibile formare un triangolo \n");
        return 1;
    }
    if ((lato_b+lato_a) <= lato_c)
        printf("Non è possibile formare un triangolo \n");
        
    if (lato_a == lato_b && lato_b == lato_c){
           printf("Il tuo triangolo è equilatero\n");
    }
    if (lato_a == lato_c || lato_b == lato_c || lato_a == lato_b) {
         printf("Il tuo triangolo è isoscele\n");
            } else
           printf("Il tuo triangolo è scaleno\n");
    return 0;
}
