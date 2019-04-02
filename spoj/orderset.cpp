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


ll del(ll idx,ll n)
{
	while(idx<=n)
	{
		Bit[idx]-=1;
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
	ll n;
	cin >> n;
	ll ary[n];
	ll val[n];
	map<ll,ll> M;
	map<ll,ll> R;
	ll k=0;
	ll sto[n];
	for (int i = 0; i < n; ++i)
	{
		char c;
		cin >> c >> val[i];
		if(c=='I')	ary[i]=1;
		if(c=='D')  ary[i]=2;
		if(c=='C')	ary[i]=3;
		if(c=='K')  ary[i]=4;
		if(c=='I') 
		{
			 sto[k]=val[i];
			 k++;
		}

	}
	sort(sto,sto+k);
	ll cnt=1;
	ll temp=0;
	ll z=k;
	for (int i = 0; i < k; ++i)
	{
			if(	M.find(sto[i])==M.end()	)
			{
				M.insert(make_pair(sto[i],cnt));
				R.insert(make_pair(cnt,sto[i]));
				// cout << sto[i]<<" "<<	cnt << endl;
				cnt++;
			}
			else
			{
				z--;
			}
	}
	// cout << z << endl;
	ll present[n];
	for (int i = 0; i < n; ++i) present[i]=0;
		ll p=0;
	set<ll> S;
	set<ll>::iterator it;
	for (int i = 0; i < n; ++i)
	{
		// cerr << i << endl;
		if(ary[i]==1)
		{
			// cerr << M[val[i]]<<endl;
			if(!present[M[val[i]]])
			{
				// cout << M[val[i]]<<endl;
				S.insert(val[i]);
				p++;
				update(M[val[i]],n);
				present[M[val[i]]]=1;
			}
		}
		else if(ary[i]==2)
		{
			if(present[M[val[i]]])
			{
				S.erase(val[i]);
				p--;
				del(M[val[i]],n);
				present[M[val[i]]]=0;
			}
		}
		else if(ary[i]==3)
		{
			// cerr<<val[i]<<" ";
			ll c=(M.lower_bound(val[i]))->first;
			// cerr<<c<<" ";
			if(M.lower_bound(val[i])==M.end()) 
			{
				// cerr<<1<<endl;	
				it=S.end();
				it--;
				// cerr<<1<<endl;
				if(val[i]==*it)
				{
					cout << p-1<<endl;
				}
				else
				{
								cout << p << endl; 	
				}
			}
			
			else
			{
				// cerr<<M[c]<<endl;
				cout<<	query(M[c]-1)<<endl;
			}
		}
		else
		{
			if(query(z)<val[i])
			{
				cout<<"invalid"<<endl;
			}
			else if(val[i]==1)
			{
				cout << *(	S.begin()) << endl;
			}
			else
			{
				ll hi=z;
				ll lo=1;
				ll x=val[i];
				// cout << x << endl;
				while(hi>lo)
				{
					// cout << hi <<" "<<lo << endl;
					ll mid=(hi+lo+1)/2;
					// cout << mid<<" "<<query(mid)<<endl;
					if(query(mid)>=x)
					{
						hi=mid-1;
					}
					else
					{
						lo=mid;
					}
				}
				// cout << lo+1 << " ";
				cout<<R[lo+1]<<endl;
			}
		}

	}
}