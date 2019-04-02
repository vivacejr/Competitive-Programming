#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front

char x[11];
char y[11];
bool prime[120];
ll dp[12][120][2];

ll init()
{
	lp(i,0,12)
		lp(l,0,120)
			lp(m,0,2)
				dp[i][l][m]=-1;
}
void find()
{
	// cerr<<"XxX"<<endl;
	lp(i,2,120)
	{

		if(!prime[i])
		{
			for(ll j=i+i;j<120;j+=i)
			{
				// cerr<<j<<endl;
				prime[j]=1;
			}
			// cout<<i<<endl;
		}	

	}
}

ll solve(char str[],ll n,ll i,ll sum,ll lo)
{
	// cerr<<i<<endl;
	if(i==n)
	{
		if(sum>=50)
		{
			if(!prime[sum-50]) 
			{
				return 1;
			}
		}
		return 0;
	}
	ll ul;
	if(dp[i][sum][lo]==-1)
	{
		dp[i][sum][lo]=0;		;
		
		if(lo==0) 	ul=str[i]-'0'+1;
		else ul=10;

		lp(j,0,ul)
		{
			if( (n-i)&1==1 )
				dp[i][sum][lo]+=solve(str,n,i+1,sum-j,lo||j<str[i]-'0');
			else
				dp[i][sum][lo]+=solve(str,n,i+1,sum+j,lo||j<str[i]-'0');
		}
	}
	return dp[i][sum][lo];
}

int main()
{
	ll t;
	cin >>t;
	lp(i,0,120) prime[i]=0;
	prime[0]=1;
	prime[1]=1;
	find();
	while(t--)
	{
		cin >> x >> y;
		ll lx=strlen(x);
		ll ly=strlen(y);
		rlp(i,lx-1,0)
		{
			if(x[i]=='0')
			{
				if(i!=0) x[i]='9';
			}
			else 
			{
				x[i]=x[i]-1;
				break;
			}
		}
		init();
		ll ans1=solve(x,lx,0,50,0);
		// cout<<endl;
		init();
		ll ans2=solve(y,ly,0,50,0);
		cout<<ans2-ans1<<endl;
	}

	return 0;
}