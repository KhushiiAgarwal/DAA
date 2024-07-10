#include <stdio.h>
int count=0;
 
void towerOfHanoi(int n, char src, char mid, char dest) {
 
    if (n == 1) {
 
        printf("Move disk 1 from %c to %c\n", src, dest);
 
        count++;
 
        return;
 
    }
 
    towerOfHanoi(n - 1, src, dest, mid);
 
    printf("Move disk %d from %c to %c\n", n, src, dest);
 
    count++;
 
    towerOfHanoi(n - 1, mid, src, dest);
 
}
 
 
int main() {
 
    int n;
 
    printf("Enter the number of disks: ");
 
    scanf("%d", &n);
 
 
    towerOfHanoi(n, 'A', 'B', 'C');
 
    printf("Total moves: %d",count);
 
 
    return 0;
 
}
