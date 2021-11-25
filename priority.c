/*
updating soon 
*/
#include<stdio.h>
#include<stdlib.h>


struct pcb {
int pid,burst_time,arrival_time,turnarround_time,waiting_time,position;};
void pline(int x);
void main()
{
struct pcb p[10],temp;
float avg=0.0,sum=0.0,wt=0.0,tt=0.0; 
int num;
printf("\nEnter the no. of process:");
scanf("%d",&num);
for(int i=0;i<num;i++)
{
printf("Enter the priority and burst time:-",i+1);
scanf("%d\n%d",&p[i].arrival_time,&p[i].burst_time);
p[i].pid=i+1;


}
/*//using sorting algorithm
for(int i=0;i<num-1;i++)

for(int j=0;num-i-1;i++)
{
if(p[i].arrival_time>p[j+1].arrival_time)

{
temp=p[j];
p[j]=p[j+1];
p[j+1]=temp;

}*/
//using sorting algorithm in the bases of priority 
for(int i=0;i<num;i++)
{
p[i]=position;
for(int j=i+1;i<num;j++)
{
if(p[i].)
}
}



}
//calculate turn arround time
sum=0;
for(int i=0;i<num;i++)
{
sum=sum+p[i].burst_time;

p[i].turnarround_time=sum;

//waiting
wt=p[i].turnarround_time-p[i].burst_time;
p[i].waiting_time=wt;

}
//calculate throughput
for(int i=0;i<num;i++)
{
tt=tt+p[i].burst_time;

}


//plinr(44);

printf("PID\tArrival\tBurst\n");
//pline(44);
for(int i=0;i<num;i++)
{
printf("%d\t%d\t  %d\n",p[i].pid,p[i].arrival_time,p[i].burst_time);
 sum+=p[i].turnarround_time;
}
printf("\nchart");//gant chart
for(int i=0;i<num;i++)
{
printf("\n%d",p[i].turnarround_time);
}

avg=sum/(float)num;
printf("\nTurn arround time is:-%f",sum);

printf("\nAverage turnaround time:-%f-",avg);
printf("\nThe waiting time is:%f",wt);
float avgwt=wt/(float)num;
printf("\naverage waiting time:%f",avgwt);
float th=tt/(float)num;
printf("trp:%f",th);



}




