#include<stdio.h>
int main()
{
	int i,j,burst=0, n;
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	int prc[n], Bt[n], At[n];
	printf("Enter the process number, Arrival time & burst time: \nPNo\tAT\tBT\n");
	for(i=0;i<n;i++)
		scanf("%d%d%d",&prc[i],&At[i],&Bt[i]);

//Sorting according to arrival time (selection sort)
	int t,pos;
	for(i=0;i<n;i++)
	{
	pos = i;
		for(j=i+1;j<n;j++)
		{
			if(At[j]<At[pos])
				pos = j;
		}
//Swapping 
	t=Bt[i];
	Bt[i]=Bt[pos];
	Bt[pos]=t;
	
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
	printf("\nPno\tBT\tAT\tWT\tTA");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\t%d\t%d\n",prc[i],Bt[i],At[i],Wt[i],Ta[i]);
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
