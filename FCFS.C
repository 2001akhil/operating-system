#include<stdio.h>
struct pcb{int pid,arrival_time,turnarround_time,burst_time;};
void pline(int x);
void main()
{
    int num;
    float sum=0.0,avg=0.0;
    struct pcb p[10],temp;
    printf("\nEnter the total no. of process:");
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        printf("\nEnter the arrival time and burst time %d: ",i+1);
        scanf("%d%d",&p[i].arrival_time,&p[i].burst_time);
        p[i].pid=i+1;
        
    }
    //sort according to the arrival time
    for(int i=0;i<num-1;i++)
    {
        for(int j=0;j<num-i-1;j++)
        {
            if(p[j].arrival_time>p[j+1].arrival_time)
            {
            temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;
            }
        }
    }
    //calculate turn arround turnarround_time
    for(int i=0;i<num;i++)
    {
        sum=sum+p[i].burst_time;
        p[i].turnarround_time=sum;
        
    }
    sum=0;
    pline(44);
    printf("PID\tArrival time\t burst_time\turnarround_time\n:");
    pline(44);
    for(int i=0;i<num;i++)
    {
        printf("%d\t%d\t%d\t%d\n",p[i].pid,p[i].arrival_time,p[i].burst_time,p[i].turnarround_time);
        sum+=p[i].turnarround_time;
        
    }
    pline(44);
    avg=sum/(float)num;
    printf("\nTOTAL NO. OF turnarround_time:%f",sum);
    printf("\nAVG turnarround_time:%f",avg);
    }
    
    void pline(int x)
    {
        for(int i=0;i<x;i++)
        {
        printf("-");
        } printf("\n");
    }
   
