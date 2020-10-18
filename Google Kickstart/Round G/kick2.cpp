#include<iostream>
#define ll long long int
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		ll n;
		cin>>n;
		ll arr[n+1][n+1];
		ll arr1[2000]={0};
		ll arr2[2000]={0};
		ll max=0;
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<n;j++)
			{
				cin>>arr[i][j];
				if(j-i>=0)
				{
					arr1[j-i]+=arr[i][j];
					if(max<arr1[j-i])
					{
						max=arr1[j-i];
					}
				}
				else if(j-i<0)
				{
					arr2[i-j]+=arr[i][j];
					if(max<arr2[i-j])
					{
						max=arr2[i-j];
					}
				}
			}
		}
		cout<<"Case #"<<z<<": "<<max<<"\n";
	}
}
