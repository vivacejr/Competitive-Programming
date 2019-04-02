#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct M 
{
	ll num;
	ll idx;
};
M Ssp[2000005];
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



int main()
{
	
	ios::sync_with_stdio(false);
	ll t;
	cin >> t;
	ll temp=t;
	while(t--)
	{
		ll n,m,k;
		cin >> n>>m>>k;
		for (int i = 0; i < m+1; ++i)
		{
			Bit[i]=0;
		}
		for (int i = 0; i < k; ++i)
		{
			ll a,b;
			cin >> a >> b;
			Ssp[i].num=a;
			Ssp[i].idx=b;
		}
		
		sort(Ssp,Ssp+k,cmp);
		ll ans=0;
		for (int i = 0; i < k; ++i)
		{
			update(Ssp[i].idx,m);
			// cout << Ssp[i].idx<<endl;
			// cout << query(m)<<" "<<query(Ssp[i].idx+1)<<endl;		
			ans+=query(m)-query(Ssp[i].idx);
			// cout << ans<<endl;
		}
		cout <<"Test case "<<temp-t<<": "<<ans << "\n";


	} 
}