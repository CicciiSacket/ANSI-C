//
//  main.c
//  Esercizio febbraio 4
//
//  Created by Francesco Sacco on 17/02/2020.
//  Copyright © 2020 Francesco Sacco. All rights reserved.
//switch case e do wile(1 stampa pippo/2 stampa pluto/3 stampa 2+2=4/4stampa il risultato di (2*2)*5+4/0 esci}


#include<stdio.h>

int main()
{
    int x;
    x=(2*2);
    int y;
    y=((2*2)*5+4);
    int I;
    do
    {
        printf("Insert value from 1 to 4, select 0 to exit.\n");
        scanf("%d",&I);
      switch(I)
      {
        case 1:
              printf("PIPPO \n");
              break;
        case 2:
              printf("PLUTO \n");
              break;
        case 3:
              printf("%d\n",x);
              break;
        case 4:
              printf("%d\n",y);
              break;
        case 0:
              return 0;
      }
    }
    while(I>0);
        return 0;
}
