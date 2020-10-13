#include<iostream>
#include<math.h>
#define ll long long int
using namespace std;
int main()
{
	ll n;
	scanf("%lld",&n);
	ll r1, s1, p1, r2, s2, p2,arr[3],min_val=0, max_val=0;
	cin>>r1>>s1>>p1>>r2>>s2>>p2;
	arr[0] = r1-r2-p2;
	arr[0] = min(arr[0], s2);
	arr[1] = s1-s2-r2;
	arr[1] = min(arr[1], p2);
	arr[2] = p1-p2-s2;
	arr[2] = min(arr[2], r2);
	for(int i=0;i<3;i++)
	{
		if(arr[i]>0)
		min_val += arr[i];
	}
	max_val = min(r1, s2) + min(s1, p2) + min(p1, r2);
	cout<<min_val<<" "<<max_val;
}
