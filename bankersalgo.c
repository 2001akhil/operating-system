#include<stdio.h>
int  main()
{
	int n,m,y=0;
	printf("Enter the number of process: \n");
	scanf("%d",&n);
	printf("Enter the number of resourses: \n");
	scanf("%d",&m);
	int alloc[n][m],max[n][m],need[n][m],avail[m];
	printf("enter the resourses alocated to each process \n");
	for(int i=0;i<n;i++)
	{
		printf("Enter the resoures allocaterd to p[%d]\n",i);
		for(int j=0;j<m;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("enter the max resourses of each process \n");
	for(int i=0;i<n;i++)
	{
		printf("Enter the  max resoures of p[%d]\n",i);
		for(int j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	printf("Enter the available instance of resourse\n");
	for(int i=0;i<m;i++)
	{
		scanf("%d",&avail[i]);
	}
	
	printf("need matrix\n");
	for(int i=0;i<n;i++)
	{
		
		for(int j=0;j<m;j++)
		{
			printf("%d\t",need[i][j]);
			
		}
		printf("\n");
	}
	int f[n],safe[n],ind=0,flag,fg=0;
	for(int i=0;i<n;i++)
	{
		safe[i]=-1;
	}
	for(int k=0;k<n;k++)
	{
		f[k]=0;
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			if(f[i]==0)
			{
				flag=0;
				for(int j=0;j<m;j++)
				{
					if(need[i][j]>avail[j])
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					safe[ind++]=i;
					for(y=0;y<m;y++)
					{
						avail[y] += alloc[i][y];
						f[i]=1;
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(safe[i]==-1)
			fg=1;
	}
	if(fg!=1)
	{
		printf("The system is in a safe state\nAnd the safe sequence is \n");
		for(int i=0;i<n;i++)
		{
		printf("p[%d]\t",safe[i]);
		}
	}
	else
	{
		printf("The system is not safe");
	}
	printf("\n");
	return 0;
}
