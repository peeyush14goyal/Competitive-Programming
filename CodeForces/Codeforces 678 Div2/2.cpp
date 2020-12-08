#include<iostream>
using namespace std;
#define ll long long int
int main()
{
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		ll n,k,day=0,min_count;
		cin>>n>>k;
		ll arr[n+1];
		min_count = n;
		for(ll i=1;i<=n;i++)
		{
			cin>>arr[i];
		}
		for(ll c=1;c<=100;c++)
		{
			day=0;
			for(ll i=1;i<=n;i++)
			{
				if(arr[i]!=c)
				{	
					day++;
					i = i + k - 1;
					
				}
				
			}
			if(min_count>day)
			{
				min_count = day;
			}
		}
		cout<<min_count<<"\n";
	}
}
