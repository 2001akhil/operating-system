#include<stdio.h>
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
