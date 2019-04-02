#include<bits/stdc++.h>
using namespace std;

int build(int ary[],int sto[],int n)
{
	int a=sqrt(n);

	for (int i = 0; i < n; ++i)
	{
		sto[i/a]+=ary[i];
	}

	for (int i = 0; i < ceil(sqrt(n)); ++i)
	{
		cout << sto[i]<<" ";
	}
	cout << endl;
	
}


int main()
{
	int n;
	cin >> n;
	int ary[n];
	for (int i = 0; i < n; ++i) cin >> ary[i];
	
	int a=sqrt(n);
	int sto[a+1];
	for (int i = 0; i < a+1; ++i)sto[i]=0;
	build(ary,sto,n);

	int q;
	cin >> q;
	while(q--)
	{
		int type;
		cin >> type;
		if(type==1) //update
		{
			int ind,val;
			cin >> ind >> val;
			sto[ind/a]+=(val-ary[ind]);
			ary[ind]=val;
		}
		else
		{
			int l,r;
			cin >> l >> r;
			int ans=0;
			for (int i = l; i <=r;)
			{
				if(i%a==0&&r-i>=a)
				{
					ans+=sto[i/a];
					i+=a;
				}
				else
				{
					ans+=ary[i];
					i++;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;

}