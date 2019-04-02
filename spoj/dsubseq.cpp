#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
ll mod=1000000007;
int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		ll n=s.length();
		ll dp[n+1];
		dp[n]=0;
		dp[n-1]=1;
		ll ary[27];
		lp(i,0,26)
		{
			ary[i]=-1;
		}
		ary[s[n-1]-'A']=n-1;
		rlp(i,n-2,0)
		{
			if(ary[s[i]-'A']==-1)
			{
				dp[i]=(2*dp[i+1])%mod+1;
			}
			else
			{
				dp[i]=((2*dp[i+1])%mod-dp[ary[s[i]-'A']+1]+mod)%mod;
			}
			ary[s[i]-'A']=i;
		}
		cout<<dp[0]%mod+1<<endl;
	}
	return 0;
}