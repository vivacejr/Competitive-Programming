#include<bits/stdc++.h>
using namespace std;
#define ll long long 

map <ll,ll> sto;

//int max(ll a,ll b)
//{
//	return(a > b ? a : b);
//}

ll dp(ll a)
{
	if(a==0)
	{
		return 0;
	}
	else if (sto[a]==0)
	{
		sto[a]= max(a,dp(a/2)+dp(a/3)+dp(a/4)) ;
	}
	return sto[a];
}

int main()
{

	ll a;
	while(scanf("%lld",&a)!=EOF)
	{
		cout<< dp(a)<<endl;
	}
}
