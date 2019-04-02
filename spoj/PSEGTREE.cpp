#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back	
#define mp make_pair
#define pf push_front
#define F first
#define S second
#define vll vector<ll>
#define pll pair<ll,ll> 
#define endl "\n"

const ll N=1e5+5;
ll v[N],n,c;
map<ll,ll> M;

struct node{
	node * left;
	node * right;	
	ll val;
};

node * root;
node * R[N];

node * init()
{
	node * temp=new node;
	temp->left = temp->right = NULL;
	temp->val = 0;
	return temp;
}

node * build(ll l,ll r,ll w,ll val,node * par)
{
	// cerr <<l<<" "<<r<<endl;
	if(l==r)
	{
		node * temp=init();
		temp->val=val;
		return temp;
	}
	if(w>=l&&w<=r)
	{
		ll mid=(l+r)/2;
		node * temp= init();
		//if diff in left part create new left node else create new right node
		if(w<=mid)
		{
			temp->left=build(l,mid,w,val,par->left);
			temp->right=par->right;
		}
		else
		{
			temp->right=build(mid+1,r,w,val,par->right);
			temp->left=par->left;
		}
		temp->val=temp->right->val+temp->left->val;
		return temp;
	}
}

node *buildspecial(ll l,ll r)
{
	if(l==r)
	{
		node * temp =init();
		temp->val=v[l];
		return temp;
	}
	ll mid=(l+r)/2;
	node * temp= init();
	temp->left=buildspecial(l,mid);
	temp->right=buildspecial(mid+1,r);
	temp->val=temp->right->val+temp->left->val;
	return temp;
}
ll query(node* a,ll st,ll endd,ll l ,ll r )
{
	// cerr<<st<<" "<<endd<<" "<<a->val<<endl;
	if(st>r||endd<l)return 0;

	if(st>=l&&endd<=r)
	{
		return(a->val);
	}
	ll m=(st+endd)>>1;
	return query(a->left,st,m,l,r)+query(a->right,m+1,endd,l,r);
}
int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
	// cout.tie(NULL);
    cin >> n;
    lp(i,0,n)
    {
    	cin >> v[i];
    }
    ll k=1;
    R[0]=init();
    R[0]=	buildspecial(0,n-1);
    ll q;
    cin >> q;
	while(q--)
	{
		ll type;
		cin >> type;
		ll idx,l,r;
		if(type==1)
		{
			cin >> idx >> l >> r;
			R[k]=init();
			// cerr<<1<<endl;
			ll z=query(R[idx],0,n-1,l-1,l-1);
			R[k]=build(0,n-1,l-1,r+z,R[idx]);
			k++;
		}	
		else 
		{
			// cerr<<1
			cin >> idx >> l >> r;
			cout<<query(R[idx],0,n-1,l-1,r-1)<<endl;
		}
	}
	return 0;
}	