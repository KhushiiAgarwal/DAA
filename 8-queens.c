#include <stdio.h>
#include <stdbool.h>


int board[8][8];
void printBoard(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", board[i][j] ? '1' : '0');
        }
        printf("\n");
    }
}

bool isSafe(int row, int col, int n) {
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }
    return true;
}
bool solveNQueens(int col, int n) {
    if (col >= n) {
        return true; 
    }
    for (int i = 0; i < n; i++) {
        if (isSafe(i, col, n)) {
            board[i][col] = 1; 
            if (solveNQueens(col + 1, n)) {
                return true; 
            }
            board[i][col] = 0;
        }
    }
    return false; 
}

int main() {
    int n=8;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }
    if (solveNQueens(0, n)) {
        printf("Solution exists:\n");
        printBoard(n);
    } else {
        printf("No solution exists.\n");
    }
    return 0;
}
