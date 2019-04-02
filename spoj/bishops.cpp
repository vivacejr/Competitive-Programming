#include <bits/stdc++.h>
using namespace std;
int main()
{
	char str[105];
	while(cin >>str)
	{
		int flag=0;
		int n=strlen(str);
		char s2[105];
		strcpy(s2,str);
		if(strlen(str)==1&&str[0]=='1')
		{
			cout << "1" << endl;
			continue;
		}
		
		if(str[n-1]=='1')
		{
			str[n-1]='9';
			for (int i = n-2; i >=0 ; i--)
			{
				if(str[i]-'0'>0)
				{
					str[i]=str[i]-1;
					for(i=i+1;i<n-1;i++)
					{
						str[i]='9';
					}
				
				break;
			}
			}
		}
		else
		{
			for (int i = n-1; i >=0 ; i--)
			{
				
				if(str[i]-'0'>0)
				{
					if(i==n-1)
					{
						str[i]=str[i]-2;
						flag=1;
					}
					else
					{
						str[i]=str[i]-1;
					}
					for(int j=i+1;j<n-1;j++)
						{
							str[j]='9';
						

						}
						if(!flag)
						str[n-1]='8';
						
					break;
				}
			}
		}
		//cout << str << endl;
		int c=0;
		for(int i=n-1;i>=0;i--)
		{
			int a=str[i]-'0';
			int b=s2[i]-'0';
			int sum=a+b+c;
			str[i]=sum%10+'0';
			c=sum/10;
		}
		if(c)
		{
			cout<<c<<str<<endl;
		}
		else
		{
			cout << str<<endl;
		}
	}	
} 