#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ll n,m;
	cin >> n >> m;
	ll ary[n];
	for (int i = 0; i < n; ++i)	cin >> ary[i];
	ll sum=0;
	ll j=0;
		ll mx=-1;
	for (int i = 0; i < n; ++i)
	{
		while(sum+ary[i]>m && j<i)
		{
			sum-=ary[j];
			j++;
		}
		sum+=ary[i];
		mx=max(sum,mx);
	}
	cout << mx << endl;
}