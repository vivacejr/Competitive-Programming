#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef  double db;
#define sz(a) (int)(a).size()

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
const ll N=1e5+5;

namespace fft 
{ 
	const db PI = acos((db)-1) ;
	template < class T> class comp 
	{
		public: T r,i; comp (T a = (T)0, T b = (T)0) : r(a), i(b) {}
	 	comp conj() { return comp(this->r, -(this->i));  }
	    comp operator=(const comp& a){ this->r = a.r, this->i = a.i; return *this; }
	    comp operator+(const comp& b){ return comp(r+b.r, i+b.i); }
	    comp operator-(const comp& b){ return comp(r-b.r, i-b.i); }
		comp operator*(const T& num){ return comp(r*num, i*num); }
	    comp operator/(const T& num){ return comp(r/num, i/num); }
	    comp operator*(const comp& b){ return comp(r*b.r - i*b.i, i*b.r + r*b.i);}
	    comp operator/(const comp& b){ return ((*this)*comp(b.r,-b.i))/(b.x*b.x + b.y*b.y);}
	};
	#define cd comp<double>
    vector<cd> w ; vll rev ;
    void revb(int nl) 
    {
    	static int l=-1;
		if(nl==l) return; 
		int t,j,k=0;l=nl;
		rev.resize(l+1); 
		while ((1 << k) < nl) 
			++k;
        lp(i,1,l+1) 
        {
        	j=rev[i-1]; t=k-1;
			while(t >= 0 && ((j >> t) & 1) )  
				j ^= (1<<t) , --t ;
            if(t>=0)
             j ^= (1<<t), --t ; rev[i] = j;
        }
    }
    void fft(vector<cd> &poly,int inv = false)
    {//sz(poly) should be 2^x
        int len, l; 
        revb(poly.size());
        lp(i,0,poly.size()) 
        	if(rev[i]>i) 
        		swap(poly[i],poly[rev[i]]);
        cd u,v; 
        if(sz(w) < sz(poly)) 
        	w.resize(sz(poly)) ;
        for(len=2, l=1; len<=sz(poly); len +=len, l +=l) 
        {
            if(w[l].r==0 && w[l].i==0) 
            { 
            	db ang = PI / l;
                cd ww(cos(ang),sin(ang));
                if(l > 1) 
                { 
                	lp(j,0,l) 
                		w[l+j] = (j&1) ? w[(l+j)>>1]*ww : w[(l+j)>>1] ;
                } 
                else 
                	w[l] = cd(1.0,0.0);
            } 
            for(int i = 0; i < sz(poly); i += len) 
            {
            	lp(j,0,l) 
	            {
	                u = poly[i+j], v = poly[i+j+l] * (inv ? w[l+j].conj() : w[l+j]) ;
	                poly[i+j] = u + v , poly[i+j+l] = u - v ;
				}
        	}
        } 
        if(inv) 
        	for(auto &x:poly) 
        		x = x /sz(poly) ;//returns vi:convolution of a,b
    } 
    vll multiply(vll &a,vll &b)
    { 
    	int bi=1, sz1=a.size()+b.size(), rsz;
        //making total size a power of 2
        while((1<<bi)<sz1) 
            ++bi; 
        rsz = (1<<bi);
        vector<cd> poly(rsz) ; 
        lp(i,0,a.size()) 
        	poly[i].r=a[i] ;
        lp(i,0,b.size())
        	poly[i].i = b[i] ; 
        fft(poly);
        cd p, qtmp, q; 
        poly[0] = poly[0].r * poly[0].i ; // for i = 0
        lp(i,1,(rsz>>1)+1)
        { 
        	p=poly[i]+poly[rsz - i].conj(), qtmp=poly[rsz-i]-poly[i].conj();
            q.r=qtmp.i, q.i=qtmp.r ; poly[i] = (p * q) * 0.25;
            if(i) poly[rsz-i] = poly[i].conj();
        } 
        fft(poly,true);//add mod in line below
        vll ans(sz1-1); 
        lp(i,0,ans.size()) 
        	ans[i] = (ll)(poly[i].r + 0.5) ;
        /*int cr=0; FN(i,sz(ans)) { // Uncomment for multiplication of two num
          ans[i] += cr; cr = ans[i] / 10; ans[i] %= 10;
		}*/
        return ans;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	    
	return 0;
}