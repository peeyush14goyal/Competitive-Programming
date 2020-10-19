/* Max Product of 4 numbers in the array*/
#include<iostream>
#include<math.h>
#define ll long long int
using namespace std;
ll maxProduct(ll arr[],ll n,ll max_val, ll num)
{
	if(n==-1||num==0)
	{
		return max_val;
	}
	
	return max(maxProduct(arr, n-1, max_val*arr[n], num-1), maxProduct(arr, n-1, max_val, num));
}
int main()
{
	ll n;
	cout<<"Enter n: ";
	cin>>n;
	ll arr[n+1];
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"Max Product is "<<maxProduct(arr, n-1, 1, 4);
}
