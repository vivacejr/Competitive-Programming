#include<bits/stdc++.h>x`
int main()
{
	while(1){
		cin >> str;
		int flag=1;
		if(str[0]=='0')
		{
			break;
		}

		for(int i=0;i<strlen(str)-1;i++)
		{
			if( str[i+1]=='0' && (str[i]=='0' || str[i]>50))
			{
				cout << "0" << endl;
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			for(int i=0;i<5005;i++)
			{
				ary[i]=0;
			}
			long long int ans=dp(strlen(str),0);
			cout << ans << endl;
			/*	for(long long int i=0;i<strlen(str);i++)
				{
				cout << ary[i] << " ";
				}
				cout << endl;*/
		}
	}
}
