#include <stdio.h>
#include <stdlib.h>
int n,nf;
int in[100];
int frames[50];
int i,j,k;
int hit=0;
int pgfc=0;
int findex=0;
void getdata()
{
    printf("Enter the l of page reference seq\n");
    scanf("%d",&n);
    printf("Entr the page refernce seq\n");
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
void fifo()
{
    initialise();
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nFor %d: ",in[i]);
        if(ishit(in[i])==0)
        {
            frames[findex]=in[i];
            findex=(findex+1)%nf;
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
     printf("Enter your choice\n1.enter data\n2.fifo\n3.exit\n");
     scanf("%d",&ch);
     switch(ch)
     {
         case 1: getdata();
         break;
         case 2: fifo();
         break;
         case 3:exit(0);
     }
 }
}
