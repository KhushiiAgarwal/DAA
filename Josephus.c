	#include <stdio.h>	
void Jos(int *arr, int size, int n) {
    int i=1;
    while(i<=size) {
        arr[i]=(arr[i] + n) % i;
        i++; 
    }
}
int main() {
    int size, n = 2;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
    Jos(arr, size, n);
    printf("Winner is %d", arr[size - 1]);
    return 0;
}
