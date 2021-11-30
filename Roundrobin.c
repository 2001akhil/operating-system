#include<stdio.h>
void main()
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
