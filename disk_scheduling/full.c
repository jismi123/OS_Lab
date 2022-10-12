#include <stdio.h>
#include<stdlib.h>
void FCFS(int [],int,int);
void SCAN(int [],int,int);
void CSCAN(int [],int,int);
int main()
{
    int n,i,intial,ch;
    printf("Enter the num of request:");
    scanf("%d",&n);
    int req[n];
    printf("Enter the sequence:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }

    printf("Enter the intial head:");
    scanf("%d",&intial);
    do{
        printf("\n1.FCFS \n 2.SCAN \n 3.CSCAN\n Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("FCFS scheduling");
                FCFS(req,intial,n);
                break;
                
            }
            case 2:
            {
                printf("SCAN scheduling");
                SCAN(req,intial,n);
                break;
            }
            case 3:
            {
                printf("CSCAN scheduling");
                CSCAN(req,intial,n);
                break;
            }
            default: printf("Wrong entry");
        }
    }while(ch<4);
}
void FCFS(int r[],int intial,int n)
{
    int i,total=0;
    for(i=0;i<n;i++)
    {
        total=total+abs(r[i]-intial);
        intial=r[i];
    }
    printf("head movt=%d",total);
}

void SCAN(int r[],int intial,int n)
{
    int disksize,d,i,j,total=0;
    printf("Enter the disk size:");
    scanf("%d",&disksize);
    printf("Direction: 1.high\n 2.low \n Enter the direction:\n");
    scanf("%d",&d);
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(r[j]>r[j+1])
            {
                int temp;
                temp=r[j];
                r[j]=r[j+1];
                r[j+1]=temp;
            }
        }
    }
    
    int index;
    for(i=0;i<n;i++)
    {
        if(intial<r[i])
        {
            index=i;
            break;
        }
    }
    
    if(d==1)
    {
        for(i=index;i<n;i++)
        {
            total=total+abs(r[i]-intial);
            intial=r[i];
        }
        total=total+abs(disksize-r[i-1]-1);
        intial=disksize-1;
        for(i=index-1;i>=0;i--)
        {
            total=total+abs(r[i]-intial);
            intial=r[i];
        }
    }
    else
    {
        for(i=index-1;i>=0;i--)
        {
            total=total+abs(r[i]-intial);
            intial=r[i];
        }
        total=total-abs(r[i+1]-0);
        intial=0;
        
        for(i=index;i<n;i++)
        {
            total=total+abs(r[i]-intial);
            intial=r[i];        
            
        }
    }
    printf("head movt:%d",total);
}

void CSCAN(int r[],int intial,int n)
{
    int disksize,d,i,j,total=0;
    printf("Enter the disk size:");
    scanf("%d",&disksize);
    printf("Direction: 1.high\n 2.low \n Enter the direction:\n");
    scanf("%d",&d);
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(r[j]>r[j+1])
            {
                int temp;
                temp=r[j];
                r[j]=r[j+1];
                r[j+1]=temp;
            }
        }
    }
    
    int index;
    for(i=0;i<n;i++)
    {
        if(intial<r[i])
        {
            index=i;
            break;
        }
    }
    
    if(d==1)
    {
        for(i=index;i<n;i++)
        {
            total=total+abs(r[i]-intial);
            intial=r[i];
        }
        total=total+abs(disksize-r[i-1]-1);
        total=total+abs(disksize-1-0);
        intial=0;
        
        for(i=0;i<index;i++)
        {
            total=total+abs(r[i]-intial);
            intial=r[i];
        }
        
    }
    else
    {
        for(i=index-1;i>=0;i--)
        {
            total=total+abs(r[i]-intial);
            intial=r[i];
        }
        total=total+abs(r[i+1]-0);
        total=total+abs(disksize-1-0);
        intial=disksize-1;
        for(i=n-1;i>=index;i--)
        {
            total=total+abs(r[i]-intial);
            intial=r[i];
        }
    }
    printf("head movt: %d",total);
    
}
