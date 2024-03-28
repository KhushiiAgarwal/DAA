#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int tileCount = 1;

void fillBoard(int **grid, int size, int xStart, int yStart, int xHole, int yHole) {
    if (size == 1)
        return;

    int halfSize = size / 2;
    int xMid = xStart + halfSize;
    int yMid = yStart + halfSize;
    int tile = tileCount++;

    if (xHole < xMid && yHole < yMid) {
        grid[xMid][yMid] = grid[xMid][yMid - 1] = grid[xMid - 1][yMid] = tile;
        fillBoard(grid, halfSize, xStart, yStart, xHole, yHole);
        fillBoard(grid, halfSize, xStart, yMid, xMid - 1, yMid);
        fillBoard(grid, halfSize, xMid, yStart, xMid, yMid - 1);
        fillBoard(grid, halfSize, xMid, yMid, xMid, yMid);
    } else if (xHole < xMid && yHole >= yMid) {
        grid[xMid][yMid - 1] = grid[xMid - 1][yMid - 1] = grid[xMid][yMid] = tile;
        fillBoard(grid, halfSize, xStart, yStart, xMid - 1, yMid - 1);
        fillBoard(grid, halfSize, xStart, yMid, xHole, yHole);
        fillBoard(grid, halfSize, xMid, yStart, xMid, yMid - 1);
        fillBoard(grid, halfSize, xMid, yMid, xMid, yMid);
    } else if (xHole >= xMid && yHole < yMid) {
        grid[xMid - 1][yMid] = grid[xMid][yMid] = grid[xMid - 1][yMid - 1] = tile;
        fillBoard(grid, halfSize, xStart, yStart, xMid - 1, yMid - 1);
        fillBoard(grid, halfSize, xStart, yMid, xMid - 1, yMid);
        fillBoard(grid, halfSize, xMid, yStart, xHole, yHole);
        fillBoard(grid, halfSize, xMid, yMid, xMid, yMid);
    } else {
        grid[xMid - 1][yMid - 1]=grid[xMid - 1][yMid] = grid[xMid][yMid - 1]=tile;
        fillBoard(grid, halfSize, xStart, yStart, xMid - 1, yMid - 1);
        fillBoard(grid, halfSize, xStart, yMid, xMid - 1, yMid);
        fillBoard(grid, halfSize, xMid, yStart, xMid, yMid - 1);
        fillBoard(grid, halfSize, xMid, yMid, xHole, yHole);
    }
}

void showGrid(int **grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == 0)
                printf(" x ");
            else
                printf(" %d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, x, y;
    printf("Enter n:");
    scanf("%d", &n);
    printf("Enter x and y for removal of tile:");
    scanf("%d %d", &x, &y);

    int size = (int)pow(2, n);
    int **grid = (int **)malloc(size * sizeof(int *));
    for (int k = 0; k < size; k++) {
        grid[k] = (int *)malloc(size * sizeof(int));
    }
    for (int k = 0; k < size; k++) {
        for (int l = 0; l < size; l++) {
            grid[k][l] = 0;
        }
    }
    fillBoard(grid, size, 0, 0, x, y);
    showGrid(grid, size);
    for (int k = 0; k < size; k++) {
        free(grid[k]);
    }
    free(grid);
    return 0;
} 
