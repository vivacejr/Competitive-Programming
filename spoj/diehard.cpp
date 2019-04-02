#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[2005][2005][4];

int rec(ll H,ll A,ll a)
{
	if(H<=0||A<=0)
	{
		return 0;
	}
	else if(dp[H][A][a]==-1)
	{
		if(a==1)
		{
			dp[H][A][a]= max(1+rec(H-5,A-10,2),1+rec(H-20,A+5,3));
		}
		if(a==2)
		{
			dp[H][A][a]= 1+rec(H+3,A+2,1);
		}
		if(a==3)
		{
			dp[H][A][a]= 1+rec(H+3,A+2,1);
		}
	}
	return dp[H][A][a]; 
}


int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		ll a;
		ll b;
		cin >> a >> b;
		
		for (int i = 0; i < 2005; ++i)
		{
			for (int j = 0; j < 2005; ++j)
			{
				for (int k = 1; k < 4; ++k)
				{
					dp[i][j][k]=-1;
				}
			}
		}
		cout << rec(a+3,b+2,1) << endl;
	}
}