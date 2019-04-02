//enclosing the maximum number of points 
//in a 2-D plane with a fixed-radius circle?

// using shrinking trick

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define vll vector<ll>
#define pll pair<ll,ll> 
#define PI 3.141592654
typedef complex<ld> Point;

ll expo(ll base, ll exponent, ll mod) { ll ans = 1;
    while(exponent !=0 ) {
        if((exponent&1) == 1) 
            ans = (ans*base)%mod ;
        base = (base*base)%mod; exponent>>= 1;
    }return ans%mod;}

Point ary[500]; //complex class in STL

struct ang{
	ld val;
	ld type;
};

bool cmp(ang a,ang b)
{
	return a.val<b.val;
}
ang angle[1000];

ll n,mx=-1;
ld rad=1;

ll solve()
{
	lp(i,1,n+1)
	{
		ll cnt=0;
		ll pt=1;
		lp(j,1,n+1)
		{
			if(i!=j)
			{
				ld d=abs(ary[j]-ary[i]);
				// cout<<d<<endl;
				// cerr<<i<<" "<<j<<endl;
				if(d<=2*rad)
				{
					ld x1=ary[i].real();
					ld y1=ary[i].imag();
					ld x2=ary[j].real();
					ld y2=ary[j].imag();
					ld l1=d/2;
					ld l2=sqrt(rad*rad-l1*l1);
					ld SB=(y2-y1)/d;
					ld CB=(x2-x1)/d;
					ld SA=l2/rad;
					ld CA=l1/rad;
					ld beta=atan2(SB*CA-CB*SA,CA*CB+SA*SB);
					ld alpha=atan2(SA*CB+CA*SB,CA*CB-SA*SB);                                                              ; 
					// cerr<<j<<endl;
					// cerr<<j<<endl;
					angle[cnt].type=1;
					angle[cnt].val=beta;
					cnt++;
					angle[cnt].type=-1;
					angle[cnt].val=alpha+1e-10;
					cnt++;
					if(alpha<beta) pt++;
				}
			}
		}
		sort(angle,angle+cnt,cmp);
		// lp(j,0,cnt) cout<<angle[j].val<<" ";
		cout<<endl;
		lp(j,0,cnt)
		{
			pt+=angle[j].type;
			if(pt>mx) 
				mx=pt;
		}
	}
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    // 1 based indexing 

   	lp(i,1,n+1)
   	{
 		cin >> ary[i].real() >> ary[i].imag();
   	}

   	solve();
   	cout<<mx<<endl;
	return 0;
}
