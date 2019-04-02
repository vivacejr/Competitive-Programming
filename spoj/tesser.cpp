#include<bits/stdc++.h>
using namespace std;
int lps[100005];
int flag;


int H(char str[],int n)
{
	int len=0;
	lps[0]=0;
	int i=1;
	while(i<n)
	{
		if(str[i]==str[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len)
			{
				len=lps[len-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
}

int find(char str[],char s2[])
{
	
	int i=0;
	int j=0;
	//cerr << i << " "<<j<<endl;
	int n=strlen(str);
	int m=strlen(s2);
	while(i<n)
	{
		
		if(s2[j]==str[i])
		{
			i++;
			j++;
		}
		if(j==m)
		{
			cout << "YES"<<endl;
			flag=1;
			break;
		}
		else if(i<n&&s2[j]!=str[i])
		{
			if(j)
			{
				j=lps[j-1];
			}
			else
			{
				i++;
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int ary[n];
		char str[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> ary[i];

		}
		for (int i = 0; i < n-1; ++i)
		{
			if(ary[i+1]>ary[i])
			{
				str[i]='G';
			}
			else if(ary[i+1]<ary[i])
			{
				str[i]='L';
			}
			else
			{
				str[i]='E';
			}
		}
		char s2[n];
		cin >> s2;
		
		H(s2,strlen(s2));

		flag=0;
		find(str,s2);
		if(!flag)
		{
			cout <<"NO"<<endl;
		}

	}	
}