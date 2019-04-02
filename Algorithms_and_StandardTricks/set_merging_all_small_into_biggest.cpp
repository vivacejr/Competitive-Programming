#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define vll vector<ll>
#define pll pair<ll,ll> 


const ll maxn=1e5+5;
ll col[maxn],sz[maxn];
vector<vector<ll> > g(maxn);
map<ll, ll> *cnt[maxn];
void dfs(int v, int p){
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
    {
    	if(u != p)
     	{
        	dfs(u, v);
            if(sz[u] > mx)
            	mx = sz[u]; bigChild = u;
    	}
    }
    if(bigChild != -1)
        cnt[v] = cnt[bigChild];
    else
        cnt[v] = new map<ll, ll> ();
    (*cnt[v])[ col[v] ] ++;
    for(auto u : g[v])
       if(u != p && u != bigChild){
           for(auto x : *cnt[u])
               (*cnt[v])[x.first] += x.second;
       }
    //now (*cnt[v])[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.

}
int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    ll n;
    cin >> n;
    lp(i,1,n+1) cin >> col[i];
	lp(i,0,n-1)
	{
		ll a,b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1,1);

	lp(i,1,n+1)
	{
		lp(j,1,5)
		{
			cout<<(*cnt[i])[j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}