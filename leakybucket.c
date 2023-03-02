#include<stdio.h>
#include<stdlib.h>
#define MIN(x,y) (x>y)?y:x

void main()
{
    int i=0,orate,cap,count=0,ch,x=0,drop=0;
    int inp[100];

    printf("Enter bucket size :\n");
    scanf("%d",&cap);

    printf("Enter output rate:\n");
    scanf("%d",&orate);

    do{
        printf("Enter the number of packets coming in second %d : \n",++i);
        scanf("%d",&inp[i]);
        printf("continue-1 end-0 : \n");
        scanf("%d",&ch);
    }while(ch);

    printf("second \t received \t sent \t dropped \t remained\n");
    for(int j=1;j<=i;j++)
    {
        printf("%d ",j);
        printf("\t %d \t",inp[j]);
        printf("\t %d \t",MIN((inp[j]+count),orate));

        if((x=inp[j]+count-orate)>0)
        {
            if(x>cap)
            {
                drop=x-cap;
                count=cap;
            }

            else{
                count=x;
                drop=0;
            }
        }

        else{
            drop=0;
            count=0;
        }

        printf("\t %d \t",drop);
        printf("\t %d",count);
        printf("\n");
    }
}