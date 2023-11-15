#include <stdio.h>

#define N 4


void printBoard(char board[N]) {
    for (int i = 0; i < N; i++) {
        printf("%c ", board[i]);
    }
    printf("\n");
}


int calculateUtility(char board[N]) {
    int utility = 0;
    for (int i = 0; i < N; i++) {
        if (board[i] == 'B') {
            utility++;
        }
    }
    return utility;
}


int miniMax(char board[N], int depth, int isMax) {
   
    int utility = calculateUtility(board);
    if (utility == N || utility == 0) {
        return utility;
    }

   
    if (isMax) {
        int maxEval = -1000;
        for (int i = 0; i < N; i++) {
            if (board[i] == '0') {
                board[i] = 'B';
                int eval = miniMax(board, depth + 1, !isMax);
                board[i] = '0'; 
                maxEval = (eval > maxEval) ? eval : maxEval;
            }
        }
        return maxEval;
    }


    else {
        int minEval = 1000;
        for (int i = 0; i < N; i++) {
            if (board[i] == '0') {
                board[i] = 'W';
                int eval = miniMax(board, depth + 1, !isMax);
                board[i] = '0'; 
                minEval = (eval < minEval) ? eval : minEval;
            }
        }
        return minEval;
    }
}

int main() {
    char board[N] = "0000W00BBW0"; 
    printf("Initial state of the board:\n");
    printBoard(board);

    int utility = miniMax(board, 0, 1); 
    printf("\nUtility of Player 1 using Mini-Max algorithm: %d\n", utility);

    return 0;
}
