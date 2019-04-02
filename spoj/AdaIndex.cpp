#include<bits/stdc++.h>
using namespace std ;

typedef struct trie{
	struct trie* sub[26];
	int prefix;
	//bool mark;//nt needed
} trie;

trie * getN()
{
	trie * node= new trie;
	for (int i = 0; i < 26; ++i)
	{
		node->sub[i]=NULL;
	}
	node->prefix=0;
	return node;
}

int insert(trie *node,string &str)
{
	int n=str.size();
	for (int i = 0; i < n; ++i)
	{
		
		if(node->sub[str[i]-'a']==NULL)
		{
			node->sub[str[i]-'a']=getN();
		}
			node = node->sub[str[i]-'a'];
			node->prefix++;
	}
}

int search(trie *node,string &ques)
{
	int n=ques.size();
	for (int i = 0; i < n; ++i)
	{
		if (node->sub[ques[i]-'a']==NULL)
		{
			return 0;
		}
		node=node->sub[ques[i]-'a'];
	}
	return node->prefix;
}
int main()
{
	int n,q;
	cin >> n >> q;
	string str[n];
	trie * root =getN();
		
	for (int i = 0; i < n; ++i)
	{
		cin >> str[i];
		insert(root,str[i]);
	}
	string ques[q];
	for (int i = 0; i < q; ++i)
	{
		cin >> ques[i];
		cout << search(root,ques[i]) <<endl		;
	}
}
