#include<bits/stdc++.h>
using namespace std;
ll sum[N],ary[N];
ll root(ll i)
{
	while(ary[i]!=i)
	{
		ary[i]=ary[ary[i]];
		i=ary[i];//**************************************
	}
	return i;
}

ll un(ll a,ll b)
{
	ll rA=root(a);
	ll rB=root(b);
	if(rA==rB)return 0;
	if(sum[rA]>sum[rB])
	{
		ary[rB]=rA;
		sum[rA]+=sum[rB];
	}
	else
	{
		ary[rA]=rB;
		sum[rB]+=sum[rA];
	}
}
bool find(ll a,ll b)
{
	return root(a)==root(b) ? true : false;
}

int main()
{
		ll n=10;
		for(ll i=0;i<n;i++)
		{
			Ary[i]=i;
			Sum[i]=1;
		}

}