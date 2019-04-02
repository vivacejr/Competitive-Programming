#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front

ll depth[1005][1005];

char S[1005][1005];
deque<pair<ll,ll> > Q;
ll n,m;
ll bfs()
{	
	while(!Q.empty())
	{
		pair<ll,ll> a=Q.front();
		ll x=a.first;
		ll y=a.second;
		Q.pop_front();
		ll d=depth[x][y];
		ll x1=1	,x2=1,y1=1,y2=1;
		
		if(x<n-1&&S[x][y]==S[x+1][y])   x1=0;
		if(x>0&&S[x][y]==S[x-1][y])    x2=0;
		if(y<m-1&&S[x][y]==S[x][y+1])  y1=0;
		if(y>0&&S[x][y]==S[x][y-1])    y2=0;
		
		if(x<n-1&&depth[x+1][y]>d+x1 )
		{
			depth[x+1][y]=d+x1;
			if(!x1)	Q.pf(mp(x+1,y));
			else	Q.pb(mp(x+1,y));
		}
		if(x>0&&depth[x-1][y]>d+x2 )
		{
			depth[x-1][y]=d+x2;
			if(!x2)	Q.pf(mp(x-1,y));
			else	Q.pb(mp(x-1,y));
		}
		if(y<m-1&&depth[x][y+1]>d+y1 )
		{
			depth[x][y+1]=d+y1;
			if(!y1)	Q.pf(mp(x,y+1));
			else	Q.pb(mp(x,y+1));
		}
		
		if(y>0&&depth[x][y-1]>d+y2)
		{
			depth[x][y-1]=d+y2;
			if(!y2)	Q.pf(mp(x,y-1));
			else	Q.pb(mp(x,y-1));
			
		}


	}
}
inline int in(){int N=0;register char c=getchar();while( c < 48 || c > 57 ){c=getchar();}while(c>47 && c< 58){N = (N << 3) + (N << 1) + (c - 48);c=getchar();}return N;}
int main()
{
	ll t;
	t=in();
	while(t--)
	{
		n=in();
		m=in();
		lp(i,0,n)
		{
			scanf("%s",S[i]);
		}
		
		lp(i,0,n)
		{
			lp(j,0,m)
			{
				depth[i][j]=100000000;
			}
		}
		depth[0][0]=0;
		
	Q.pf(mp(0,0));

		bfs();
		printf("%lld\n",depth[n-1][m-1]);

	}
	return 0;
}