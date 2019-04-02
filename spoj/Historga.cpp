#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	stack<ll> S;
	ll n;
	while(1)
	{
		cin >> n;
		if(n==0) break;
		ll ary[n+1];
		for (int i = 1; i <= n; ++i) cin >> ary[i];
		S.push(0);
		ll area=0;
		ll mx=-1;
		ary[0]=-1;
		for (int i = 1; i <= n; ++i)
		{
			if(ary[i]>=ary[S.top()]) 
			{
				S.push(i);
			}
			else
			{
				ll temp=S.top();
				while(ary[S.top()]==ary[temp])
				{
					S.pop();
					mx=max((i-S.top()-1 )*(ary[temp]),mx);
				}
				i--;
			}
		}
		while(!S.empty())
		{
			ll temp=S.top();
			{
				while(!S.empty()&&ary[S.top()]==ary[temp])
				{
						mx=max((n-S.top()+1)*(ary[temp]),mx);
						S.pop();
						if(S.size()==2)
						{	
							mx=max(ary[S.top()]*n,mx);
							S.pop();
						}	
				}
			}
		}
			cout << mx << endl;
		
	}
}