#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct ped {
	bool all ;
	ll sum;
};

struct ped tree[400004];

ll ary[100001];

ll build(ll node,ll start,ll end)
{
	// cerr << node<<" "<<start<<" "<<end<< endl;

	if(start>end)
	{
		return 0;
	}
	if(start==end)
	{
		if(ary[start]==1)
		{
			tree[node].all=true;	
		}
		else
		{
			// cout << node << endl;
			tree[node].all=false;
		}

		tree[node].sum=ary[start];
		// cout << tree[node].sum<<endl;
	}
	else
	{
		ll mid=(start+end)/2;
		build	(2*node,start,mid)	;
		build	(2*node+1,mid+1,end)	;

		if( tree[2*node].all==true && tree[2*node+1].all==true )
		{
			tree[node].all=true;
		}
		else
		{
			tree[node].all=false;
		}

		tree[node].sum=tree[2*node].sum+tree[2*node+1].sum;

	}

}
ll update(ll node,ll start,ll end,ll x,ll y)
{
	// cerr << node<<" "<<start<<" "<<end<< endl;

	if(start==end)
	{
		ary[start]=sqrt(ary[start]);
		// cout << start << " "<<ary[start]<<endl;
		if(ary[start]==1)
		{
			tree[node].all=true;	
		}
		tree[node].sum=ary[start];
	}
	else if(tree[node].all==true||start>end)
	{

		// cout << 1 << endl;
		//do nothing
	}
	else
	{
		ll mid=(start+end)/2;
		if(y<=mid)	update(2*node,start,mid,x,y);
		else if(x>mid)	update(2*node+1,mid+1,end,x,y);
		else
		{
			update(2*node,start,mid,x,y);
			update(2*node+1,mid+1,end,x,y);
		}

		if( tree[2*node].all==true && tree[2*node+1].all==true )
		{
			tree[node].all=true;
		}

		tree[node].sum=tree[2*node].sum+tree[2*node+1].sum;

	}
}

ll query(ll node,ll start,ll end,ll l,ll r)
{
	// cerr << node<<" "<<start<<" "<<end<< endl;
	
	if(l>end||r<start)
	{
		return 0;
	}
	else if(start==end)
	{
		// cout << tree[node].sum<<endl;
		return tree[node].sum;
	}
	else if(start>=l&&end<=r)
	{
		// cout << tree[node].sum<<endl;
		return tree[node].sum;
	}
	else
	{
		ll mid=(start+end)/2;
		return( query(2*node,start,mid,l,r)+query(2*node+1,mid+1,end,l,r));
	}
}


int main()
{
	ll n;
	while(scanf("%lld",&n))
	{
	for (ll i = 1; i < n+1; ++i) scanf("%lld",&ary[i]);

	build(1,1,n);
	
	ll m;
	scanf("%lld",&m);
	while(m--)
	{
		ll type,x,y;
		scanf("%lld%lld%lld",&type,&x,&y);
		if(x>y)
		{
			ll temp=x;
			x=y;
			y=temp;
		}
		if(type)
		{
			cout<<query(1,1,n,x,y)<<endl;
		}
		else
		{
			update(1,1,n,x,y);
		}
	}	
}
}