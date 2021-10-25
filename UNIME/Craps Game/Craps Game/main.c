//
//  Craps Game [Book exercise]
//  Created by Francesco_Utility on 18/10/21.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int roll_dice(void) {
    return((rand() % 7) + (rand() % 7));
}

bool Game(void) {
    int sum = roll_dice();
    printf("\nYour sum is: %d \n", sum);
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

int PlayGame(int win, int lose) {
    bool game = Game();
    if(game == true) {
        win+=1;
       printf("User win\n");
    }
    else {
        lose+=1;
        printf("User lose\n");
    }
    
    printf("Current victories: %d\n",win);
    printf("Current defeats: %d\n",lose);
    
    char choose;
    printf("\nAnother play? \n" );
    scanf("%s",&choose);
    if (choose == 'y'|| choose == 'Y' ) {
       PlayGame(win,lose);
    }
    if (choose == 'n' || choose == 'N') {
        printf("\nGoodbay!\n\n" );
        return 0;
    }
    else {
        return 0;
    }
}

int main(int argc, const char * argv[]) {
    int win = 0;
    int lose = 0;
    printf("Welcome to Craps Game!\n" );
    PlayGame(win,lose);
}
