#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct ped{
	ll open;
	ll close;
};
//open is 0
int ary[100005];
struct ped tree[4*100005];

struct ped merge(struct ped l,struct ped r)
{
	struct ped res;
	// cout << l.open<<" "<<l.close<<" "<<r.open<<" "<<r.close<<endl;
	if(l.open>=r.close)	res.open=r.open+l.open-r.close;
	else				res.open=r.open;

	if(r.close>=l.open) res.close=l.close+r.close-l.open;
	else				 res.close=l.close;
	// cout << l.open<<" "<<l.close<<" "<<r.open<<" "<<r.close<<endl;
	return res;
}

struct ped build(int node ,int start, int end)
{
	if(start==end)
	{
		if(ary[start])
		{
			tree[node].close=1;
			tree[node].open=0;
		}
		else
		{
			tree[node].open=1;
			tree[node].close=0;
		}

		return tree[node];

	}
	else
	{
		int mid=(start+end)/2;
		tree[node]=merge(build(2*node,start,mid),build(2*node+1,mid+1,end));
		// cout <<node<<" "<<start<<" "<<end<<" "<<tree[node].open<<" "<<tree[node].close<<endl;

		return tree[node];
	}
}

struct ped query(int node,int start,int end,int ind)
{

	if(start==end)
	{


		tree[node].close=1-tree[node].close;
		tree[node].open=1-tree[node].open;
		// cout <<node<<" "<<tree[node].open<<" "<<tree[node].close<<endl;
		return tree[node];
	}
	else
	{
		int mid=(start+end)/2;
		if(ind <=mid) 
		{
			tree[node]=merge(query(2*node,start,mid,ind),tree[2*node+1]);
		}
		else 
		{
			tree[node]=merge(tree[2*node],query(2*node+1,mid+1,end,ind));
		}
			// cout <<start<<" "<<end<<" "<<node<<" "<<tree[node].open<<" "<<tree[node].close<<endl;

		return tree[node];
	}
}


int main()
{
	int t=10;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		char c;
		char str[100005];
		scanf("%s",str);
		// cout << str;
		for (int i = 1; i <= n; ++i)
		{
			if (str[i-1]=='(')
			{
				ary[i]=0;
			}
			else
			{
					ary[i]=1;
			}
		}

		build(1,1,n);
		
		int q;
		scanf("%d",&q);
		cout << "Test "<<10-t<<":"<<endl;
		
		while(q--)
		{
			int ind;
			scanf("%d",&ind);
			struct ped ans;
			if (ind) 	
			{
				ans=query(1,1,n,ind);
			}
			else
			{
				if(tree[1].open!=0||tree[1].close!=0)
				{
					printf("NO\n");
				}
				else
				{
					printf("YES\n");
				}
			}
		}

	}
}