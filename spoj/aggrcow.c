#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

long long int ary[100005];
int main()
{
	long long int i,n,t,c,sum=0;
	cin >> t;
	while(t--)
	{
		cin >> n >>c ;
		sum=0;
		for(i=0;i<n;i++)
		{
			cin>> ary[i];
		}

		sort(ary,ary+n); //sorted now

		long long int hi=ary[n-1]-ary[0];
		long long int lo=1;
		long long int mid,count,temp=0;
		while(hi>lo)
		{
			//	cout << hi << " " << lo << endl;
			mid=(hi+lo+1)/2;
			temp=0;
			count=1;
			//	cout << mid << endl;
			for(i=0;i<n;i++)
			{

				//cout << ary[i] << " " << ary[temp] <<endl;
				if(ary[i]-ary[temp]>=mid)
				{
					temp=i;
					count ++;
				}
			}
			//	cout << count << endl;
			if(count<c)
			{
				hi=mid-1;
			}
			else
			{
				lo = mid;
			}
		}
		cout << hi<< endl;
	}

}

