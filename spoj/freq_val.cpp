/*  Vivace_jr */

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll ary[100005];


struct ped{
	ll preCnt;
	ll sufCnt;
	ll preEl;
	ll sufEl;
	ll mxCnt;
	ll mxEl;
};

struct ped tree[4*100005];

struct ped merge(struct ped l,struct ped r)
{
	struct ped res;
	if(l.preEl==r.preEl)	res.preCnt=l.preCnt+r.preCnt;
	else					res.preCnt=l.preCnt;
	if(l.sufEl==r.sufEl)		res.sufCnt=l.sufCnt+r.sufCnt;
	else					res.sufCnt=r.sufCnt;

	res.preEl=l.preEl;
	res.sufEl=r.sufEl;

	if(l.sufEl==r.preEl)
	{
		if(l.sufCnt+r.preCnt>l.mxCnt)
		{
			if(l.sufCnt+r.preCnt>r.mxCnt)
			{
				res.mxEl=l.sufEl;
				res.mxCnt=l.sufCnt+r.preCnt;
			}
			else
			{
				res.mxEl=r.mxEl;
				res.mxCnt=r.mxCnt;
			}
		}
		else
		{
			if(l.mxCnt>r.mxCnt)
			{
				res.mxEl=l.mxEl;
				res.mxCnt=l.mxCnt;
			}
		   	else
			{
				res.mxEl=r.mxEl;
				res.mxCnt=r.mxCnt;
			}
		}		
	}
	else
	{
		if(l.mxCnt>r.mxCnt)
			{
				res.mxEl=l.mxEl;
				res.mxCnt=l.mxCnt;
			}
		   	else
			{
				res.mxEl=r.mxEl;
				res.mxCnt=r.mxCnt;
			}
	}
	return res;
}

struct ped build(int node,int start,int end)
{
	if(start==end)
	{
		tree[node].preCnt=tree[node].sufCnt=tree[node].mxCnt=1;
		tree[node].preEl=tree[node].sufEl=tree[node].mxEl=ary[start];
		// cout<<start<<" "<<end<<" "<<tree[node].mxCnt<<endl;
		return tree[node];
	}
	else
	{
		int mid=(start+end)/2;
		tree[node]=merge(build(2*node,start,mid),build(2*node+1,mid+1,end));
		// cout<<start<<" "<<end<<" "<<tree[node].mxCnt<<endl;
		return tree[node];
	}
}

struct ped query(int node,int start,int end,int l,int r)
{
		// cout<<node<<" "<<start<<" "<<end<<" "<<tree[node].mxCnt<<endl;

	if(start==end)				return tree[node];
	
	else if(l<=start&&r>=end)	return tree[node];

	else
	{
		int mid=(start+end)/2;
		if(r<=mid) return query(2*node,start,mid,l,r);
		else if(l>mid) return query(2*node+1,mid+1,end,l,r);
		else 
		{
			return merge(query(2*node,start,mid,l,r),query(2*node+1,mid+1,end,l,r));
		}
	}
}


int main()
{

	ios::sync_with_stdio(false);
	int n;
	while( 1 )
	{
		cin >> n;
		// cerr << n;
		if(n==0) break;
		int m;
		cin >> m;
		for (int i = 1; i <= n; ++i) cin >> ary[i];

		build(1,1,n);

		while(m--)
		{
			int l , r;
			cin >> l >> r;
			cout<<query(1,1,n,l,r).mxCnt<<endl;
		}


	}
}