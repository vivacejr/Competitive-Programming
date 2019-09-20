// https://www.spoj.com/problems/SUBST1/
// find distinct substrings in array.

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
 
#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define pll pair<ll,ll> 
#define vpll vector<pll>
#define all(X) X.begin(),X.end()
#define endl "\n"
#define SET(A, val) memset(A, val, sizeof(A))
// Structure to store information of a suffix 
#define FN(i, n) for (int i = 0; i < (int)(n); ++i)
#define FEN(i,n) for (int i = 1;i <= (int)(n); ++i)
#define sz(a) (int)(a).size()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repv(i,a,b) for(int i=b-1;i>=a;i--)
const int N = (int)2e5 + 10;
const int LOGN = 22;
vector<int> lcp(N, 0); 
//SA[i] = ith Lexicographically smallest suffixs index.
int
RA[LOGN][N],SA[N],tempSA[N],cnt[N],LCP[LOGN][N];
void cSort(int l,int k,int n) {
        SET(cnt,0);
    rep(i,0,n) cnt[(i+k<n?RA[l][i+k]:0)]++;
    int maxi=max(300,n),t;
    for(int i=0,sum=0;i<maxi;i++) {
        t = cnt[i], cnt[i] = sum, sum += t;// index
    }
    rep(i,0,n)tempSA[cnt[(SA[i]+k<n?RA[l][SA[i]+k]:0)]++]=SA[i];
    rep(i,0,n)SA[i]=tempSA[i];
}//dollar[i]: next â��$â�� in string.
void build_SA(string &s){
    int n = sz(s);
    rep(i,0,n) RA[0][i] = s[i], SA[i] = i;
    rep(i,0,LOGN-1){
        int k=(1<<i);
        if(k>=n)break;
        cSort(i,k,n);cSort(i,0,n);
        int rank=0;RA[i+1][SA[0]]=rank;
        rep(j,1,n){
            if((RA[i][SA[j]]==RA[i][SA[j-1]])&&(RA[i][SA[j]+k]==RA[i][SA[j-1]+k]))
                RA[i+1][SA[j]]=rank;
            else RA[i+1][SA[j]]=++rank;
        }
    }
}
 
vector<int> build_LCP(string txt) 
{ 
	ll n=txt.size();
    vector<int> invSuff(n, 0); 
    for (int i=0; i < n; i++) 
        invSuff[SA[i]] = i; 
    int k = 0; 
    for (int i=0; i<n; i++) 
    { 
        if (invSuff[i] == n-1) 
        { 
            k = 0; 
            continue; 
        } 
        int j = SA[invSuff[i]+1]; 
        while (i+k<n && j+k<n && txt[i+k]==txt[j+k]) 
            k++; 
        lcp[invSuff[i]] = k; // lcp for the present suffix. 
        if (k>0) 
            k--; 
    } 
    return lcp; 
} 
//build_LCP(s)
// Driver program to test above functions 
int main() 
{ 
	ll t;
	cin >> t;
	while(t--)
	{
		memset(SA,0,sizeof(SA));
		memset(RA,0,sizeof(RA));
		memset(tempSA,0,sizeof(tempSA));
		memset(cnt,0,sizeof(cnt));
		memset(LCP,0,sizeof(LCP));
	    string s;
	    cin >> s;
	    s+=(char)('$');
	    // cout<<(ll)'$'<<endl;
	    build_SA(s);
	    build_LCP(s); 
	    ll x=-1;
	    ll sum=0;
	    lp(i,0,s.size())SA[i]--;
	    s.pop_back();
	    // lp(i,0,s.size())
	    // {
	    	// cout<<SA[i]<<" ";
	    // }
 
	    lp(i,0,s.size())
	    {
	    	sum+=lcp[i];
	    	// cout<<lcp[i]<<endl;
	    }
	    ll n=s.size();
	    cout<<(n*n+n)/2-sum<<endl;
	}
}
 