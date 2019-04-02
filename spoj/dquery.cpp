// 1 based indexing

#include<bits/stdc++.h>
using namespace std;

int n;
int z;
bool cmp0(const vector <int> & a,const vector < int> & b)
{
	if(a[1]/z==b[1]/z)
	{
		return a[2]<b[2];
	}
	else
	{
		return a[1]<b[1];
	}
}



bool cmp3(const vector <int> & a,const vector < int> & b)
{
	return a[0]<b[0];
}

int main()
{
	cin >> n;
	int ary[n+1];
	for (int i = 1; i <= n; ++i) scanf("%d",&ary[i]);

	int q;
	cin >> q;
	vector<vector<int> > ques(q);

	for (int i = 0; i < q; ++i)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		ques[i].push_back(i);
		ques[i].push_back(l);
		ques[i].push_back(r);
	}
	z=sqrt(n);
	sort(ques.begin(),ques.end(),cmp0);

	int a=sqrt(n);

	int x=0,y=0;
	
	int freq[1000001];
	for (int i = 0; i < 1000001; ++i) freq[i]=0;
	
	int left=ques[0][1];
	int c =1;
	int right=ques[0][1];
	freq[ary[right]]++;

	for (int i = 0; i < q; ++i)
	{
		if(ques[i][1]>left)
		{
			while(ques[i][1]!=left)
			{
				freq[ary[left]]--;
				if(freq[ary[left]]==0)
				{
					c--;
				}
				left++;
				}
			}
		else if(ques[i][1]<left)
		{
			while(ques[i][1]!=left)
			{
				left--;
				freq[ary[left]]++;
				if(freq[ary[left]]==1)
				{
					c++;
				}
			}
		}

		if(ques[i][2]>right)
		{
			while(ques[i][2]!=right)
			{
				right++;
				freq[ary[right]]++;
				if(freq[ary[right]]==1)
				{
					c++;
				}
			}
		}
		
		if(ques[i][2]<right)
		{
			while(ques[i][2]!=right)
			{
				freq[ary[right]]--;
				if(freq[ary[right]]==0)
				{
					c--;
				}
				right--;
			}
				}

		ques[i].push_back(c);
		
	}
		sort(ques.begin(),ques.end(),cmp3);
		for (int i = 0; i < q; ++i)
		{
			printf("%d\n",ques[i][3]);			
		}
	}