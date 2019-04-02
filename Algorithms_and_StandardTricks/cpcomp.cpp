#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define F first
#define S second
#define vll vector<ll>
#define pll pair<ll,ll> 
#define endl "\n"
const ll N=5e3+5,N2=2e5+1;
vll G[N];
ll adj[N][N];
ll vis[N];
vll G2[N];
bool prime[N2];



ll seive()
{
	lp(i,2,N2)
	{
		set<ll> S;
		if(prime[i]==0)
		lp(j,2,N2)
		{
			lp(k,j+i,N2)
			{
				adj[k][j]=1;
				k+=i-1;
			}
			j+=i-1;
		}
	}
}
ll dfs(ll a)
{
	vis[a]=1;
	lp(i,0,G[a].size())
	{
		if(!vis[G[a][i]])
		{
			dfs(G[a][i]);
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll n;
	cin >> n;
	ll ary[n];
	seive();
	lp(i,0,n)
	{
		cin >> ary[i];
		G2[ary[i]].pb(i);
	}	   
	ll cnt=0;
	lp(i,0,n)
	{
		lp(j,0,n)
		{
			if(adj[ary[i]][ary[j]]==0)
			{
				G[i].pb(j);
			}
		}
	}
	lp(i,0,n)
	{
		if(!vis[i])
		{
			dfs(i);
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}