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
struct ped{
	ll r0;
	ll r1;
	ll r2;
};
ll ary[1000005];

struct ped tree[4*1000005];

ll lazy[4*1000005];

struct ped I;

ll build(ll node,ll start,ll end)
{
	if(start==end) tree[node].r0=1,tree[node].r1=0,tree[node].r2=0,lazy[node]=0;
	else
	{
		ll mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node].r0=(end-start+1);
		tree[node].r1=0;
		tree[node].r2=0;
		lazy[node]=0;
		// cout<<node<<" "<<start<<" "<<end<<" "<<tree[node].r0<<endl;
	}
}

ll query(ll node,ll start,ll end,ll l,ll r)
{
	// cout<<node<<" "<<start<<" "<<end<<" "<<tree[node].r0<<endl;
	
    if(lazy[node])
    { 
    	if(lazy[node]==1)
    	{
	        ll t1=tree[node].r1;
			tree[node].r1 = tree[node].r0;
			tree[node].r0 = tree[node].r2;
			tree[node].r2 = t1;   
        }
        else
        {
        	ll t1=tree[node].r2;
			tree[node].r2 = tree[node].r0;
			tree[node].r0 = tree[node].r1;
			tree[node].r1 = t1;   
        }
        if(start != end)
        {
            lazy[2*node] = (lazy[2*node]+lazy[node])%3;
			lazy[2*node+1] = (lazy[2*node+1]+lazy[node])%3;               
        }
        lazy[node] = 0;                                 
    }
    if(start>r||end<l||start>end) return 0;

	if(start>=l&&r>=end)
	{
		return tree[node].r0;	
	}
	else
	{
		ll mid=(start+end)/2;
		ll z= query(2*node,start,mid,l,r) + query(2*node+1,mid
			+1,end,l,r);
		return z;
	}
}

ll update(ll node,ll start,ll end,ll l ,ll r)
{
    if(lazy[node])
    { 
    	if(lazy[node]==1)
    	{
	        ll t1=tree[node].r1;
			tree[node].r1 = tree[node].r0;
			tree[node].r0 = tree[node].r2;
			tree[node].r2 = t1;   
        }
        else
        {
        	ll t1=tree[node].r2;
			tree[node].r2 = tree[node].r0;
			tree[node].r0 = tree[node].r1;
			tree[node].r1 = t1;   
        }
        if(start != end)
        {
            lazy[2*node] = (lazy[2*node]+lazy[node])%3;
			lazy[2*node+1] = (lazy[2*node+1]+lazy[node])%3;               
        }
        lazy[node] = 0;                                 
    }
    if(start>r||end<l||start>end) return 0;

	if(start>=l&&r>=end)
	{
		ll t1=tree[node].r1;
		tree[node].r1 = tree[node].r0;
		tree[node].r0 = tree[node].r2;
		tree[node].r2 = t1;

		lazy[2*node] = (lazy[2*node]+1)%3;
		lazy[2*node+1] = (lazy[2*node+1]+1)%3;

	}
	else
	{
		ll mid=(start+end)/2;
		update(2*node,start,mid,l,r);
		update(2*node+1,mid+1,end,l,r);
		tree[node].r0=tree[2*node+1].r0+tree[2*node].r0;
		tree[node].r1=tree[2*node+1].r1+tree[2*node].r1;
		tree[node].r2=tree[2*node+1].r2+tree[2*node].r2;
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q;
    cin >> n >>q;
    build(1,0,n-1);
    while(q--)
    {
    	ll type,a,b;
    	cin >>type>> a >> b;
    	if(type==0)
    	{
    		update(1,0,n-1,a,b);
    	}
    	else
    	{
    		cout<<query(1,0,n-1,a,b)<<endl;
    	}
    }
	return 0;
}