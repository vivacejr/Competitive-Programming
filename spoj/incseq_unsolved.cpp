#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=5000000;
ll dp[100001][51];
struct M 
{
	ll num;
	ll idx;
};
M Ssp[2000005];
ll bit[200005];

bool cmp(M a,M b)
{
	if(a.num==b.num) return a.idx>b.idx;
	return a.num<b.num;
}

ll update(ll idx,ll n)
{
	while(idx<=n)
	{
		bit[idx]+=1;
		idx=idx+(idx&(-idx));	
	}
}

ll query(ll idx)
{
	ll sum=0;	
	while(idx>0)
	{
		sum+=bit[idx];
		idx=idx-(idx&(-idx));
	}
	return sum;
}





int main()
{
	ll n,k;
	cin >> n >> k;
	ll ary[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> Ssp[i].num;
		Ssp[i].idx=i;
	}
	sort(Ssp,Ssp+n,cmp);
	ll ans=0;
	for (int i = 0; i < n; ++i)
	{
		ans=ans+comb(query(Ssp[i].idx+1),k-1)%mod;
		ans=ans%mod;
		cout << ans << endl;
		update(Ssp[i].idx+1,n);
	}
	cout << ans << endl;



}