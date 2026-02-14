int main() {
    int n=4;
    
    int p[]={1,2,3,4};
    int at[] = {0,0,0,0};
    int bt[]={2,2,3,4};
    int ct[20];int tat[20];int wt[20];
    ct[0]=bt[0]; //because only first index is same
    for(int i=1;i<n;i++){
        ct[i]=ct[i-1]+bt[i]; //ct[i-1] is the privious completion time
    }
        for(int i=1;i<n;i++){
            tat[i]= ct[i];//tat is ct-at as is 0
             wt[i]=tat[i]-bt[i];
        }
        
    printf("P\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

        
    }
