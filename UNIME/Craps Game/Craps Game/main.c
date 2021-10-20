//
//  main.c
//  Craps Game [Se la somma dei dadi è 7 oppure 11 user vince, user perde se la somma è 2 o 3; Qualsiasi altra uscita prende il nume di "punto" e il gioco continua, si arriva alla vittoria se esce di nuovo il punto mentre si perde se esce il 7.]
//
//  Created by Francesco_Utility on 18/10/21.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int roll_dice(void) { //Genera due numeri casuali da tra 1 e 6 e ne restituisce la somma
    return((rand() % 7) + (rand() % 7));
}

bool play_game(void) { //Gioca la partita chiamando roll_dice, visualizza gli esiti dei vari lanci e ritorna true se l'utente vince altrimenti false;
    int sum = roll_dice();
    printf("Your sum is: %d \n", sum);
    if (sum == 7 || sum == 11) {
        return true;
    }
    if (sum == 2 || sum == 3) {
        return false;
    }
    else{
        int sumSecondary = roll_dice();
        if(sumSecondary == sum) {
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) { //Tiene conto delle vittorie e delle sconfitte chiamando play_game e chiedendo se si vuole giocare ancora
    bool game = play_game();
    if(game == true) {
        printf("User win \n");
    }
    else {
        printf("User lose \n");
    }
}
