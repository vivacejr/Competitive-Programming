#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll Bit[200005];

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
	ll t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		ll ary[n+1];
		for (int i = 0; i <= n+1; ++i)
		{
			Bit[i]=0;
			ary[i]=0;
		}
		ll prev=0;
		for (int i = 1; i <=n ; ++i)
		{

			if(n-prev-(query(n)-query(prev)) >=	i+1)
			{
				// cerr<<1<<endl;
				ll hi=n;
				ll lo=prev+1;
				while(hi>lo)
				{
					// cerr<<lo<<" "<<hi<<" "<<	i<<endl;
					ll mid=(hi+lo)/2;
					if(mid-prev-(query(mid)-query(prev)) >=	i+1)
					{
						hi=mid;						
					}
					else
					{
						lo=mid+1;
					}
				}
				update(lo,n);
				ary[lo]=i;
				prev=lo;
			}
			else
			{
				ll temp=i+1;
				temp=temp-(n-prev-(i-1-query(prev)));
				
				if(temp%(n-i+1)!=0)	temp=temp%(n-i+1);
				else temp=n-i+1;
				ll hi=n;
				ll lo=1;
				// cout<<temp<<" "<<i<<endl;
				while(hi>lo)
				{
					ll mid=(hi+lo)/2;
					if(mid-(query(mid)) >=	temp)
					{
						hi=mid;						
					}
					else
					{
						lo=mid+1;
					}
				}
				update(lo,n);
				ary[lo]=i;
				prev=lo;
			}
		}	
		for (int i = 1; i <= n; ++i)
		{
			cout << ary[i]<<" ";
		}
		cout<<endl;
	}
}