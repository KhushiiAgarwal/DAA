#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmp[50][50];
int n;

int partition(int a[], int min, int max) {
    int right = max, left = min, flag = 0;
    int index =(max - min + 1) + min;
    while (flag != 1) {
        while ((a[index] <= a[right]) && (index != right)) {
            cmp[a[index]][a[right]]++;
            cmp[a[right]][a[index]]++;
            right--;
        }
        if (index == right) {
            flag = 1;
        } else if (a[index] > a[right]) {
            int temp;
            temp = a[index];
            a[index] = a[right];
            a[right] = temp;
            index = right;
        }
        if (flag != 1) {
            while (a[index] >= a[left] && (index != left)) {
                cmp[a[left]][a[index]]++;
                cmp[a[index]][a[left]]++;
                left++;
            }
            if (index == left) {
                flag = 1;
            } else if (a[index] < a[left]) {
                int temp;
                temp = a[index];
                a[index] = a[left];
                a[left] = temp;
                index = left;
            }
        }
    }
    return index;
}

void quick_sort(int a[], int min, int max) {
    int index;
    if (min < max) {
        index = partition(a, min, max );
        quick_sort(a, min, index - 1);
        quick_sort(a, index + 1, max);
    }
}

int main() {
    int i, j, arr[50], iterations;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        arr[i] = i;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cmp[i][j] = cmp[j][i] = 0;
        }
    }

    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);

    for (i = 0; i < iterations; i++) {
        int arr_copy[50];
        for (j = 0; j < n; j++) {
            arr_copy[j] = arr[j];
        }
        quick_sort(arr_copy, 0, n - 1);
    }

    printf("\nThe average matrix formed after %d iterations is\n", iterations);

    for (i = 0; i < n; i++) {
        printf("\t%d", arr[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t", arr[i]);
        for (j = 0; j < n; j++) {
            printf("%.2f\t", (float)cmp[i][j] / iterations); 
        }
        printf("\n");
    }
    return 0;
}
