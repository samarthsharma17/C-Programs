#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
    float p,q;
    float num,denom;
    char ch;
    printf("enter 2 nos\n");
    scanf("%f %f",&p,&q);
    printf(" \nsum\nminus\nmultiply\ndivide\n");
    printf("enter choice:\n");
    printf("Hello");
    scanf("%c",&ch);
    printf("Hello");
    
    switch(ch)
    {
        
    case '+': 
        printf("sum is:%f",p+q);
        break;
    case '-':
        printf("minus: %f",p-q);
        break;
    case '*':
        printf("multiply: %f",p*q);
        break;
    case '/':
        if(p==0&&q!=0)
        {
            num=p;
            denom=q;
            printf("divide:%f ",num/denom);
            
        }
        if(p!=0&&q==0)
        {
            num=q;
            denom=p;
            printf("divide=%f",num/denom);
            
        }
        if(p!=0&&q!=0)
        {
            printf("divide=%f",p/q);
            
        }
        else
        {
            printf("zero error");
            
        }
        break;
    default:
        printf("enter correct choice");
        break;
    }
    
    
    return 0;
}