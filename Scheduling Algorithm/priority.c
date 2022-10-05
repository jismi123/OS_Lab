#include<stdio.h>
int main()
{
	int i,j,burst=0, n;
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	int prc[n], Bt[n], At[n], pr[n];
	printf("Enter the process number, Arrival time, priority & burst time: \nPNo\tAT\tPr\tBT\n");
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&prc[i],&At[i],&pr[i],&Bt[i]);

//Sorting according to priority (selection sort)
	int t,pos;
	for(i=0;i<n;i++)
	{
	pos = i;
		for(j=i+1;j<n;j++)
		{
			if(pr[j]<pr[pos])
				pos = j;
		}
//Swapping 
	t=Bt[i];
	Bt[i]=Bt[pos];
	Bt[pos]=t;
	
	t=pr[i];
	pr[i]=pr[pos];
	pr[pos]=t;
	
	t=At[i];
	At[i]=At[pos];
	At[pos]=t;
	
	t=prc[i];
	prc[i]=prc[pos];
	prc[pos]=t;
	}		
// Waiting time calculation
	int Wt[n];
	for(int i=0;i<n;i++)
	{	
	if(i==0)
	{
		Wt[i]=At[i];
	}
	else
	{
		Wt[i]=burst-At[i];
	}
	burst+= Bt[i];
	}
	
//Turn Around Time Calculation 	
	int Ta[n];
	int temp=0;
	for(int i=0;i<n;i++)
	{
		temp+=Bt[i];
		Ta[i]=temp-At[i];
	}
	
//Displaying the table with Waiting time and turn around time
	printf("\nPno\tBT\tAT\tpr\tWT\tTA");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\t%d\t%d\t%d\n",prc[i],Bt[i],At[i],pr[i],Wt[i],Ta[i]);
	}
	
//Finding Average waiting time	
	int SumWT=0;
	for(i=0;i<n;i++)
	{
		SumWT+=Wt[i];
	}
	float AvgWT=(float)SumWT/(float)n;
	
//Finding Average Turn Around time
	int SumTA=0;
	for(i=0;i<n;i++)
	{
		SumTA+=Ta[i];
	}
	float AvgTa=(float)SumTA/(float)n;
	
	printf("\nAverage Waiting Time = %f milliseconds\nAverage Turnaround time = %f milliseconds\n",AvgWT,AvgTa);
	
	return 0;
}
