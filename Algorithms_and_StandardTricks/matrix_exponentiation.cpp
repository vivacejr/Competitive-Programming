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
const ll N=1e5+5,mod=1e9+7;
ll K;
typedef vector<vector<ll> > matrix;

matrix mul(matrix A, matrix B)
{
    matrix C(K, vector<ll>(K));
    lp(i,0, K) lp(j,0, K) lp(k,0, K)
		C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
    return C;
}

matrix pow(matrix A, ll p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
	
	return 0;
}