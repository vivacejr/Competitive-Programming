#include<bits/stdc++.h>
using namespace std;
typedef struct trie{
	struct trie * sub[26];
	bool mark;
	long long ll key;
} trie;
long long ll c=1;

long long ll ary[100005];
long long ll size[100005];
trie* getNode()
{
	trie * node=new trie;
	for (long long ll i = 0; i < 26; ++i)
	{
		node->sub[i]=NULL;
	}
	node->mark=false;
	node->key=0;
	return node;

}

void insert(trie* head,char str[])
{
	long long ll n=strlen(str);
	for (long long ll i = 0; i < n; ++i)
	{
		if(!head->sub[str[i]-'a'])
		{
			head->sub[str[i]-'a']=getNode();
		}		head=head->sub[str[i]-'a'];
	}
	head->mark=true;
	head->key=c++;
}

long long ll present(trie* head,char str[])
{
	long long ll n=strlen(str);
	for (long long ll i = 0; i < n; ++i)
	{
		if(!head->sub[str[i]-'a'])
		{
			return false;
		}
		head=head->sub[str[i]-'a'];
	}
	
	if(head->mark&&head!=NULL)	//........
		return head->key;
	else
		return false;
}

void long long llialize()
{
	for (long long ll i = 0; i < 100005; ++i)
	{
		ary[i]=i;
		size[i]=1;
	}
}
long long ll root(long long ll k)
{
	k;
	while(ary[k]!=k)
	{
		ary[k]=ary[ary[k]];
		k=ary[k];
	}
	return k;
}

long long ll un(long long ll k1,long long ll k2)
{
	long long ll rA=root(k1);
	long long ll rB=root(k2);
	if(size[rA]>size[rB])
	{
		ary[rB]=rA;
		size[rA]+=size[rB];
	}
	else
	{
		ary[rA]=rB;
		size[rB]+=size[rA];
	}
}



long long ll main()
{
	long long ll t;
	cin >>t;
	while(t--)
	{
		long long ll n;
		cin >> n;
		char s1[22];
		char s2[22];
		long long ll k1,k2;
		trie *head=getNode();
		c=1;
		long long llialize();
		for (long long ll i = 0; i < n; ++i)
		{
			cin >> s1;
			
			long long ll x='a'-'A';
			
			s1[0]=s1[0]+x;
			if(!present(head,s1))
			{
				insert(head,s1);
			}
			k1=present(head,s1);
			
			cin >> s2;
			s2[0]=s2[0]+x;	

			if(!present(head,s2))
			{
				insert(head,s2);
			}
			k2=present(head,s2);
			
			if(root(k1)!=root(k2))
			{
				un(k1,k2);
				cout << size[root(k1)]<<endl;	
			}
			else
			{
				cout << size[root(k1)]<<endl;
			}
		}
	}
}	