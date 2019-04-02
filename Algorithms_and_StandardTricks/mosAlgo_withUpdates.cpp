// 1 based indexing
// Author - Vivace_jr 

#include<bits/stdc++.h>
using namespace std;

int n;
int z;
bool cmp0(const vector <int> & a,const vector < int> & b)
{
	if(a[1]/z==b[1]/z)
	{
		if(a[2]==b[2])
		{
			return a[3]<b[3];
		}
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
	vector<vector<int> > upd(q);
	int t=0;	//timestamp
	int j=0;
	for (int i = 0; i < q; ++i)
	{
		int type;
		cin >> type
		if(type==1)
		{
			int ind,val;
			cin >> ind >> val;
			upd[t].push_back(ind);
			upd[t].push_back(val);
			t++;
		}
		else
		{
			int l,r;
			scanf("%d%d",&l,&r);
			ques[j].push_back(i);
			ques[j].push_back(l);
			ques[j].push_back(r);
			ques[j].push_back(t);
			j++;
		}
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
	int time=0;
	for (int i = 0; i < j
		; ++i)
	{
		if(ques[i][3]>time)
		{
			while(ques[i][3]!=time)
			{
				time++;
				if(left<=upd[time][0]&&right>=upd[time][0])
				{
					freq[ ary[ upd[time][0] ] ]--;
					freq[upd[time][1]]++;
				}
				//jab vaapis ana ho uske liye jugaad
				int temp=ary[ upd[time][0] ];
				ary[upd[time][0]]=upd[time][1];
				upd[time][1]=temp;
			}
		}
		else if(ques[i][3]<time)
		{
			while(ques[i][3]!=time)
			{
				if(left<=upd[time][0]&&right>=upd[time][0])
				{
					freq[ ary[ upd[time][0] ] ]--;
					freq[upd[time][1]]++;
				}

				int temp=ary[ upd[time][0] ];
				ary[upd[time][0]]=upd[time][1];
				upd[time][1]=temp;
				time--;
			}
		}

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