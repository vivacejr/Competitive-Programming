#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair

/* ZERO-INDEXED SPARSE TABLE FOR RANGE SUM QUERY PROBLEM WITHOUT UPDATES*/

ll dp[10000][100];
ll init(ll pow,ll n)
{
	lp(i,0,n+1)
	{
		lp(j,0,pow+1)
		{
			dp[i][j]=0;
		}
	}	
}
ll ans;
ll ary[100000];

ll query(ll l,ll r)
{
		while(l<=r)
		{
			ll k=1;
			ll cnt=0;
			if(l==r)
			{
				ans+=ary[r];
				break;
			}
			while(l+k<=r)
			{
				k=k<<1;
				cnt++;
			}
			ans+=dp[l][cnt-1];
			l=l+(k>>1);
		}
}

int main()
{
	ll n;
	cin >> n;
	lp(i,0,n) cin >> ary[i];
	ll a=1;
	ll pow=0;
		while(a<n)
		{
			a=a*2;
			pow++;
		}

		lp(i,n,a) ary[i]=0;
		n=a;
		init(pow,n);

		lp(i,0,n) dp[i][0]=ary[i];
	lp(j,1,pow+1)
	{
		lp(i,0,n)
		{
			if(i+(1<<(j-1)) < n)
			{
				dp[i][j]=dp[i][j-1]+dp[i+(1<<(j-1))][j-1];
			}
		}
	}

	ll q;
	cin >> q;
	while(q--)
	{
		ll a,b;
		cin >> a>>b;
		ans=0;
		query(a-1,b-1);
	
		cerr <<ans<<endl;
	}
}
