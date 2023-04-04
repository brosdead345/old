#include <stdio.h>

int main() {
    int n, bt[10], wt[10], tat[10], i, swt = 0, stat = 0;
    float awt, atat;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the burst time of process P%d: ", i+1);
        scanf("%d", &bt[i]);
        printf("\n");
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        swt += wt[i];
    }

    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        stat += tat[i];
    }

    awt = (float) swt / n;
    atat = (float) stat / n;
    printf("\nAvg waiting time = %.2f", awt);
    printf("\nAvg turnaround time = %.2f\n", atat);

    printf("\nProcess\tCPU Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf(" P%d\t\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    printf("\n****** Gantt Chart ******\n");
    printf("|");
    for (i = 0; i < n; i++) {
        printf("  P%d  |", i+1);
    }
    printf("\n0");
    for (i = 0; i < n; i++) {
        printf("      %d", tat[i]);
    }

    return 0;
}
