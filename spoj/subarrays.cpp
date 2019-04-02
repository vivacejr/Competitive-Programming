#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ll n;
	cin >> n;
	ll ary[n];
	for (int i = 0; i < n; ++i) cin >> ary[i];
	ll k;
	cin  >> k ;
	ll freq[1000001];
	for (int i = 0; i < 1000001; ++i)
	{
		freq[i]=0;
	}
	set<ll> A;
	for (int i = 0; i < k; ++i)
	{
		A.insert(ary[i]);
		freq[ary[i]]++;
	}
	set<ll>::iterator it;
	it=A.end();
	it--;
	cout<<*it<<" ";
	for (int i = k; i < n; ++i)
	{
		freq[ary[i]]++;
		if(freq[ary[i]]==1)	 A.insert(ary[i]);
		freq[ary[i-k]]--;
		if(freq[ary[i-k]]==0) 	
		{
			A.erase(ary[i-k]);
		}
		it=A.end();
		it--;
		cout<<*it<<" ";	
	}
	cout<<endl;
}