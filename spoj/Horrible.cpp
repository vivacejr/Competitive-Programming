/*horrible queries spoj*/


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front

ll tree[4*100000];
ll lazy[4*100000];

ll build(ll node,ll start,ll end)
{
	if(start==end) tree[node]=0,lazy[node]=0;
	else
	{
		ll mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[2*node]=0;
		tree[2*node+1]=0;
		lazy[2*node]=0;
		lazy[2*node+1]=0;
	}
}

ll query(ll node,ll start,ll end,ll l,ll r)
{
	// cout<<start<<" "<<end<<" "<<node<<" "<<tree[node]<<endl;
    if(lazy[node] )
    { 
        tree[node] += (end - start + 1) * lazy[node];   
        if(start != end)
        {
            lazy[node*2] += lazy[node];                 
            lazy[node*2+1] += lazy[node];               
        }
        lazy[node]=0;
    }
    if(start>r||end<l||start>end) return 0;

	if(start>=l&&r>=end)
	{
		return tree[node];	
	}
	else
	{
		ll mid=(start+end)/2;
		ll z= query(2*node,start,mid,l,r) + query(2*node+1,mid+1,end,l,r);
		return z;
	}
}

ll update(ll node,ll start,ll end,ll l ,ll r,ll val)
{
	// cout<<start<<" "<<end<<" "<<node<<" "<<tree[node]<<endl;

    if(lazy[node])
    { 
        tree[node] += (end - start + 1) * lazy[node];   
        if(start != end)
        {
            lazy[node*2] += lazy[node];                 
            lazy[node*2+1] += lazy[node];               
        }
        lazy[node] = 0;                                 
    }
    if(start>r||end<l||start>end) return 0;

	if(start>=l&&r>=end)
	{
		tree[node]+=(end-start+1)*val;
		if(start!=end)
		{
			lazy[2*node]+=val;
			lazy[2*node+1]+=val;
		}
	}
	else
	{
		ll mid=(start+end)/2;
		update(2*node,start,mid,l,r,val);
		update(2*node+1,mid+1,end,l,r,val);
		tree[node]=tree[2*node+1]+tree[2*node];

	}
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,q;
		cin >> n>>q;
		build(1,1,n);

		while(q--)
		{
			ll type,l,r,val;
			cin >> type;		
			if(type) // range query
			{
				cin>>l>>r;
				cout<<query(1,1,n,l,r)<<endl;
			}
			else // range update
			{
				cin>>l>>r>>val;

				update(1,1,n,l,r,val);
			}
		}
	}
	return 0;
}