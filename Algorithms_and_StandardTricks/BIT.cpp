/*kquery using bit*/
/*1 base indexing*/


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct M
{
   	ll key;
   	ll key2;
   	ll key3;	
   	ll key4;
};
bool cmp(struct M a, struct M b)
{
	if(a.key==b.key) return b.key4<=a.key4;
  	return (a.key >  b.key);
}
bool cmp2(struct M a,struct M b)
{
	return a.key4<b.key4;
}

ll bit[30002];


ll update(ll idx,ll n)
{
	while(idx<=n)
	{
		bit[idx]+=1;
		idx=idx+(idx&(-idx	));
	}
}

ll query(ll idx)
{
	ll sum=0;
	while(idx>0)
	{
		sum+=bit[idx];
		idx=idx-(idx&(-idx));
	}
	return sum;
}

inline int in(){int N=0;register char c=getchar();while( c < 48 || c > 57 ){c=getchar();}while(c>47 && c< 58){N = (N << 3) + (N << 1) + (c - 48);c=getchar();}return N;}

struct M Ssp[230000];
int main()
{

	ll n;
	n=in();
	ll q;
	for (int i = 0; i < n; ++i)
	{
		ll a; 
		a=in();
		Ssp[i].key=a;
		Ssp[i].key2=0;
		Ssp[i].key4=i;
		Ssp[i].key3=0;
	}
	q=in();

	for (int i = 0; i < q; ++i)
	{
		ll l,r,k;
		l=in();
		r=in();
		k=in();
		Ssp[i+n].key=k;
		Ssp[i+n].key2=l;
		Ssp[i+n].key3=r;
		Ssp[i+n].key4=i+n;
	}

	sort(Ssp, Ssp+n+q, cmp);

	for (int i = 0; i < n+q; ++i)
	{
		if(!Ssp[i].key2)
		{
			
			update(Ssp[i].key4+1,n);
		}
		else
		{
			// cout <<Ssp[i].key3<<" "<<Ssp[i].key2<<" "<<i<<endl;
			Ssp[i].key=query(Ssp[i].key3)-query(Ssp[i].key2-1);
		}
	}
	// cerr <<"xxx"<<endl;
	sort(Ssp, Ssp+n+q, cmp2);
	for (int i = 0; i < n+q; ++i)
	{
		if(	Ssp[i].key2)
		{
			printf("%lld\n",Ssp[i].key);
		}
	}
}