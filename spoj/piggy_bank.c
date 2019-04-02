#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t ;
	cin >> t;
	while(t--)
	{
		int e;
		int f;
		cin >> e >> f;
		int b = f-e;
		int n;
		cin >> n;
		int val[n];
		int w[n];
		for(int i=0;i<n;i++)
		{
			cin >> val[i] >> w[i] ;
		}
		int dp[n+1][b+1] ;
		for(int i=0;i<n+1;i++)
		{
			for(int j=0;j<b+1;j++)
			{
				dp[i][j]=0;
			}	
		}
		for(int i=1;i<n+1;i++)
		{
			for(int j=1;j<b+1;j++)
			{

				if(j==w[i-1]&&dp[i-1][j]==0)
				{
					dp[i][j]=val[i-1];
				}
				else if(j==w[i-1])
				{
					dp[i][j]=min(dp[i-1][j],val[i-1]);
				}
				else if( j>=w[i-1] && (dp[i-1][j]!=0||dp[i][j-w[i-1]]!=0) )
				{
					if(dp[i-1][j]==0)
					{
						dp[i][j]=dp[i][j-w[i-1]]+val[i-1] ;
					}
					else if(dp[i][j-w[i-1]]==0)
					{
						dp[i][j]=dp[i-1][j];
					}
					else
					{

						dp[i][j]=min(dp[i-1][j],dp[i][j-w[i-1]]+val[i-1]);
					}
				}
				else
				{
					dp[i][j]=dp[i-1][j];
				}

			}
		}
		/*for(int i=0;i<n+1;i++)
		  {
		  for(int j=0;j<b+1;j++)
		  {
		  cout << dp[i][j] << " ";
		  }
		  cout << endl;
		  }*/
		if(dp[n][b])
		{
			cout << "The minimum amount of money in the piggy-bank is "<< dp[n][b]<<"." <<endl;
		}
		else
		{
			cout << "This is impossible."<<endl;
		}
	}
	return 0;
}
