#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ary[50005];
struct ped{
	ll sum;
	ll pre;
	ll suf;
	ll mx;
};
struct ped tree[4*50005];

struct ped merge(struct ped l,struct ped r)
{
	struct ped res;
	res.sum=l.sum+r.sum;
	res.pre=max(l.pre,l.sum+r.pre);
	res.suf=max(r.suf,r.sum+l.suf);
	res.mx=max(l.suf+r.pre,max(l.mx,r.mx));

	return res;
}


struct ped build(ll node,ll start,ll end)
{
	if(start==end)
	{
		tree[node].sum=tree[node].pre=tree[node].suf=tree[node].mx=ary[start];
		return tree[node];
	}
	else
	{ 	
		ll mid=(start+end)/2;
		tree[node]=merge(build(2*node,start,mid),build(2*node+1,mid+1,end));
		return tree[node];
	}																			
}

struct ped query(ll node,ll start,ll end,ll l,ll r)
{
	if(start==end)				return tree[node];
	
	if(start>=l&&end<=r)	return tree[node];
	
	else
	{
		ll mid=(start+end)/2;
		if(r<=mid) return query(2*node,start,mid,l,r);
		if(l>mid)  return query(2*node+1,mid+1,end,l,r);
		return(merge(query(2*node,start,mid,l,r),query(2*node+1,mid+1,end,l,r)));
	}

}

int main()
{
	ll n;
	cin >> n;
	for (ll i = 1; i <= n; ++i) scanf("%lld",&ary[i]);

	build(1,1,n);	
	ll m;
	scanf("%lld",&m);
	while(m--)
	{
		ll l,r;
		scanf("%lld%lld",&l,&r);
		cout<<query(1,1,n,l,r).mx<<endl;
	}
	return 0;
}