#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define vll vector<ll> 
ll expo(ll base, ll exponent, ll mod) {
    ll ans = 1;
    while(exponent !=0 ) {
        if((exponent&1) == 1) {
            ans = (ans*base)%mod ;
        }
        base = (base*base)%mod;
        exponent>>= 1;
    }
    return ans%mod;
}


typedef struct trie{
	struct trie* sub[10];
	bool mark;
}trie;

trie *getNode()
{
	trie *node=new trie;
	node->mark=0;
	for (int i = 0; i < 10; ++i)
	{
		node->sub[i]=NULL;
	}
	return node;
}

int insert(trie *root,char str[])
{
	trie *node=root;
	for (int i = 0; i < strlen(str); ++i)
	{
		if(node->sub[str[i]-'0']==NULL)
		{
			node->sub[str[i]-'0']=getNode();
		}
		node=node->sub[str[i]-'0'];
	}
	node->mark=true;

}

bool search(trie *root,char str[])
{
	trie *node=root;

	for (int i = 0; i <strlen(str); ++i)
	{
		if(!node->sub[str[i]-'0'])
		{
			return false;
		}
		else
		{
			if(node->mark==true) return false;
			node=node->sub[str[i]-'0'];
			
		}
	}
	return (node !=NULL && node->mark);
}

int main()
{
	ll t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		char str[10005][15];
		trie *root=getNode();
		for (int i = 0; i < n; ++i)
		{
			cin >> str[i];
			insert(root,str[i]);
		}
		ll flag=0;
		for (int i = 0; i < n; ++i)
		{
			if(!search(root,str[i]))
			{
				flag=1;
				cout<<"NO"<<endl;
				break;
			}
		}
		if(flag==0) cout<<"YES"<<endl;
	}
}