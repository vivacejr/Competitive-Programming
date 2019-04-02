#include<stdio.h>
int main()
{
	int n;	//number of weights
	scanf("%d",&n) ;
	int wt; //max weight that we can take
	scanf("%d",&wt);
	int ary[n+1][wt+3]; 

	//scanning weight(2nd coloumn)(must be sorted) and its value(1st coloumn)
	int i,j;
	for(i=0;i<n+1;i++)
	{
		if(i==0) //row for total weight
		{
			for(j=3;j<wt+3;j++)
			{
				ary[0][j]=j-2;
			}
		}
		else
		{
			for(j=0;j<2;j++)
			{
				scanf("%d",&ary[i][j]);
			}
			for(j=2;j<3;j++)
			{
				ary[i][j]=0;
			}
		}
		ary[0][0]=0;
		ary[0][1]=0;
		ary[0][2]=0;
	}
	//knapsack
	int prevmax=0;
	for(i=1;i<n+1;i++)
	{
		for(j=3;j<wt+3;j++)
		{
			if(ary[i][1]<=ary[0][j])
			{
				if(i>1)
				{
					if(ary[i][0] + ary[i-1][j-ary[i][1]] > ary[i-1][j])
					{
						ary[i][j]=ary[i][0]+ary[i-1][j-ary[i][1]];
					}
					else
					{
						ary[i][j]=ary[i-1][j];
					}
				}
				else
				{
					ary[i][j]=ary[i][0];
				}
			}
			else
			{
				ary[i][j]=ary[i-1][j];
			}
		}
	}

	printf("\nthere you go : \n\n");
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<wt+3;j++)
		{
			printf("%d ",ary[i][j]); 
		}
		printf("\n");
	}

}

