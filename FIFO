#include<stdio.h>
void main()
{
    int frame[10],page[10],flag,fault,fn,n;
    printf("\nEnter the no.of string ref:-");
    scanf("%d",&n);
    printf("\nEnter the no. of string:-");
    scanf("%d",&fn);
    for(int i=0;i<fn;i++)
    {
        frame[i]=-1;

    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<fn;j++)
        {
            if(frame[j]==page[i])
            {
                flag++;
                fault--;
                break;
            }
            
        }fault++;
        if(fault==0)
            {
                frame[(fault-1)%fn]=page[i];
            }
            for(int k=0;k<fn;k++)
            {
                printf("%d",&frame[k]);
            }
    }printf("\nNO.of pages:-%d",fault);
}
