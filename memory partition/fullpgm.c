#include<stdio.h>

int main()
{
    int n,m,i;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    printf("Enter the number of blocks:");
    scanf("%d",&m);
    int blocksize1[m],processsize1[n],blocksize2[m],blocksize3[m],processsize2[n],processsize3[n];
    printf("Enter the block sizes:");
    for(i=0;i<m;i++)
    {
        scanf("%d",&blocksize1[i]);
        blocksize2[i]=blocksize1[i];
        blocksize3[i]=blocksize2[i];
    }
    printf("Enter the process sizes:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&processsize1[i]);
        processsize2[i]=processsize1[i];
        processsize3[i]=processsize2[i];
    }
    firstfit(blocksize1,m,processsize1,n);
    bestfit(blocksize2,m,processsize2,n);
    worstfit(blocksize3,m,processsize3,n);
    return 0;
}

void firstfit(int blocksize1[],int m,int processsize1[],int n)
{
    int i,j;
    int allocation[n];
    for(i=0;i<n;i++)
    {
        allocation[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(blocksize1[j]>=processsize1[i])
            {
                allocation[i]=j;
                blocksize1[j]-=processsize1[i];
                break;
            }
        }
    }
    printf("\nprocess number\tprocess size\tblock num\n");
    for(int i=0;i<n;i++)
    {
        printf("\n%d \t\t%d \t\t",i+1,processsize1[i]);
        if(allocation[i]!=-1)
        {
            printf("%d",allocation[i]+1);
        }
        else
        {
            printf("Not allocated");
        }
    }
}

void bestfit(int blocksize2[],int m,int processsize2[],int n)
{  
    int i,j,best;
    int allocation2[n];
    for(i=0;i<n;i++)
    {
        allocation2[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        best=-1;
        for(j=0;j<m;j++)
        {
           if(blocksize2[j]>=processsize2[i])
           {
               if(best==-1)
               {
                   best=j;
               }
           
               else if(blocksize2[best]>blocksize2[j])
               {
                    best=j;
               }
           }
        }
        if(best!=-1)
        {
            allocation2[i]=best;
            blocksize2[best]-=processsize2[i];
        }
    }
    printf("\n------BEST FIT------");
    printf("\nprocess number\tprocess size\tblock num\n");
    for(int i=0;i<n;i++)
    {
        printf("\n%d \t\t%d \t\t",i+1,processsize2[i]);
        if(allocation2[i]!=-1)
        {
            printf("%d",allocation2[i]+1);
        }
        else
        {
            printf("Not allocated");
        }
    }
}

void worstfit(int blocksize3[],int m,int processsize3[],int n)
{
    int i,j,worst;
    int allocation3[n];
    
    for(i=0;i<n;i++)
    {
        allocation3[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        worst=-1;
        for(j=0;j<m;j++)
        {
           if(blocksize3[j]>=processsize3[i])
           {
               if(worst==-1)
                worst=j;
               else if(blocksize3[worst]<blocksize3[j])
                worst=j;
           }
        }
        if(worst!=-1)
        {
            allocation3[i]=worst;
            blocksize3[worst]-=processsize3[i];
        }
    }
    printf("\n------WORST FIT------");
    printf("\nprocess number\tprocess size\tblock num\n");
    for(int i=0;i<n;i++)
    {
        printf("\n%d \t\t%d \t\t",i+1,processsize3[i]);
        if(allocation3[i]!=-1)
        {
            printf("%d",allocation3[i]+1);
        }
        else
        {
            printf("Not allocated");
        }
    }
}

