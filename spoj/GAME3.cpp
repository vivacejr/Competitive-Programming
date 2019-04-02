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
		ll n;
		cin >> n;
		if(n%2==0)
		{
			cout<<"Marica"<<endl;
		}
		else
		{
			n--;
			ll flag=1;//alt
			ll ans=0;//lose
			while(n>1)
			{
				n/=2;
				if(flag==1)
				{
					ans=1;
					flag=2;
				}
				else if(flag==2) 
				{
					if(n%2==1)
					{
						cout<<"Marica"<<endl;
						ans=3;
						break;
					
					}
					else
					{
						flag=1;
						ans=0;
					}
				}
				else
				{
					cout<<"Marica"<<endl;
					ans=3;
					break;
				}
				// cout<<ans<<" "<<n<<" "<<flag<<endl;
			}
			if(ans==1)
			{
				cout<<"Ivica"<<endl;
			}
			else if(ans==0)
			{
				cout<<"Marica"<<endl;
			}
		}
	}
	return 0;
}