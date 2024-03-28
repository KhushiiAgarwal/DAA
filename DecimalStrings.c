Generate all decimal strings of length n which do not contain consecutive occurrences of digit d using Dynamic Programming

#include <stdio.h>

void generateDecimalStrings(int n, char *current, int index, char prev, char d) {
    if (index == n) {
        printf("%s\t", current);
        return;
    }
    for (char digit = '0'; digit <= '9'; digit++) {
        if (digit == d && prev == d) {
            continue; 
        }
        current[index] = digit; 
        generateDecimalStrings(n, current, index + 1, digit, d);
    }
}

int main() {
    int n;
    char d;
    printf("Enter the length of decimal strings (n): ");
    scanf("%d", &n);
    printf("Enter the digit to avoid consecutive occurrences (d): ");
    scanf(" %c", &d);

    if (n <= 0) {
        printf("Invalid input for n.\n");
        return 1;
    }
    if (d < '0' || d > '9') {
        printf("Invalid input for d. It must be a digit (0-9).\n");
        return 1;
    }
    char current[n + 1]; 
    generateDecimalStrings(n, current, 0, ' ', d);
    return 0;
}
