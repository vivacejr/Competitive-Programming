#include<bits/stdc++.h>
using namespace std;

int sto[100][10001];
int ary[100][10001];
int ci[100];
int main()
{
	int n;
	cin >> n;
	int col[n];
	int wt[n];
	int mw;
	cin >> mw;

	int i,j,k;
	for(i=1;i<=n;i++)
	{
		cin >> wt[i] >> col[i] ;
		ary[col[i]][ci[col[i]]]=wt[i]; //stores wts corresponding to ith colour 
		ci[col[i]]++;
	}
	//	for(i=1;i<=10;i++)
	//	{
	//		for(j=0;j<5;j++)
	//		{
	//			cout << ary[i][j] << " " ;
	//		}
	//		cout << endl;

	sto[0][0]=1;
	for(i=1;i<=10;i++)
	{

		for(j=1;j<=mw;j++)
		{
			if(sto[i][j]==0)
			{
				for(k=0;k<ci[i];k++)
				{
					if(j-ary[i][k] >= 0)
					{
						if( sto[i-1][j-ary[i][k] ] == 1)
						{
							sto[i][j]=1;
							break;
						}
					}
				}
			}
		}
	}
	//	for(i=0;i<=10;i++)
	//	{
	//		for(j=0;j<20;j++)
	//		{
	//			cout <<sto[i][j]<< " ";
	//		}
	//		cout << endl;
	//	}

	for(i=mw;i>=0;i--)
	{
		if(sto[10][i]==1)
		{
			cout << i << endl;
			break;
		}
	}

}
