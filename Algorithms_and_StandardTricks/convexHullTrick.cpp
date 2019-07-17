//lines ka convex hull
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
#define pll pair<ll,ll> 
#define pld pair<ld,ld> 
#define vpll vector<pll>
#define vpld vector<pld>
#define all(X) X.begin(),X.end()
#define endl "\n"

const ll N=1e5+5;
vpld V,cht;
pld line_intersection(ld m1,ld c1,ld m2,ld c2)
{
	return mp((c2-c1)/(m1-m2),(m2*c1-m1*c2)/(m2-m1));
}
ll add(ll m,ll c)
{
	while(1)
	{
		ll z=cht.size()-1;
		if(z<=0)
		{
			cht.pb(mp(m,c));
			break;
		}
		pld p1 = line_intersection(cht[z-1].ff,cht[z-1].ss,m,c);
		pld p2 = line_intersection(cht[z].ff,cht[z].ss,cht[z-1].ff,cht[z-1].ss);
		ld x1 = p1.ff;
		ld x2 = p2.ff;
		if(x1>x2)
		{
			cht.pb(mp(m,c));
			break;
		}
		else
		{
			cht.pop_back();
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll n;
	cin >> n;
	lp(i,0,n)	    
	{
		ld m,c; // y = mx + c
		cin >> m >> c;
		V.pb(mp(m,c));
	}
	sort(all(V));//sorted according to slopes
	lp(i,0,n)
	{
		add(V[i].ff,V[i].ss);
	}
	lp(i,0,cht.size())
	{
		cout<<cht[i].ff<<" "<<cht[i].ss<<endl;
	}
	return 0;
}