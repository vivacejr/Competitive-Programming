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
#define sz(a) (int)(a).size()


#define cpx complex<double>
#define vlc vector<cpx>
#define pi 3.14159265359

const ll N=1e5+5;

ll A[N],B[N];

vlc fft(vll v)
{
	ll n=v.size();
	if(n==1) //constant
	{
		vlc tmp; //just converting it into complext vector
		tmp.pb(cpx(1.0*v[0],0.0));
		return tmp;
	}

	ll h = n/2;
	vll v1,v2;

	lp(i,0,h)
	{
		v1.pb(v[i*2]); //even coeff
		v2.pb(v[i*2+1]); //odd
	}
	vlc a1=fft(v1),a2=fft(v2);
	vlc ans(n); 
	cpx w(1,0),wn(cos(2*pi/n),sin(2*pi/n));
	lp(i,0,h)
	{
		ans[i]=a1[i]+w*a2[i];
		ans[i+h]=a1[i]-w*a2[i];
		w*=wn;
	}
	return ans;
}


vlc ifft(vlc v)
{
	ll n=v.size();
	if(n==1) return v;

	ll h = n/2;
	vlc v1,v2;

	lp(i,0,h)
	{
		v1.pb(v[i*2]); //even coeff
		v2.pb(v[i*2+1]); //odd
	}
	vlc a1=ifft(v1),a2=ifft(v2);
	vlc ans(n); 
	cpx w(1,0),wn(cos(2*pi/n),sin(-2*pi/n)); //conjugate
	lp(i,0,h)
	{
		ans[i]=a1[i]+w*a2[i];
		ans[i+h]=a1[i]-w*a2[i];
		w*=wn;
	}
	return ans;
}

vector<cpx> Mul(vlc c1,vlc c2)
{
	ll n1=c1.size(),n2=c2.size(),mx,mn;
	mx=max(n1,n2);
	mn=min(n1,n2);
	vlc res;
	lp(i,0,mn) res.pb(c1[i]*c2[i]);
	lp(i,mn,mx)res.pb(cpx(0,0));
	return res;
}



int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    ll n;
    cin >> n;
    
    lp(i,0,n)  	cin >> A[i]; //c0+c1x+c2x^2...
    lp(i,0,n)  	cin >> B[i];
    vll v1,v2;
    lp(i,0,n)
    {
    	v1.pb(A[i]);
    	v2.pb(B[i]);
    }
    
    //making n a multiple of 2
    ll j=1;
    while(j<n) 	j=j<<1;
    n=j;
    j*=2;
    n*=2;
    lp(i,v1.size(),j)
    {
    	v1.pb(0);
    	v2.pb(0);	
    }
    vlc final;
    final = ifft(Mul(fft(v1),fft(v2)));
    rlp(i,n-1,0)
    {
    	cout<<real(final[i])/j<<" "; 
    }
    cout<<endl;
	return 0;
}