#include <stdio.h>
#include <stdlib.h>
struct process
{
    int pid;
    int bt;
    int wt;
    int tt;
    int rbt;

};
void findwt(struct process p[],int n,int q)
{
    int t=0;
    while(1)
    {
        int done=1;
        for(int i=0;i<n;i++)
        {
            if(p[i].rbt>0)
            {
                done=0;
                if(p[i].rbt>q)
                {
                    t+=q;
                    p[i].rbt=p[i].rbt-q;
                }
                else
                {
                    t+=p[i].rbt;
                    p[i].wt=t-p[i].bt;
                    p[i].rbt=0;
                }
            }
        }
        if(done==1)
            break;
    }
}
void findtt(struct process p[],int n)
{
    for(int i=0;i<n;i++)
        p[i].tt=p[i].wt+p[i].bt;
}
void findavg(struct process p[],int n,int q)
{
    int sumwt=0,sumtt=0;
    findwt(p,n,1);
    findtt(p,n);
    for(int i=0;i<n;i++)
    {
        sumwt+=p[i].wt;
        sumtt+  =p[i].tt;
    }
    printf("Avg waiting time=%f\n",(float)sumwt/(float)n);
    printf("Avg turnaround time=%f\n",(float)sumtt/(float)n);

}

int main()
{
    struct process p[10];
    int n,i,q;
    printf("Enter total no of processes\n");
    scanf("%d",&n);
    printf("Enter bt\n");
    for(i=0;i<n;i++)
    {
        p[i].pid=i+1;
        printf("P[%d]:",i+1);
        scanf("%d",&p[i].bt);
        p[i].wt=p[i].tt=0;
        p[i].rbt=p[i].bt;
    }
    q=2;
    findavg(p,n,q);
    return 0;
}
