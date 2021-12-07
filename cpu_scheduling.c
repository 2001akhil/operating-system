#include<stdio.h>
struct pcb{int pid,arrival_time,turnarround_time,burst_time;};
//void pline(int x);
void fcfs()
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
    //pline(44);
    printf("PID\tArrival time\t burst_time\tTurnarround_time\n:");
    //pline(44);
    for(int i=0;i<num;i++)
    {
        printf("%d\t%d\t\t\t%d\t\t%d\n",p[i].pid,p[i].arrival_time,p[i].burst_time,p[i].turnarround_time);
        sum+=p[i].turnarround_time;
        
    }
    //pline(44);
    avg=sum/(float)num;
    printf("\nTOTAL NO. OF turnarround_time:%f",sum);
    printf("\nAVG turnarround_time:%f",avg);
}
    
/*void pline(int x)
{
    for(int i=0;i<x;i++)
    {
        printf("-");
    } 
    printf("\n");
}*/

void priority()
  {

   int n, tot_wt=0, tot_tat=0,temp=0,pos,count=0,temp1=0,temp2=0;
   float a=0,a_wt=0,a_tat=0;

   printf("Enter the number of processes ");
   scanf("%d",&n);
   int p[n], bt[n], tat[n], wt[n],pr[n];
   for(int i=0;i<n;i++){
        p[i]=i;
     printf("\nEnter Burst Time of P%d\t",i);
     scanf("%d",&bt[i]);
     printf("\nEnter priority of P%d",i);
     scanf("%d",&pr[i]);}

    for(int i=0;i<n;i++)

    {

      for(int j=0;j<n;j++)

      {

        if(pr[i]<pr[j])

        {
        temp=pr[i];
        pr[i]=pr[j];
        pr[j]=temp;
       
        temp1=bt[i];

        bt[i]=bt[j];

        bt[j]=temp1;

       

        temp2=p[i];

        p[i]=p[j];

        p[j]=temp2;

          }

     }  }  

    for(int i=0;i<n;i++)
    {
     wt[0]=0;
     if(i!=0)
     {
        wt[i]=wt[i-1]+bt[i-1];
        a_wt=a_wt+wt[i];
        tat[i]=wt[i]+bt[i];
        a_tat=a_tat+tat[i];
     }
     else
     {
         tat[i]=bt[i];
         a_tat=a_tat+tat[i];
     }
    }
   
    printf("Process\tBurst time\tTurn Around Time\tWaiting Time\tPriority\n");
        for(int i=0;i<n;i++)
        {
            printf(" Process[%d]\t%d\t\t",p[i],bt[i]);
            printf("%d\t\t%d\t\t%d\n",tat[i],wt[i],pr[i]);
        }
         printf("Average turn around time %f\n ",a_tat/n);
         printf("Average waiting time %f\n ",a_wt/n);


   
       
        printf("Gantt chart\n");
        for(int i=0;i<n;i++)
        {
            printf("\tP%d\t",p[i]);
        }
        printf("\n%d\t\t",count);
        for(int i=0;i<n;i++)
        {
            count=count+bt[i];
            printf("%d\t\t",count);
            a=count;
        }
 
  }


void sjf()
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
            if(p[j].burst_time>p[j+1].burst_time)
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
    //pline(44);
    printf("PID\tArrival time\t burst_time\turnarround_time\n:");
    //pline(44);
    for(int i=0;i<num;i++)
    {
        printf("%d\t%d\t%d\t%d\n",p[i].pid,p[i].arrival_time,p[i].burst_time,p[i].turnarround_time);
        sum+=p[i].turnarround_time;
    }
    //pline(44);
    avg=sum/(float)num;
    printf("\nTOTAL NO. OF turnarround_time:%f",sum);
    printf("\nAVG turnarround_time:%f",avg);
}    


void rr()
  {
       int n, total = 0, counter = 0, time_quantum,check=0;
       int wt[10], tat[10], bt[10],rem[10];
       float a_wt, a_tat;
       printf("\nEnter Total Number of Processes: ");
       scanf("%d", &n);
       printf("\nEnter Time Quantum:\t");
      scanf("%d", &time_quantum);
      for(int i = 0; i <n; i++)

      {

        printf("\nEnter Details of Process[%d]\n", i + 1);
        printf("Burst Time:\t");
        scanf("%d", &bt[i]);
        rem[i] = bt[i];

      }
      printf("Gantt chart\n");
        while(check<n)
        {
            for(int i=0;i<n;i++)
            if(rem[i]>time_quantum)
            {
                printf("\tP%d\t",i);
                total=total+time_quantum;
                rem[i]=rem[i]-time_quantum;
            }
            else if(rem[i]==0)
            {
               
            }
            else
            {
                printf("\tP%d\t",i);
                total=total+rem[i];
                tat[i]=total;
                wt[i]=total - bt[i];
                a_wt=a_wt+wt[i];
                a_tat=a_tat+tat[i];
                rem[i]=0;
                check++;
            }

      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(int i = 0;i<=0;i++)
      {
          printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d\n", i + 1, bt[i], total, total - bt[i]);
      }
      printf("Average turn around time %f\n ",a_tat/n);
        printf("Average waiting time %f\n ",a_wt/n);
 }
  }


void main()
{
    int a;
    char c;
    printf("\n1.FCFS\n2.SJF\n3.Priority\n4.Round Robin");
    printf("\nEnter the choice: ");
    scanf("%d",&a);
    switch(a)
    {
        case 1:fcfs();
               break;
        case 2:sjf();
               break;
        case 3:priority();
               break;
        case 4:rr();
               break;
        default:printf("\nWrong choice");
                break;
    }
}
