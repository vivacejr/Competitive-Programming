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

ll update(ll node,ll start,ll end,ll l ,ll r,ll val)
{
    if(lazy[node])
    { 
        tree[node] = lazy[node];   
        if(start != end)
        {
            lazy[node*2] = lazy[node];                 
            lazy[node*2+1] = lazy[node];               
        }
        lazy[node] = 0;                                 
    }
    if(start>r||end<l||start>end) return 0;

	if(start>=l&&r>=end)
	{
		tree[node]=val;
		if(start!=end)
		{
			lazy[2*node]=val;
			lazy[2*node+1]=val;
		}
	}
	else
	{
		ll mid=(start+end)/2;
		update(2*node,start,mid,l,r,val);
		update(2*node+1,mid+1,end,l,r,val);
	}
}

ll query(ll node,ll start,ll end,ll l,ll r)
{
	if(lazy[node])
    { 
        tree[node] = lazy[node];   
        if(start != end)
        {
            lazy[node*2] = lazy[node];                 
            lazy[node*2+1] = lazy[node];               
        }
        lazy[node] = 0;                                 
    }
    if(start>r||end<l||start>end) return 0;
   	if(start>=l&&r>=end)
	{
		return tree[node];
	}
	else
	{
		ll mid=(start+end)/2;
		return max(query(2*node,start,mid,l,r),query(2*node+1,mid+1,end,l,r));
	} 
}


int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin >> n;
		ll ary[2*n];
		ll temp[2*n];
		lp(i,0,2*n)
		{
			cin>>ary[i];
			temp[i]=ary[i];
		}
		sort(ary,ary+2*n);
		vector<ll>V;
		map<ll,ll> M;

		lp(i,0,2*n)
		{
			V.pb(ary[i]);
			ll temp=i;
			while(i<2*n&&ary[i]==ary[temp])
			{
				i++;
			}
			i--;
		}
		lp(i,0,V.size())
		{
			M.insert	(mp(V[i],i+1));
		}
		build(1,1,V.size());

		ll v=V.size();
		for (int i = 0; i < n; ++i)
		{
			ll l=M[temp[2*i]];
			ll r=M[temp[2*i+1]];
			update(1,1,v,l,r,i+1);

		}
		set<ll> S;
		lp(i,1,v+1)
		{
			S.insert(query(1,1,v,i,i));
		}
		cout<<S.size()<<endl;
	}
	return 0;
}