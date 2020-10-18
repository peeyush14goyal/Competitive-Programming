#include<iostream>
#include<math.h>
#define ll long long int
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		ll n,w;
		cin>>w>>n;
		ll arr[w+1],min_val,max_val=0,avg=0,sum=0,min_ans;
		for(ll i=0;i<w;i++)
		{
			cin>>arr[i];
			sum+=arr[i];
			if(i==0)
			{
				min_val=arr[i];
			}
			else if(min_val>arr[i])
			{
				min_val=arr[i];
			}
			if(max_val<arr[i])
			{
				max_val=arr[i];
			}
		}
		//avg= round(sum/w);
		
		//ll r_count = 0, l_count = 0,start=1,end=n;

		ll foward, backward;
		min_ans = n*w;
		for(ll j=0;j<w;j++)
		{
			ll avg_moves=0;
			for(ll i=0;i<w;i++)
			{
				foward = abs(arr[j] - arr[i]);
				backward = n - abs(arr[j] - arr[i]);
				avg_moves += abs(min(backward, foward));
			}
			if(min_ans > avg_moves)
			{
				min_ans = avg_moves;
			}
		}
		cout<<"Case #"<<z<<": "<<min_ans<<"\n";
	}
}
