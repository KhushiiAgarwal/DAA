#include <stdio.h>
#define MAX_SIZE 100

void enqueue(int *queue, int *rear, int value) {
    *rear = (*rear + 1) % MAX_SIZE;
    queue[*rear] = value;
}
int dequeue(int *queue, int *front) {
    int value = queue[*front];
    *front = (*front + 1) % MAX_SIZE;
    return value;
}
int Josephus(int n) {
    int queue[MAX_SIZE];
    int front = 0, rear = -1;
    for (int i = 1; i <= n; i++) {
        enqueue(queue, &rear, i);
    }
    while (front != rear) {
        dequeue(queue, &front); 
        int alternate = dequeue(queue, &front); 
        enqueue(queue, &rear, alternate); 
    }
    return queue[front] + 1;
}
int main() {
    int n;
    printf("Enter the total number of people: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX_SIZE) {
        printf("Invalid input.\n", MAX_SIZE);
        return 1;
    }
    int winner = Josephus(n);
    printf("The winner is person %d\n", winner);
    return 0;
}
