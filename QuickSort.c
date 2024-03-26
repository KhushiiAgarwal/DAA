#include <stdio.h>

int cmp[50][50];

int partition(int a[], int min, int max) {
    int ind = min, right = max, left = min, flag = 0;
    while (flag != 1) {
        while ((a[ind] <= a[right]) && (ind != right)) {
            cmp[a[ind]][a[right]]++;
            cmp[a[right]][a[ind]]++;
            right--;
        }
        if (ind == right) {
            flag = 1;
        } else if (a[ind] > a[right]) {
            int temp;
            temp = a[ind];
            a[ind] = a[right];
            a[right] = temp;
            ind = right;
        }
        if (flag != 1) {
            while (a[ind] >= a[left] && (ind != left)) {
                cmp[a[left]][a[ind]]++;
                cmp[a[ind]][a[left]]++;
                left++;
            }
            if (ind == left) {
                flag = 1;
            } else if (a[ind] < a[left]) {
                int temp;
                temp = a[ind];
                a[ind] = a[left];
                a[left] = temp;
                ind = left;
            }
        }
    }
    return ind;
}

void quick_sort(int arr[], int min, int max) {
    int index;
    if (min < max) {
        index = partition(arr, min, max);
        quick_sort(arr, min, index - 1);
        quick_sort(arr, index + 1, max);
    }
}

int main() {
    int n,i,j, arr[50];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      printf("Enter element %d:",i+1);
      scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            cmp[i][j] = cmp[j][i] = 0;
        }
    }

    quick_sort(arr, 0, n - 1);

    printf("\nSorted array:");
    for (i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    
    printf("\n\nCount matrix:\n");
    for (i = 0; i < n; i++) {
        printf("\t%d", arr[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
        for (j = 0; j < n; j++) {
            printf("%d\t",  cmp[i][j]);
        }
        printf("\n");
    }

}
