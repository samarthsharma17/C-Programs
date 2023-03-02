#include<stdio.h>
#include<stdlib.h>

int pqueue[100];
int rear=-1;
int front=-1;

void insert()
{
    if(rear==99)
    {
        printf("Queue is full\n");
        return;
    }

    int item,ind;

    printf("Enter the item to be inserted\n");
    scanf("%d",&item);

    if(rear==-1 && front==-1)
    {
        pqueue[++rear]=item;
        front++;
    }

    else{
        rear++;

        for(ind=0;ind<rear;ind++)
        {
            if(pqueue[ind]>item)
            {
                break;
            }
        }

        for(int i=rear;i>ind;i--)
        {
            pqueue[i]=pqueue[i-1];
        }

        pqueue[ind]=item;
    }
}

void delete()
{
    int x,ind=0;

    if(rear==-1 && front==-1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Enter the element to be deleted\n");
    scanf("%d",&x);

    if(rear==front && pqueue[rear]==x)
    {
        printf("Element %d is deleted from the queue\n",x);
        rear=front=-1;
    }

    else{
         printf("Element %d is deleted from the queue\n",x);

        while(pqueue[ind]!=x)
        {
            ind++;
        }

        for(int i=ind;i<rear;i++)
        {
            pqueue[i]=pqueue[i+1];
        }

        rear--;
    }
}

void print()