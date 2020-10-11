#include<iostream>
#include<string.h>
#include<math.h>
#define ll long long int
using namespace std;
int main()
{
	string str1, str2;
	ll ans=0;
	cin>>str1;
	cin>>str2;
	ans = abs(str1.length()-str2.length());
	for(ll i=0;i<str1.length()&&i<str2.length();i++)
	{
		if(str1[i]!=str2[i])
		{
			ans++;
		}
	}
	printf("%lld",ans);
}
