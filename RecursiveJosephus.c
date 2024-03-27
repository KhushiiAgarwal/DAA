#include <stdio.h>
int Jos(int n,int k) {
    if (n == 1) {
        return 1; // Base case: Only one person, the winner is 1.
    } else if (n % k == 0) {
        return k * (Jos(n / k ,k) - 1) + 1;
    } else {
        return k * Jos(n / k, k ) + 1;
    }
}
int main() {
    int k=2, n;
    printf("Enter the total number of people: ");
    scanf("%d", &n);
    int winner = Jos(n,k);
    printf("The winner is person %d\n", winner);
    return 0;
}
