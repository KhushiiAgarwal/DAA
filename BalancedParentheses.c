//Balanced Parentheses Enumeration
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *str;
    int openCount;
    int closeCount;
} ParenthesesCombination;

void initializeCombination(ParenthesesCombination *comb, int n) {
    comb->str = (char *)malloc((2 * n + 1) * sizeof(char));
    comb->str[0] = '\0';
    comb->openCount = 0;
    comb->closeCount = 0;
}

void freeCombination(ParenthesesCombination *comb) {
    free(comb->str);
}

void generateParentheses(int n, ParenthesesCombination *comb, int index) {
    if (index == 2 * n) {
        printf("%s\n", comb->str);
        return;
    }

    if (comb->openCount < n) {
        comb->str[index] = '(';
        comb->str[index + 1] = '\0';
        comb->openCount++;
        generateParentheses(n, comb, index + 1);
        comb->openCount--;
    }

    if (comb->closeCount < comb->openCount) {
        comb->str[index] = ')';
        comb->str[index + 1] = '\0';
        comb->closeCount++;
        generateParentheses(n, comb, index + 1);
        comb->closeCount--;
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("No balanced parentheses to generate.\n");
        return 0;
    }
    ParenthesesCombination combination;
    initializeCombination(&combination, n);
    generateParentheses(n, &combination, 0);
    freeCombination(&combination);

    return 0;
}
