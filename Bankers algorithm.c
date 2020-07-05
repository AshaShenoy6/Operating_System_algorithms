#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,i,j,k;
    printf("Enter no of procesees\n");
    scanf("%d",&n);
    printf("Enter no of resources\n");
    scanf("%d",&m);
    int alloc[n][m],max[n][m],avail[m],need[n][m];
    printf("Enter alloc matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
          scanf("%d",&alloc[i][j]);
     printf("Enter max matrix\n");
     for(i=0;i<n;i++)
        for(j=0;j<m;j++)
          scanf("%d",&max[i][j]);
     printf("Enter avail\n");
     for(i=0;i<m;i++)
            scanf("%d",&avail[i]);
     for(i=0;i<n;i++)
        for(j=0;j<m;j++)
                need[i][j]=max[i][j]-alloc[i][j];
     printf("need ,atrix is:\n");
     for(i=0;i<n;i++)
     {
         for(j=0;j<m;j++)
         {
          printf("%d\t",need[i][j]);
         }
         printf("\n");
     }
     int safeseq[n],finish[n],found=0,count=0;
     for(i=0;i<n;i++)
        finish[i]=0;
     while(count<n)
     {
         found=0;
         for(i=0;i<n;i++)
         {
             if(finish[i]==0)
             {
                 for(j=0;j<m;j++)
                 {
                     if(need[i][j]>avail[j])
                       break;
                 }
                 if(j==m)
                 {
                     for(k=0;k<m;k++)
                        avail[k]=avail[k]+alloc[i][k];
                     safeseq[count++]=i;
                     finish[i]=1;
                     found=1;

                 }
             }
         }
         if(found==0)
         {
             printf("Not safe\n");
             return 0;
         }
     }
     printf("Safe\n");
     printf("Sequence is:\n");
     for(i=0;i<n;i++)
        printf("P%d\t",safeseq[i]+1);
     return 0;

}
