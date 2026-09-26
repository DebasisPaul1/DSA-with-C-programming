#include <stdio.h>

int board[20][20];
int n;

int safe(int row, int col) {
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return 0;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j])
            return 0;

    return 1;
}

int solve(int row) {
    if (row == n)
        return 1;

    for (int col = 0; col < n; col++) {
        if (safe(row, col)) {
            board[row][col] = 1;

            if (solve(row + 1))
                return 1;

            board[row][col] = 0;
        }
    }

    return 0;
}

int main() {
    printf("Enter number of queens: ");
    scanf("%d", &n);

    if (solve(0)) {
        printf("Solution:\n");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                printf("%d ", board[i][j]);
            printf("\n");
        }
    }
    else
        printf("No solution\n");

    return 0;
}
