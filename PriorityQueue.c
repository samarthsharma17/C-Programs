#include<stdio.h>
#include<stdlib.h>

int pqueue[100];
int front=-1;
int rear=-1;

void insert()
{
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
    int x,j=0;
    printf("Enter the element to be deleted :\n");
    scanf("%d",&x);

    if(rear==-1 && front==-1)
    {
        printf("Queue is empty\n");
    }

    else if(rear==front && pqueue[rear]==x)
    {
        printf("Element deleted from the queue is : %d\n",pqueue[front]);
        rear=front=-1;
    }

    else{
        printf("Element deleted from the queue is : %d\n",x);

        while(pqueue[j]!=x)
        {
            j++;
        }

        for(int i=j;i<rear;i++)
        {
            pqueue[i]=pqueue[i+1];
        }
        rear--;
    }
}

void display()
{
    if(rear==-1 && front==-1)
    {
        printf("Queue is empty\n");
    }

    else{
        printf("Elements are : \n");

        for(int i=0;i<=rear;i++)
        {
            printf("%d\t",pqueue[i]);
        }
    }
}

void main()
{
    int ch;
    printf("Choose an option :\n");
    printf("1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT");

    while(1)
    {
        printf("\nYour Choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: insert();
                    break;
                
            case 2: delete();
                    break;

            case 3: display();
                    break;

            case 4: exit(0);
                    break;

            default: printf("INVALID INPUT");
        }
    }
}