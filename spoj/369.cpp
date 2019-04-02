#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
ll mod=1000000007;
char x[100];
char y[100];
ll dp[52][18][18][18][2];

ll init()
{
	lp(i,0,51)
		lp(j,0,18)
			lp(k,0,18)
				lp(l,0,18)
					lp(m,0,2)
						dp[i][j][k][l][m]=-1;
}

ll solve(ll i,char str[],ll n ,ll c1,ll c2,ll c3,ll lo)
{

	if(c1==17||c2==17||c3==17) return 0;
	if(i==n)
	{
		if(c1==c2&&c2==c3&&c1>=1)
		{
			return 1;
		}
		else return 0;
	}
	ll ul;
	if(dp[i][c1][c2][c3][lo]==-1)
	{
		dp[i][c1][c2][c3][lo]=0		;
		if(lo=a=0)
		{
			ul=str[i]-'0'+1;
		}
		else ul=10;
		lp(j,0,ul)
		{
			// cout<<j;
			if(j==3) dp[i][c1][c2][c3][lo]+=solve(i+1,str,n,c1+1,c2,c3,lo||j<str[i]-'0');
			else if(j==6)  dp[i][c1][c2][c3][lo]+=solve(i+1,str,n,c1,c2+1,c3,lo||j<str[i]-'0');
			else if(j==9)  dp[i][c1][c2][c3][lo]+=solve(i+1,str,n,c1,c2,c3+1,lo||j<str[i]-'0');
			else  dp[i][c1][c2][c3][lo]+=solve(i+1,str,n,c1,c2,c3,lo||j<str[i]-'0');
			dp[i][c1][c2][c3][lo]%mod;
		}
	}
	return dp[i][c1][c2][c3][lo]%mod;
}


int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		cin >> x;
		ll lx=strlen(x);
		rlp(i,lx-1,0)
		{
			if(x[i]=='0')
			{
				x[i]='9';
			}
			else 
			{
				x[i]=x[i]-1;
				break;
			}
		}
		init();
		ll ans=0;
		ll ans2=0;
		ans+=solve(0,x,lx,0,0,0,0);
		cin >> y;
		ll ly=strlen(y);
		init();
		ans2+=solve(0,y,ly,0,0,0,0);
		// if(ly==51) cout<<
		// cout<<ans<<endl;
		cout<<ans2-ans<<endl;
		// cout<<ans<<endl;

	}
	return 0;
}