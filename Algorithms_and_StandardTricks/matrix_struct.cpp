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

ll expo(ll b,ll e,ll m)
{
	ll a=1;
    while(e !=0 )
    {
        if((e&1) == 1) 
            a= (a*b)%m;
        b=(b*b)%m; e>>= 1;
	}
	return a%m;
}
const ll N = 		205;
struct matrix{
    ld B[N][N], n;
    matrix(){n = N; memset(B,0,sizeof B);}
    matrix(int _n){
        n = _n; memset(B, 0, sizeof B);
    }
    void iden(){for(int i = 0; i < n; i++) B[i][i] = 1;}
    void operator += (matrix M){
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) B[i][j] = add(B[i][j], M.B[i][j]);
    }
    void operator -= (matrix M){
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) B[i][j] = sub(B[i][j], M.B[i][j]);
    }
    void operator *= (ld b){
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) B[i][j] = mul(b, B[i][j]);
    }
    matrix operator - (matrix M){
        matrix ret = (*this); ret -= M; return ret;
    }
    matrix operator + (matrix M){
        matrix ret = (*this); ret += M; return ret;
    }   
    matrix operator * (matrix M){
        matrix ret = matrix(n); memset(ret.B, 0, sizeof ret.B);
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < n;j++)
                for(int k = 0; k < n; k++){
                    ret.B[i][j] = add(ret.B[i][j], mul(B[i][k], M.B[k][j]));
                }
        return ret;
    }
    matrix operator *= (matrix M){ *this = ((*this) * M);}
    matrix operator * (int b){
        matrix ret  = (*this); ret *= b; return ret;
    }
    vector<double> multiply(const vector<double> & v) const{
    	vector<double> ret(n);
    	for(int i = 0; i < n; i++)
    		for(int j = 0; j < n; j++){
    			ret[i] += B[i][j] * v[j];
    		}
    	return ret;
    }
};




int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	matrix T=matrix(n);    
	return 0;
}