#include<bits/stdc++.h>
using namespace std;

int m(int a,int b, int c)
{
	return min(min(a,b),min(a,c));
}
int lcs(int dp[2005][2005],char s1[],char s2[],int a,int b,int count)
{

	if(a<0&&b>=0)
	{
		return b+1;	
	}
	else if(b<0&&a>=0)
	{
		return a+1;
	}
	else if(a<0&&b<0)
	{
		return 0;
	}
	else if(!dp[a][b])
	{
		if(s1[a]==s2[b])
		{
			count=lcs(dp,s1,s2,a-1,b-1,count);
		}
		else
		{
			count=count + m(1+lcs(dp,s1,s2,a-1,b-1,count),1+lcs(dp,s1,s2,a,b-1,count),1+lcs(dp,s1,s2,a-1,b,count));
		}

		dp[a][b]=count;
	}
	return dp[a][b];
}
int main()
{
	int t;
	cin >>t;
	while(t--)
	{
		char s1[2005];
		char s2[2005];
		cin >> s1 >> s2;
		int dp[2005][2005];
		for(int i=0;i<205;i++)
		{
			for(int j=0;j<205;j++)
			{
				dp[i][j]=0;
			}
		}
		int a=strlen(s1);
		int b=strlen(s2);
		int ans=lcs(dp,s1,s2,a-1,b-1,0);
		//		for(int i=0;i<5;i++)
		//		{
		//			for (int j=0;j<5;j++)
		//			{
		//				cout << dp[i][j] << " ";
		//			}
		//			cout <<endl;
		//		}
		cout <<ans << endl;
	}
}
