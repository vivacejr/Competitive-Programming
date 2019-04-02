#include<stdio.h>
#include<math.h>
int main()
{
        int n,m,i,j;
	 long long int a=0;
        scanf("%d%d",&n,&m);
        int ary[n+2][m+2];
        for(i=0;i<n;i++)
        {
                ary[i][m]=0;
                ary[i][m+1]=0;
                for(j=0;j<m;j++)
                {		
                        scanf("%d",&ary[i][j]);
                        if (ary[i][j]==0)
                        {
                                ary[i][m]++;
                        }
                        else
                        {
            	        ary[i][m+1]++;	
                   	}
                }
                     a=a+pow(2,ary[i][m])-1+pow(2,ary[i][m+1])-1;
            }
        for(i=0;i<m;i++)
        {		
        	ary[n][i]=0;
        	ary[n+1][i]=0;
	for(j=0;j<n;j++)
	{	
		if(ary[j][i]==0)
			ary[n][i]++;
		else 
			ary[n+1][i]++;
	}
	a=a+pow(2,ary[n][i])-1+pow(2,ary[n+1][i])-1-n;
        }
        printf("%lld",a);
	
}      
