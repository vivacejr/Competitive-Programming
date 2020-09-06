#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update


using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> pbds;

ll ary[100000];
struct ped{
	pbds S;
};
ped N[100000];

pbds::iterator it;


ped merge(ped l,ped r)
{
	ped temp;
	for(it=l.S.begin();it!=l.S.end();it++)
	{
		temp.S.insert(*it);
	}
	for(it=r.S.begin();it!=r.S.end();it++)
	{
		temp.S.insert(*it);
	}
	return temp;
}


ll build(ll node,ll start,ll end)
{
	if(start==end)
	{
		N[node].S.insert(ary[start]);
	}
	else
	{
		ll mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node,mid+1,end);
		N[node]=merge(N[2*node],N[2*node+1]);
	}
}

ll query(ll node,ll st,ll ed,ll l,ll r,ll val)
{
	if(st>ed||ed<l||st>r)
	{
		return 0;
	}
	if(st>=l&&ed<=r)
	{
		ll x = tre[node].S.order_of_key(mp(val,-1LL));
		return x;
	}
	else
	{
		ll mid=(st+ed)/2;
		ll x=query(2*node,st,mid,l,r,val);
		ll y=query(2*node+1,mid+1,ed,l,r,val);
		return x+y;
	}
}

int main()
{
	ll n;
	cin >> n;
	lp(i,0,n) cin >> ary[i];

	ll q;


	return 0;
}