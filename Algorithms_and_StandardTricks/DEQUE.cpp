	/*spoj subarrays - 
using dqueues */

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ll n,k;
	cin >> n;
	ll ary[n];
	for (int i = 0; i < n; ++i) cin >> ary[i];
	cin >> k;
	
	vector<ll> A;
	deque<ll> q;

	for (int i = 0; i < k; ++i)
	{
		while(!q.empty()&&ary[i]>=ary[q.back()])  q.pop_back();

		q.push_back(i);
	}
	A.push_back(ary[q.front()]);

	for (int i = k; i < n; ++i)
	{
		while(!q.empty()&&q.front()<=i-k) q.pop_front();
		while(!q.empty()&&ary[i]>=ary[q.back()])  q.pop_back();

		q.push_back(i);

		A.push_back(ary[q.front()]);
		
	}
	for (int i = 0; i < A.size(); ++i)
	{
		cout << A[i]<<" ";
	}
	cout << endl;

}
