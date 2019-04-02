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
	ll cnt=1;

	while(1)
	{
		string s;
		cin >> s;
		ll len=s.length();
		ll op=0;
		ll cl=0;
		ll ans=0;
		if(s[0]=='-') break;
		lp(i,0,len)
		{
			if(s[i]=='{')
			{
				op++;
				// cout<<op<<endl;
			}
			else
			{
				cl++;
				if(op<cl)
				{
					ans++;
					op++;
					cl--;
				}
				if(op>=cl)
				{
					op-=cl;
					cl=0;
				}
			}
		}
		// cout<<op<<endl;
		cout<<cnt<<". "<<ans+op/2<<endl;
		cnt++;
	}
	return 0;
}