#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
struct process
{
	int wt;
	int tt;
	int bt;
};
int main()
{
    struct process p[10];
	int i,n,tott=0,totwt=0;
	float avgtt,avgwt;
	printf("Enter the number of processes\n");
	scanf("%d",&n);
	printf("Enter burst time - \n");
	for(i=0;i<n;i++)
	{
		printf("Process %d - ",(i+1));
		scanf("%d",&p[i].bt);
	}
	p[0].wt=0;
	p[0].tt=p[0].wt+p[0].bt;
	for(i=1;i<n;i++)
	{
		p[i].wt=p[i-1].tt;
		p[i].tt=p[i].bt+p[i].wt;
	}
	for(i=0;i<n;i++)
	{
		tott+=p[i].tt;
		totwt+=p[i].wt;
	}
	printf("Total waiting time = %d\n",totwt);
	printf("Total turnaround time = %d\n",tott);
	avgtt=(float)tott/n;
	avgwt=(float)totwt/n;
	printf("Average waiting time = %f\n",avgwt);
	printf("Average turnaround time = %f\n",avgtt);
	printf("Process\tBT\tWT\tTT");
	for(i=0;i<n;i++)
	{
		printf("\np[%d]\t%d\t%d\t%d",(i+1),p[i].bt,p[i].wt,p[i].tt);
	}
	return 0;
}
