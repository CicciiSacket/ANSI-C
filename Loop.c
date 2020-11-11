//
//  main.c
//  Ciclo
//
//  Created by Francesco Sacco on 14/02/2020.
//  Copyright © 2020 Francesco Sacco. All rights reserved.
//

#include <stdio.h>

int main(void){
    
    int x = 0;
    int y = -x*x + 10*x +10;

    
    
    while (y>=0) {
        y= -x*x + 10*x + 10;
        
        printf("x=%d y=%d \n",x, y);
        x++;
    }
    
}

