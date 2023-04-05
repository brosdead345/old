#include <stdio.h>
#include <string.h>

#define MAX_PROCESSES 10

int main()
{
    char pn[MAX_PROCESSES][10], t[10];
    int arr[MAX_PROCESSES], bur[MAX_PROCESSES], star[MAX_PROCESSES], finish[MAX_PROCESSES], tat[MAX_PROCESSES], wt[MAX_PROCESSES];
    int i, j, n, temp, totwt = 0, tottat = 0;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the ProcessName, Arrival Time& Burst Time:");
        scanf("%s %d %d", &pn[i], &arr[i], &bur[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                temp = bur[i];
                bur[i] = bur[j];
                bur[j] = temp;
                strcpy(t, pn[i]);
                strcpy(pn[i], pn[j]);
                strcpy(pn[j], t);
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (i == 0)
            star[i] = arr[i];
        else
            star[i] = finish[i - 1];
        wt[i] = star[i] - arr[i];
        finish[i] = star[i] + bur[i];
        tat[i] = finish[i] - arr[i];
    }
    printf("\nPName Arrtime Burtime WaitTime Start TAT Finish");
    for (i = 0; i < n; i++)
    {
        printf("\n%s\t%3d\t%3d\t%3d\t%3d\t%6d\t%6d", pn[i], arr[i], bur[i], wt[i], star[i], tat[i], finish[i]);
        totwt += wt[i];
        tottat += tat[i];
    }
    printf("\nAverage Waiting time:%f", (float)totwt / n);
    printf("\nAverage Turn Around Time:%f", (float)tottat / n);
    return 0;
}
