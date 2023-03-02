#include<stdio.h>
#include<stdlib.h>

void main()
{
    int w,f,frames[100];

    printf("Enter the window size\n");
    scanf("%d",&w);

    printf("Enter no of frames\n");
    scanf("%d",&f);

    printf("Enter %d frames\n",f);

    for(int i=1;i<=f;i++)
    {
        scanf("%d",&frames[i]);
    }

    printf("With sliding window protocol the frames will be sent in this order\n");
    printf("After sending %d frames the sender waits for the acknowledgement from the receiver\n",w);

    for(int i=1;i<=f;i++)
    {
        if(i%w==0)
        {
            printf("%d\n",frames[i]);
            printf("Acknowlegement of above frames sent is received by the sender\n");
        }

        else
            printf("%d\n",frames[i]);
    }

    if(f%w!=0)
    {
       printf("Acknowlegement of above frames sent is received by the sender\n");
    }

}