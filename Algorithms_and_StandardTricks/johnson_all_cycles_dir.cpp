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
const ll N=1e5+5;
vll G[N];
stack<ll> st;
set<ll> S;
set<ll> F[N];
ll start=0;
ll dfs(ll a)
{
	ll f=0,f2=0;
	lp(i,0,G[a].size())
	{
		if(a==start)
		{
			f=1;
			continue;
		}
		if(S.find(a)==S.end())
		{
			S.insert(a);
			st.push(a);
			dfs(a);
		}
	}
	st.pop(a);
	if(f==1)
	{
		S.erase(a);
	}
}

ll solve(ll n)
{
	lp(i,1,n+1)
	{
		start=i;
		dfs(i);
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	ll n,m;
	cin >>n >> m;
	lp(i,0,m)
	{
		ll a,b;
	}   
	lp(i,1,n+1)
	{

	}
	return 0;
}