	#include<bits/stdc++.h>
	using namespace std;
	typedef long long int ll;

	#define lp(var,start,end) for (ll var = start; var <end ; ++var)
	#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
	#define pb push_back
	#define mp make_pair
	#define pf push_front

	int main()
	{
		ll t;
		cin >> t;
		while(t--)
		{
			ll n,m;
			cin >> n >> m;
			ll ary[n][m];
			lp(i,0,n)
			{
				lp(j,0,m)
				{
					cin >> ary[i][j];
				}
			}
			ll cnt=0;
			lp(i,0,n)
			{
				ll prev;
				if(ary[i][m-1])
					prev=1; //win
				else
				    prev=0; 
				rlp(j,m-2,0)
				{
					if(ary[i][j]>1)
					{
						prev=1;
					}
					else if(ary[i][j]==1)
					{
						prev=1-prev;
					}
				}
				if(prev) cnt++;
			}
			if(cnt%2)cout<<"FIRST"<<endl;
			else cout<<"SECOND"<<endl;
		}
		return 0;
	}