#include<bits/stdc++.h>
using namespace std;

int dp[102][505];
int sto[102][505];


int m(int a,int b)
{
	return ( a > b ? a : b);
}

int main()
{
	int b;
	int n;
	while(1)
	{
		cin >> b >> n;
		if(b==0&&n==0)
		{
			break;
		}
		else{
			int ary[n];
			int f[n];
			int temp;
			for(int i=0;i<n;i++)
			{
				cin >> ary[i];
				cin >> f[i];
			}
			for(int i=0;i<n;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					if(ary[j]<ary[i])
					{
						temp=ary[i];
						ary[i]=ary[j];
						ary[j]=temp;
						temp=f[i];
						f[i]=f[j];
						f[j]=temp;			
					}
				}
			}
			for(int i=0;i<n+1;i++)
			{
				for(int j=0; j<b+1;j++)
				{
					dp[i][j]=sto[i][j]=0;
				}
			}
			for(int i=1;i<n+1;i++)
			{
				for(int j=1;j<b+1;j++)
				{
					if(ary[i-1]<=j)
					{

						if(dp[i-1][j-ary[i-1]]+f[i-1]>dp[i-1][j])
						{
							dp[i][j]=dp[i-1][j-ary[i-1]]+f[i-1];
							sto[i][j]=sto[i-1][j-ary[i-1]]+ary[i-1];;
						}
						else
						{
							dp[i][j]=dp[i-1][j];
							sto[i][j]=sto[i-1][j];
						}
					}
					else
					{
						dp[i][j]=dp[i-1][j];
						sto[i][j]=sto[i-1][j];
					}
				}	

			}
			for(int i=1;i<n+1;i++)
			{
				for(int j=1;j<b+1;j++)
				{
					cout << dp[i][j] << " " ;
				}
				cout << endl;
			}
			for(int i=1;i<n+1;i++)
			{
				for(int j=1;j<b+1;j++)
				{
					cout << sto[i][j] << " " ;
				}
				cout << endl;
			}
			int ho=sto[n][b];//meri wali approach
			int ans;//teri wali approach
			for(int i=0;i<b+1;i++)
			{
				if(dp[n][i]==dp[n][b])
				{
					ans =i ;
					break;
				}
			}
			cout <<ans<<" "<< ho << " " << dp[n][b] <<endl;
		}}
	return 0;
}


