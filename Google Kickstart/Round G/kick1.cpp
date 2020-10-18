#include<iostream>
#include<string>

using namespace std;
#define ll long long int
int main()
{
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		string str;
		ll kick=0;
		ll ans = 0;
		cin>>str;
		for(ll i=0;i<str.length();i++)
		{
			if(str.substr(i, 4)=="KICK")
			{
				kick++;
				i+=2;
			}
			else if(str.substr(i, 5)=="START")
			{
				ans+=kick;
				i+=4;
			}
		}
		cout<<"Case #"<<z<<": "<<ans<<"\n";
	}
}
