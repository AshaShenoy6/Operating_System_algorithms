#include <stdio.h>
#include <stdlib.h>
int n,nf;
int in[100];
int frames[50];
int i,j,k;
int hit=0;
int pgfc=0;
void getdata()
{
    printf("Enter the l of page reference seq\n");
    scanf("%d",&n);
    printf("Enter the page reference seq\n");
    for(i=0;i<n;i++)
        scanf("%d",&in[i]);
    printf("Enter the no of frames\n");
    scanf("%d",&nf);

}
void initialise()
{
    pgfc=0;
    for(i=0;i<nf;i++)
        frames[i]=9999;

}
int ishit(int data)
{

    hit=0;
    for(j=0;j<nf;j++)
    {
        if(frames[j]==data)
        {
            hit=1;
            break;
        }
    }
    return hit;
}
void disppages()
{

    for(k=0;k<nf;k++)
    {
        if(frames[k]!=9999)
        {
            printf("%d ",frames[k]);
        }
    }
}
void dispPgfc()
{
    printf("Total page fault counts:%d",pgfc);

}
void lru()
{
    initialise();
    int least[50];
    for(i=0;i<n;i++)
    {
        printf("\nFor %d:",in[i]);
        if(ishit(in[i])==0)
        {
            for(j=0;j<nf;j++)
            {
                int pg=frames[j];
                int found=0;
                for(k=i-1;k>=0;k--)
                {
                    if(pg==in[k])
                    {
                        least[j]=k;
                        found=1;
                        break;
                    }
                    else
                        found=0;
                }
                if(!found)
                    least[j]=-9999;
            }
            int min=9999;
            int repindex;
            for(j=0;j<nf;j++)
            {
                if(least[j]<min)
                {
                    min=least[j];
                    repindex=j;
                }
            }
            frames[repindex]=in[i];
            pgfc++;
            disppages();
        }
        else
            printf("No page fault\n");
    }
    dispPgfc();
}

int main()
{
   int ch;
 while(1)
 {
     printf("Enter your choice\n1.enter data\n2.lru\n3.exit\n");
     scanf("%d",&ch);
     switch(ch)
     {
         case 1: getdata();
         break;
         case 2: lru();
         break;
         case 3:exit(0);
     }
 }
}
