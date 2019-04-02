#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define F first
#define S second
#define vll vector<ll>
#define pll pair<ll,ll> 
#define endl "\n"
ll cnt=0;
ll freq[10];

ll f()
{
	// cout<<cnt<<" ";
	cout<<"impossible"<<endl;
}


ll p()
{
	ll f=0;
	// cout<<cnt<<" ";
	if(freq[0]>0)
	{
		rlp(i,9,0)
		{

			lp(j,0,freq[i])
			{
				if(i!=0||f==1)
				{
					f=1;
					cout<<i;
				}
				else
				{
 					cout<<0;
 					break;
				}
			}
		}	
		cout<<endl;
	}
	else
	{
		freq[5]--;
		rlp(i,9,0)
		{
			lp(j,0,freq[i])
			{
				cout<<i;
			}
		}	
		cout<<5<<endl;
	}
	
}

int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		cnt++;
		string s;
		cin >> s;
		memset(freq,0,sizeof freq);
		lp(i,0,s.length())
		{
			freq[s[i]-'0']++;
		}
		ll sum=0;
		lp(i,0,10)
		{
			sum+=freq[i]*i;
		}
		if(freq[0]>0||freq[5]>0)
		{
			if(sum%3==0)
			{
				p();
				continue;
			}
			else if(sum%3==1)
			{
				if(freq[1]>0)
				{
					freq[1]--;
					p();
				}
				else if(freq[4]>0)
				{
					freq[4]--;
					p();
				}
				else if(freq[7]>0)
				{
					freq[7]--;
					p();
				}
				else
				{
					if(freq[2]>1)
					{
						freq[2]-=2;
						p();
					}
					else if(freq[2]>0&&(freq[5]>1||(freq[5]>0&&freq[0]>0)))
					{
						freq[2]--;
						freq[5]--;

						p();
					}
					else if(freq[5]>2||(freq[5]>1&&freq[0]>0))
					{
						freq[5]-=2;
						p();
					}
					else if(freq[2]>0&&freq[8]>0)
					{
						freq[2]--;
						freq[8]--;
						p();
					}
					else if((freq[5]>1||(freq[5]>0&&freq[0]>0))&&freq[8]>0)
					{
						freq[5]--;
						freq[8]--;
						p();
					}
					else if(freq[8]>1)
					{
						freq[8]-=2;
						p();
					}
					else
					{
						f();
						continue;
					}
				}
			}	
			else
			{
				if(freq[2]>0)
				{
					freq[2]--;
					p();
				}
				else if((freq[5]>1)||(freq[5]>0&&freq[0]>0))
				{
					freq[5]--;
					p();
				}
				else if(freq[8]>0)
				{
					freq[8]--;
					p();
				}
				else
				{
					if(freq[1]>1)
					{
						freq[1]-=2;
						p();
					}
					else if(freq[1]>0&&freq[4]>0)
					{
						freq[1]--;
						freq[4]--;
						p();
					}
					else if(freq[4]>1)
					{
						freq[4]-=2;
						p();
					}
					else if(freq[1]>0&&freq[7]>0)
					{
						freq[1]--;
						freq[7]--;
						p();
					}
					else if(freq[4]>0&&freq[7]>0)
					{
						freq[4]--;
						freq[7]--;
						p();
					}
					else if(freq[7]>1)
					{
						freq[7]-=2;
						p();
					}
					else 
					{
						f();
						continue;
					}
				}
			}
		}
		else
		{
			f();
			continue;
		}
		
	}	    
	return 0;
}