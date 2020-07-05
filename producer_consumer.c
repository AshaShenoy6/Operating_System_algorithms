#include<stdio.h>
#include<stdlib.h>

int main()
{
    int in=0,out=0,produce,consume,buffersize=10,buffer[10],op;
    printf("PRODUCER & CONSUMER");
    do
    {
        printf("\nChoose an option below:\n 1)Produce\n 2)Consume\n 3)Exit\n Enter your option - ");
        scanf("%d",&op);
        switch(op)
        {
            case 1: if((in+1)%buffersize==out)
                    {
                        printf("\nBuffer is full");
                        break;
                    }
                    else
                    {
                        printf("\nEnter the value - ");
                        scanf("%d",&produce);
                        buffer[in]=produce;
                        in=(in+1)%buffersize;
                    }
                    break;
            case 2: if(in==out)
                    {
                        printf("\nBuffer is empty");
                        break;
                    }
                    else
                    {
                        consume=buffer[out];
                        printf("\n%d is consumed",consume);
                        out=(out+1)%buffersize;
                    }
                    break;
            case 3: exit(0);
        }
    }while(op!=3);
    return 0;
}