#include<bits/stdc++.h>
using namespace std;
char str[6105];
int ary[6105][6105];

int ppp(int a ,int b)
{
	return(a<b ? a : b);
}

int dp(int a,int l)
{
	if(l<=1)
	{
		return 0;
	}
	else if(ary[a][l]==0)
	{
		if(str[a]==str[a-l+1])
		{
			ary[a][l]=(dp(a-1,l-2));
			//return ary[a][l];
		}
		else
		{
			ary[a][l]=ppp(1+dp(a-1,l-1),1+dp(a,l-1));
		}
	}
	return ary[a][l];
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> str;
		for(int i=0;i<6105;i++)
		{
			for(int j=0;j<6105;j++)
			{
				ary[i][j]=0;
			}
		}
		int ans=dp(strlen(str)-1,strlen(str));
		cout << ans << endl;
	}
}
