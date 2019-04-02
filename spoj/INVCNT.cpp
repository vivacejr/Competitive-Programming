#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct M 
{
	ll num;
	ll idx;
};
M Ssp[200005];
ll Bit[200005];


bool cmp(M a,M b)
{
	if(a.num==b.num) return a.idx<b.idx;
	return a.num<b.num;
}

ll update(ll idx,ll n)
{
	while(idx<=n)
	{
		Bit[idx]+=1;
		idx=idx+(idx&(-idx));	
	}
}

ll query(ll idx)
{
	ll sum=0;
	while(idx>0)
	{
		sum+=Bit[idx];
		idx=idx-(idx&(-idx));
	}
	return sum;
}
ll ary[200005];


int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		for (int i = 0; i < n+1; ++i)
		{
			Bit[i]=0;
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> ary[i];
			Ssp[i].num=ary[i];
			Ssp[i].idx=i;
		}
		
		sort(Ssp,Ssp+n,cmp);
		ll ans=0;
		for (int i = 0; i < n; ++i)
		{
			update(Ssp[i].idx+1,n);
			ans+=query(n)-query(Ssp[i].idx+1);
		}
		cout << ans << endl;


	} 
}