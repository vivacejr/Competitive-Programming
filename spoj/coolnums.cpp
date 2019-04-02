	#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) (int)(x.size())
#define all(a) a.begin(), a.end()
#define INF numeric_limits<long long>::max()
#define oo  numeric_limits<int> :: max()
#define CLR(s) memset(s, false, sizeof(s))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define DBG(s) cerr << #s << "  == > " << s << endl
#define trace5(a,b,c,d,e) cerr<<#a<<" == > "<<a<<" "<<#b<<" == > "<<b<<" "<<#c<<" == > "<<c<<" "<<#d<<" == > "<<d<<" "<<#e<<" == > "<<e<<endl
typedef long long lld;
typedef vector <int> vi;
typedef pair< int, int > pii;
typedef vector <pii> vpii;
#define MOD 1000000007
#define MA 100
int dp[54][2][18][18][18];
vi a;
int num;
int solve(int index, int free, int t,int s, int n)
{
	if(t > 17 || s > 17 || n > 17) return 0;
 
	//DBG(index);
	if(index == num)
	{
		//DBG(index);
		if(t >= 1 && (t == s) && (s == n))
		 return 1;
		return 0;
	}
	int &ret = dp[index][free][t][s][n];
	if(ret != -1) return ret;
    ret = 0;
    int nfree,nt,ns,nn;
    for(int i = 0; i < 10; i++)
    {
		nfree = free | (i < a[index]);
		nt = t + ( (i == 3) ? 1 : 0); //DBG(nt);
		ns = s + ( (i == 6) ? 1 : 0); //DBG(ns);
		nn = n + ( (i == 9) ? 1 : 0); //DBG(nn);
		if(free)
		{
			ret = ((ret % MOD) + (solve(index+1, nfree, nt, ns, nn)) % MOD) % MOD;
		}
		else
		{
			if( i <= a[index])
			 ret = (ret % MOD +   (solve(index+1, nfree, nt, ns, nn)) % MOD ) % MOD;
		}
 
	}
 
	return (ret% MOD);
}
void convert(char* m)
{
	a.clear();
	int l = strlen(m);
	for(int i = 0; i < l; i++)
	 a.pb( (m[i] - '0'));
	//reverse(all(a));
	num = sz(a);
}
 
void decrement(char* s)
{
	int l = strlen(s)-1;
	int g = s[l] - '0';
	int b = 0;
 
	if(g != 0)
	{
		g--;
		s[l] = g + '0';
	}
	else
	{
		g = 9;
		s[l] = g + '0';
		l--; b = 1;
	}
	while( b != 0 && l >= 0)
	{
		int g = s[l] - '0';
		if( g != 0)
		{
			g --;
			s[l] = g + '0';
			b = 0;
		}
		else
		{
			 g = 9; 
			 s[l] = g + '0';
			 b = 1; l--;
		}
	}
 
 
}
int main()
{
	int te; cin >> te;
	while(te--)
	{
		char x[MA],y[MA]; cin >> x >> y;
		decrement(x);
		//int l = strlen(x);
		/*for(int i = 0; i < l; i++)
		 cout << x[i];
		cout << endl;*/
		convert(x);
		memset(dp,-1,sizeof dp);
		int ans1 = solve(0,0,0,0,0);
 
		convert(y);
		memset(dp,-1,sizeof dp);
		int ans2 = solve(0,0,0,0,0);
		cout << ans2<< endl;
		cout<<ans1<<endl;
	}
	return 0;
}