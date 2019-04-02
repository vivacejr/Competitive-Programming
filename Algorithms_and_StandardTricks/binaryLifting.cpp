#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define vll vector<ll> 
ll expo(ll base, ll exponent, ll mod) {
    ll ans = 1;
    while(exponent !=0 ) {
        if((exponent&1) == 1) {
            ans = (ans*base)%mod ;
        }
        base = (base*base)%mod;
        exponent>>= 1;
    }
    return ans%mod;
}

vector<vector<ll> > G(100000);

ll dp[100000][20];

ll init(ll n)
{
	lp(i,0,n)
	{
		lp(j,0,20)
		{
			dp[i][j]=-1;
		}
	}
}

ll query(ll node,ll k)
{
	ll j=0;
	while(k>0)
	{
		if(k&1)
		{
			node=dp[node][j];
		}
		j++;
		k>>=1;

	}
	return node;
}

int main()
{
	ll n;
	cin >> n;
	init(n);
	lp(i,0,n) 
	{
		ll k; //number of children
		cin >> k;
		lp(j,0,k)
		{
			ll child;
			cin >> child;
			child--;
			G[i].pb(child);
			G[child].pb(i);
			dp[child][0]=i;
		}
	}
	lp(j,1,20)
	{
		lp(i,0,n)
		{
			if(1<<j>=n)break; 
			
			if(dp[i][j-1]<n&&dp[i][j-1]!=-1) dp[i][j]=dp[dp[i][j-1]][j-1]; //2^j-1 + 2^j-1 =2^jth parent;
		}
	}

	ll q;
	cin >> q;
	while(q--)
	{
		ll node,k;
		cin >> node >> k;//node ka kth parent
		node--; 
		cout<<query(node,k)+1<<endl;
	}



	return 0;
}