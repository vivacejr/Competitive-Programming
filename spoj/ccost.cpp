#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front


struct X
{
	ll x1,y1,type,idx,val,ans,save;
};
bool cmp(struct X a,struct X b)
{
	if(a.y1==b.y1)
	{
		if(a.x1==b.x1)
		{
			if(a.type==0&&b.type==0)
			{
				return 1;
			}
			else if(a.type==0)
			{
				if(b.type==1)
				return 0;
				else return 1;
			}
			else if(b.type==0)
			{
				if(a.type==1) return 1;
				else return 0;
			}
			else return 1;
		}
		else return a.x1<b.x1;
	}
	else return a.y1<b.y1;
}


ll bit[10000005];
X ary[100000 + 500005];


ll update(ll idx,ll val)
{
	while(idx<=10000001)
	{
		bit[idx]+=val;
		idx=idx+(idx&(-idx	));
	}
}

ll query(ll idx)
{
	ll sum=0;
		// cout<<idx<<endl;

	while(idx>0)
	{
		sum+=bit[idx];
		idx=idx-(idx&(-idx));
		// cout<<idx<<" "<<sum<<endl;
	}
	return sum;
}

int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);		
		// cout<<n<<
		lp(i,0,n)
		{
			ll a,b,c;
			scanf("%lld%lld%lld",&a,&b,&c);
			ary[i].x1=a;
			ary[i].y1=b;
			ary[i].val=c;
			ary[i].type=0;
		}

		ll q;
		scanf("%lld",&q);
		// cout<<q<<endl;
		lp(i,0,2*q)
		{
			scanf("%lld",&ary[i + n].x1);
			scanf("%lld",&ary[i + n].y1);	
			scanf("%lld",&ary[i + n+1].x1);
			scanf("%lld",&ary[i + n+1].y1);
			ary[i+n].type=1;
			ary[i+n+1].type=2;
			ary[i+n].idx=i/2;
			ary[i+n+1].idx=i/2;
			ary[i+n].save=ary[i+n+1].x1;
			ary[i+1+n].save=ary[i+n].x1;
			i++;

		}

		ll final[q];
		sort(ary,ary+n+2*q,cmp);
		lp(i,0,10000002) bit[i]=0;
		lp(i,0,q) final[i]=0;
		// lp(i,0,n+2*q) cout<<ary[i].type<<" "<<ary[i].x1<<" "<<ary[i].y1<<endl; 	
		lp(i,0,n+2*q)
		{
			if(!ary[i].type)
			{
				update(ary[i].x1+1,ary[i].val);
			}
			else
			{
				if(ary[i].type==1)	final[ary[i].idx]-=query(ary[i].save+1)-query(ary[i].x1);
				
				else final[ary[i].idx]-=query(ary[i].save)-query(ary[i].x1+1);
			}
		}
		lp(i,0,q)
		{
			//cout<<final[i]<<" ";
			printf("%lld\n", final[i]);
		}
		//cout<<endl;
	}
	return 0;
}