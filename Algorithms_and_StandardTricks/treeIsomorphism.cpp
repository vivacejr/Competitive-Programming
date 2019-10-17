#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll,ll> 
#define pld pair<ld,ld> 
#define vpll vector<pll>
#define vpld vector<pld>
#define all(X) X.begin(),X.end()
#define endl "\n"
#define sz(x) ((ll)((x).size()))
const ll N=1e5+5,inf=1e18;

vll G1[N],G2[N];
ll p1[N],p2[N];
vll lev1[N],lev2[N];
ll vis1[N],vis2[N];
ll mx1=-1,mx2=-1;
vll val1[N],val2[N];
ll bfs(ll r1,ll r2)
{	
	queue<pll> Q;
	Q.push(mp(r1,0));
	while(!Q.empty())
	{
		pll tp=Q.front();
		Q.pop();
		vis1[tp.ff]=1;
		lev1[tp.ss].pb(tp.ff);
		mx1=tp.ss;
		lp(i,0,G1[tp.ff].size())
		{
			ll x=G1[tp.ff][i];
			if(!vis1[x])
			{
				p1[x]=tp.ff;
				Q.push(mp(x,tp.ss+1));
			}
		}
	}

	Q.push(mp(r2,0));
	while(!Q.empty())
	{
		pll tp=Q.front();
		Q.pop();
		vis2[tp.ff]=1;
		lev2[tp.ss].pb(tp.ff);
		mx2=tp.ss;
		lp(i,0,G2[tp.ff].size())
		{
			ll x=G2[tp.ff][i];
			if(!vis2[x])
			{
				p2[x]=tp.ff;
				Q.push(mp(x,tp.ss+1));
			}
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll n;
	cin >> n;
	lp(i,0,n-1)
	{
		ll a,b;
		cin >> a >> b;
		G1[a].pb(b);
		G1[b].pb(a);
	}		    
	lp(i,0,n-1)
	{
		ll a,b;
		cin >> a >> b;
		G2[a].pb(b);
		G2[b].pb(a);
	}	
	ll r1=1;
	ll r2=1;
	bfs(r1,r2);	   
	if(mx1!=mx2)
	{
		cout<<"NO1"<<endl;
		return 0;
	} 
	vll I;
	I.pb(1);
	rlp(i,mx1,1)
	{
		vector<pair<vll,ll> > v1;
		vector<pair<vll,ll> > v2;

		lp(j,0,lev1[i].size())
		{
			ll x=lev1[i][j];
			if(val1[x].size()==0)
				val1[x]=I;
			v1.pb(mp(val1[x],x));
		}
		lp(j,0,lev2[i].size())
		{
			ll x=lev2[i][j];
			if(val2[x].size()==0)
				val2[x]=I;
			v2.pb(mp(val2[x],x));
		}
		sort(all(v1));
		sort(all(v2));
		// cout<<i<<" "<<v1.size()<<" "<<v2.size()<<endl;
		if(v1.size()!=v2.size())
		{
			cout<<"NO2"<<endl;
			return 0;
		}
		// lp(j,0,v1.size())
		// {
		// 	lp(k,0,v1[j].ff.size())
		// 	{
		// 		cout<<v1[j][k]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<endl;
		// lp(j,0,v2.size())
		// {
		// 	lp(k,0,v2[j].size())
		// 	{
		// 		cout<<v1[j][k]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<endl;
		lp(j,0,v1.size())
		{
			if(v1[j].ff!=v2[j].ff)
			{
				cout<<"NO3"<<endl;
				return 0;
			}	
		}
		vll cur;
		ll c=0;
		lp(j,0,v1.size())
		{
			ll a=v1[j].ss;
			ll b=v2[j].ss;
			if(v1[j].ff!=cur)
			{
				c++;
				cur=v1[j].ff;
			}
			val1[p1[a]].pb(c);
			val2[p2[a]].pb(c);
		}
		cout<<"YES"<<endl;

	}
	return 0;
}