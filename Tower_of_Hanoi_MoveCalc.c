 
#include <stdio.h>
#include <math.h>
 
 
int disk_moved(int n, int k) {
 
    int count = 0;
 
    for (int i = 0; i < n; i++) {
 
        int m = (int)pow(2, i);
 
        if (k < m) {
 
            break;
 
        } else if (k == m) {
 
            return n - 1;
 
        } else {
 
            k -= m;
 
            count++;
 
        }
 
    }
 
    int lastDisk = n - 1;
 
    while (count > 0) {
 
        lastDisk--;
 
        count--;
 
    }
 
    return lastDisk;
 
}
 
 
int main() {
 
    int n, k;
 
    printf("Enter the number of disks (n): ");
 
    scanf("%d", &n);
 
    printf("Enter the move number (k): ");
 
    scanf("%d", &k);
 
 
    int maxMoves = (int)pow(2, n) - 1;
 
    if (k < 1 || k > maxMoves) {
 
        printf("Invalid move number!\n");
 
        return 1;
 
    }
 
    int diskNumber = disk_moved(n, k);
 
    printf("Disk %d will be moved after the %dth move.\n", diskNumber, k);
 
    return 0;
 
}
