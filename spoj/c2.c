#include <bits/stdc++.h>
using namespace std;
#define LL long long
map <LL,LL> ans;
LL coins(LL n)
{
	if(n==0)
		return 0;
	else if(!ans[n])
	{
		ans[n]= max(n,coins(n/2) + coins(n/3) + coins(n/4));
	}
	return ans[n];
}
int main() {
	LL n;
	while(scanf("%lld",&n)!=EOF)
	{
		printf("%lld\n",coins(n));
	}

	return 0;
}
