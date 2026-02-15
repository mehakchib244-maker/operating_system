#include <stdio.h>

int main() {
    int n;
    int at[20], bt[20], ct[20], tat[20], wt[20], pid[20],total_tat = 0, total_wt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time for P%d: ", pid[i]);
        scanf("%d", &at[i]);
        printf("Enter Burst Time for P%d: ", pid[i]);
        scanf("%d", &bt[i]);
    }

    // Sorting by Arrival Time (FCFS)
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {//second number he hoga j kyuki a[0]jo hai woh i aur j a[i+1] se start hoga end tak jayega taki woh compare ho sake
            if(at[i] > at[j]) { //  Swap processes based on arrival time i is outer loop current position, j is next position it will start from i+1 to end of array, if at[i] is greater than at[j] then swap 
                int temp;
//if condition is true then swap arrival time, burst time and process id
                temp = at[i]; at[i] = at[j]; at[j] = temp; //swap arrival time
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;//swap bt kyuki sabka oreder change hoga
                temp = pid[i]; pid[i] = pid[j]; pid[j] = temp;
            }
        }
    }

    // First process
    ct[0] = at[0] + bt[0]; // completion time of first process is arrival time + burst time start at its at and completes after its burst time

    // Remaining processes
    for(int i = 1; i < n; i++) {
        if(ct[i-1] < at[i])//previous process finished before next arrived ..>cpu idle time
            ct[i] = at[i] + bt[i];// ex prev ct =5 , current at =8 ...> cpu idle from 5 to 8 then current process starts at 8 and completes at 8+bt[i]
        else
            ct[i] = ct[i-1] + bt[i];//previous process finished after next arrived ..> no idle time current process starts immediately after previous process completes at ct[i-1] and completes at ct[i-1]+bt[i]
    } //ex ct[0]=5, at[1]=3, bt[1]=4 ...> ct[1] = 5+4 = 9

    for(int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);

    }

    printf("\nAverage Turnaround Time = %.2f", (float)total_tat / n);
    printf("\nAverage Waiting Time = %.2f", (float)total_wt / n);

    return 0;
}
