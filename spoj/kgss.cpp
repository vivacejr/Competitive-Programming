#include<bits/stdc++.h>
using namespace std;
struct ped{
	int mx;
	int mxel;
};
struct ped tree[3000005];
int ary[1000005];

int build(int node,int start,int end)
{
	if(start==end)
	{
		tree[node].mx=ary[start];
		tree[node].mxel=ary[start];
	}
	else
	{
		int mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node].mxel=max(tree[2*node].mxel,tree[2*node+1].mxel);
		tree[node].mx=max(tree[2*node].mx,max(tree[2*node+1].mx,tree[2*node].mxel+tree[2*node+1].mxel));
		// cout <<start<<" "<<end<<" "<< node << " "<<tree[node].mx<<endl;
		
	}
}
int ans=-1;
int update(int node,int start,int end,int a,int b)
{
	// cout <<start<<" "<<end<<" "<< node<<endl;
	if(start==end)
	{
		ary[start]=b;
		tree[node].mx=ary[start];
		tree[node].mxel=ary[start];
	}
	else
	{
		int mid=(start+end)/2;
		if(a<=mid)	update(2*node,start,mid,a,b);
		else		update(2*node+1,mid+1,end,a,b);

		tree[node].mxel=max(tree[2*node].mxel,tree[2*node+1].mxel);
		tree[node].mx=max(tree[2*node].mx,max(tree[2*node+1].mx,tree[2*node].mxel+tree[2*node+1].mxel));
	}	
}

int query(int node,int start,int end,int x ,int y)
{
	if(y<start||x>end)
	{
		return 0;
	}
	else
	{
		if(start>=x && end<=y)
		{
			if(ans<tree[node].mx)
			{
				ans=tree[node].mx;
			}
			return tree[node].mxel;
		}
		else
		{
			int mid=(start+end)/2;
			int x1=query(2*node,start,mid,x,y);
			int x2=query(2*node+1,mid+1,end,x,y);
			if(x2+x1>ans)
			{
				ans=x1+x2;
			}
			return max(x1,x2);
		}
	}
	
}
int main()
{	
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> ary[i];

	build(1,1,n);

	int ques;
	cin >> ques;

	while(ques--)
	{
		char c;
		int a,b;
		cin >> c >> a >> b;
		if(c=='U')
		{
			update(1,1,n,a,b);
		}
		else
		{
			ans=-1;
			int waste=query(1,1,n,a,b);
			cout << ans<<endl;
		}
	}
}