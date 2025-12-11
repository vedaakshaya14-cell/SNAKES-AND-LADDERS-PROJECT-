#include <stdio.h>
#include <stdlib.h>

int checkPosition(int pos) {
    // Ladders
    if (pos == 3)  return 22;
    if (pos == 5)  return 8;
    if (pos == 11) return 26;
    if (pos == 20) return 29;

    // Snakes
    if (pos == 17) return 4;
    if (pos == 19) return 7;
    if (pos == 21) return 9;
    if (pos == 27) return 1;

    return pos;
}

int main() {
    int player1 = 0, player2 = 0, dice;
    int turn = 1;

    while (player1 < 100 && player2 < 100) {

        printf("\nEnter dice value (1–6) for Player %d: ", turn);
        scanf("%d", &dice);

        // Validate input
        if (dice < 1 || dice > 6) {
            printf("Invalid dice value! Enter between 1 and 6.\n");
            continue;
        }

        if (turn == 1) {
            player1 += dice;
            if (player1 <= 100)
                player1 = checkPosition(player1);

            printf("Player 1 is now at position: %d\n", player1);
            turn = 2;

        } else {
            player2 += dice;
            if (player2 <= 100)
                player2 = checkPosition(player2);

            printf("Player 2 is now at position: %d\n", player2);
            turn = 1;
        }
    }

    if (player1 >= 100)
        printf("\nPlayer 1 Wins!\n");
    else
        printf("\nPlayer 2 Wins!\n");

    return 0;
}
