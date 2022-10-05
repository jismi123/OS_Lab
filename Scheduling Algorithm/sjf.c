#include <stdio.h>
struct process
{
    int wt,bt,tat,at;
};

struct process a[10];

int main()
{
    int n,i,temp[10],t,count=0,tot_wt=0,tot_tat=0,short_p;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter burst time and arrival time\n");
    printf("\nAT\tBT\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].at,&a[i].bt);
        temp[i]=a[i].bt;
    }
    
    a[9].bt=10000;
    for(t=0;count!=n;t++)
    {
        short_p=9;
        for(i=0;i<n;i++)
        {
            if(a[i].bt<a[short_p].bt && (a[i].at<=t && a[i].bt>0))
                short_p=i;
        }
        a[short_p].bt=a[short_p].bt-1;
        if(a[short_p].bt==0)
        {
            count++;
            a[short_p].wt=t+1-a[short_p].at-temp[short_p];
            a[short_p].tat=t+1-a[short_p].at;
            tot_wt+=a[short_p].wt;
            tot_tat+=a[short_p].tat;
        }
    }
    printf("\nPNO\tAT\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d\n",i+1,a[i].at,temp[i],a[i].wt,a[i].tat);
    }
    printf("\nAverage Waiting time is %f\nAverage Turn Around Time is %f",(float)tot_wt/(float)n,(float)tot_tat/(float)n);
}
