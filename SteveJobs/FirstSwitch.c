
#include<stdio.h>

int main(){
    
    int Menù;
    printf("scegli il programma che preferisci: \n");
    scanf("%d", &Menù);
    switch (Menù) {
        case 1: printf("hai scelto programma triangolo: \n");
           
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

        break;
        case 2: printf("hai scelto programma altezza: \n");
                int età;
                int altezza;
                
                printf("inserire età: \n");
                scanf("%d", &età);
                printf("inserire altezza: \n");
                scanf("%d", &altezza);
                printf("la tua altezza\n");
                
            //    if (età <= 0 || altezza <= 0){
            //        printf("ERRORE");
            //    }
                
                if ((altezza >= 250) |  (età >= 6 & altezza <80)){
                    printf("non");}
                printf(" è nella norma \n");
                
                return 0;
            //||non valuta il secondo argomento se verifica 1//
        break;
        case 3: printf("hai scelto programma data: \n");
                
                int mese;
                int anno;
                
                
                printf("inserire il mese: \n");
                scanf("%d", &mese);
                
                if(mese >12) {
                    printf("Attenzione i mesi del calendario sono 12. \n");
                    return 1;
                }
                
                if (mese <1){
                    printf("Attenzione i mesi del calendario sono 12. \n");
                    return 1;
                    
                }
                
                printf("inserire l'anno: \n");
                scanf("%d", &anno);
                
                if (mese == 12) {
                    printf("il mese é: %d \n", 1);
                    printf("l'anno é: %d \n", anno+1);
                } else {
                    printf("il mese é: %d \n", mese+1);
                    printf("l'anno é: %d \n", anno);
                }
                
                return 0;
        break;
        case 4: printf("hai scelto il programma smistamento alunni: \n");
            
               int numero_studenti;
               int numero_gruppi;
               int gruppi_realizzabili;
               int alunni_esclusi;

               printf("digitare numero di studenti: \n");
               scanf("%d", &numero_studenti);
               
               printf("digitare numero gruppi: \n");
               scanf("%d", &numero_gruppi);
               
               gruppi_realizzabili = (numero_studenti / numero_gruppi);
               alunni_esclusi = (numero_studenti % numero_gruppi);
               
               printf("il numero di gruppo realizzabili é: \n");
              
               printf("%d \n", gruppi_realizzabili);
               
               printf("gli alunni spaiati sono: \n");
               
               printf("%d \n", alunni_esclusi);
               
               if(alunni_esclusi > 4)
                   printf("É possibile creare un gruppo con gli alunni rimanenti. \n");
               else
                   printf("il numero di alunni che rimangono spaiati non é sufficiente per creare nessun altro gruppo. \n");

               return 0;
        break;
        case 5: printf("hai scelto di uscire. \n");
            return 0;
            
        default: printf("hai scelto un programma che ancora non c'è. \n");
            return 0;
  }
}
