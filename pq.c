#include <stdio.h>
#include <math.h>
#define MAX 20

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int main() {
    int arrival[MAX];
    int burst[MAX];
    int prior[MAX];
    int n, i, j, temp, temp1, temp2, tot = 0;
    float avg = 0.0, wait = 0.0;
    int t1 = 0, t2 = 0;
    
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter the arrival time for job %d: ", i + 1);
        scanf("%d", &arrival[i]);
        printf("Enter the burst time for job %d: ", i + 1);
        scanf("%d", &burst[i]);
        printf("Enter the priority for job %d: ", i + 1);
        scanf("%d", &prior[i]);
    }
    
    printf("\nPriority \t Arrival \t Burst time \t Turnaround time\n");
    
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (prior[i] < prior[j]) {
                swap(prior, i, j);
                swap(arrival, i, j);
                swap(burst, i, j);
            }
        }
        
        tot += burst[i];
        printf("%d \t\t %d \t\t %d \t\t %d\n", prior[i], arrival[i], burst[i], tot);
    }
    
    for (i = 0; i < n; i++) {
        t1 = t2;
        t2 += burst[i];
        printf("\nWaiting time for job %d is: %d", i + 1, t1);
        wait += t1;
    }
    
    avg = wait / n;
    printf("\n\nThe average waiting time is %.2f\n", avg);
    
    return 0;
}
