//
//  Craps Game [Page xxx Exercise number xxx]
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

char PrintResult(void) {
    bool game = Game();
    if(game == true) {
        return 'W';
    }
    else {
        return 'L';
    }
}

int PlayGame(void) {
    char printResult = PrintResult();
    if(printResult == 'W') {
        printf("User win \n");
    }
    else if (printResult == 'L'){
        printf("User lose \n");
    }
    char choose;
    printf("Another play? \n" );
    scanf("%s",&choose);
    if (choose == 'y'|| choose == 'Y' ) {
       PlayGame();
    }
    if (choose == 'n' || choose == 'N') {
        return 0;
    }
    else {
        return 0;
    }
}

int main(int argc, const char * argv[]) {
    PlayGame();
}
