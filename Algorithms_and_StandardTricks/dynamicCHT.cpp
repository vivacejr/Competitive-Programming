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
vpld V;
set<pld>cht;
pld line_intersection(ld m1,ld c1,ld m2,ld c2)
{
	return mp((c2-c1)/(m1-m2),(m2*c1-m1*c2)/(m2-m1));
}

ll bad(auto it)
{
	if(it==cht.begin()||next(it)==cht.end())
		return 0;
	auto itp = prev(it);
	auto itn = next(it);
	ld m1 = (*itp).ff;
	ld c1 = (*itp).ss;
	ld m2 = (*it).ff;
	ld c2 = (*it).ss;
	ld m3 = (*itn).ff;
	ld c3 = (*itn).ss;
	ld x1 = line_intersection(m1,c1,m3,c3).ff;
	ld x2 = line_intersection(m1,c1,m2,c2).ff;
	return x1 <= x2;

}
ll add(ll m,ll c)
{
	if(cht.size()<=1)
	{
		cht.insert(mp(m,c));	
	}

	auto it = cht.lower_bound(mp(m,c));

	if(it!=cht.end()) //check parralel
		if( (*it).ff == m && (*it).ss < c )		cht.erase(it);
	
	cht.insert(mp(m,c));
	it = cht.lower_bound(mp(m,c));
	if (bad(it))
	{
		cht.erase(it);
		return 0;
	}
	while(1) // prev
	{
		it = cht.lower_bound(mp(m,c));
		if(it==cht.begin())break;
		auto it2 = prev(it);
		if(bad(it2))cht.erase(it2);
		else break;
	}
	while(1) //next
	{
		it = cht.lower_bound(mp(m,c));
		auto it2 = next(it);
		if(it2==cht.end())break;
		if(bad(it2))	cht.erase(it2);
		else break;
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
	lp(i,0,n)
	{
		add(V[i].ff,V[i].ss);
	}
	for(auto it = cht.begin();it !=cht.end(); it++)
	{
		cout<<(*it).ff<<" "<<(*it).ss<<endl;
	}
	return 0;
}