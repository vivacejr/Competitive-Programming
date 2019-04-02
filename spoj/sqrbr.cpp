#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front

ll dp[400][400];
ll ary[400];
ll post[400];
ll n;
void init()
{
	lp(i,0,2*n)
	{
		post[i]=0;
		ary[i]=-1;
	}

	lp(i,0,2*n)
	{
		lp(j,0,2*n)
		{
			dp[i][j]=-1;
		}
	}
}

ll solve(ll i,ll cnt)
{
	// cout<<i<<" "<<cnt<<endl;
	if(i==2*n)
	{
		if(cnt==0)
		{
			return 1;
		}
		return 0;
	}
	else
	{
		if(dp[i][cnt]==-1)
		{
			dp[i][cnt]=0;
			if(ary[i]==1)
			{
				dp[i][cnt]=solve(i+1,cnt+1);
			}
			else
			{
				// cout<<i<<"xx"<<cnt<<endl;
				ll temp=0;
				if(cnt>0)temp+=solve(i+1,cnt-1);
				if(2*n-i-post[i]>cnt)temp+=solve(i+1,cnt+1);
				dp[i][cnt]=temp;
			}

		}
		return dp[i][cnt];
	}
}


int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		ll k;
		cin >> n>>k;
		
		init();

		lp(i,0,k)
		{
			ll a;
			cin >> a;
			ary[a-1]=1;
		}
		post[2*n-1]=0;
		rlp(i,2*n-2,0)
		{
			if(ary[i+1]==1)
			{
				post[i]=post[i+1]+1;
			}
			else
			{
				post[i]=post[i+1];
			}
		}
		cout<<solve(0,0)<<endl;
	}
	return 0;
}