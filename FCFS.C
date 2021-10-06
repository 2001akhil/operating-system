#include<stdio.h>
struct pcb{
    int pid,turnarround_time,burst_time,arrival_time;

};
void pline(int x);
void main()
{
    struct pcb p[10],temp;
    int num;
    float sum=0.0,avg=0.0;

    printf("Enter the process:");
    scanf("%d",num);
    for(int i=0;i<num;i++)
    {
        printf("\nEnter the burst time and arrival time:%d",i+1);
        scanf("%d%d",&p[i].arrival_time,&p[i].burst_time);
      p[i].pid=i+1;


    }
    //sort according to the arrival time
    for(int i=0;i<num-1;i++)
    {
        for(int j=0;j<num-i-1;j++)
        {
            temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;

        }
    }
    //calculate the turn arround time
    for(int i=0;i<num;i++)
    {
        sum=sum+p[i].burst_time;
        p[i].turnarround_time=sum;


    }
    sum=0;
    pline(44);
    printf("PID\tArrival time\tBurst time\tTurn arround time\n");
    pline(44);
    //each process value
    for(int i=0;i<num;i++)
    {
        printf("%d\t%d\t%d\t%d\t/n",p[i].pid,p[i].arrival_time,p[i].burst_time,p[i].turnarround_time);
        sum+=p[i].turnarround_time;

    }
    pline(44);
    avg=sum/(float)num;
printf("\nTotal turn arround time %f",sum);
printf("\nAvg time %f",avg);



}
void pline(int x)
{
    for(int i=0;i<x;i++)
    {printf("\n");}printf("\n");
}
