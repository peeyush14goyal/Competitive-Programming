//Link to the problem https://codeforces.com/contest/1420/problem/C1 
#include<iostream>
#include<vector>
#define ll long long int
using namespace std;
int maxSum(vector<ll> &a)
{
	ll n = a.size();
	vector<ll> d1(n+1),d2(n+1);
	d1[0]=0;
	d2[0]=0;
	for(ll i=0;i<n;++i)
	{
		d1[i+1]=max(d1[i], d2[i]+a[i]);
		d2[i+1]=max(d2[i], d1[i]-a[i]);
	}
	return max(d1.back(), d2.back());
}
int main()
{
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		ll n, q;
		cin>>n>>q;
		vector<ll> a(n);
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
		}
		cout<<maxSum(a)<<"\n";
	}
}

/*Test Case
3
3 0
1 3 2
2 0
1 2
7 0
1 2 5 4 3 6 7

Output
3
2
9
*/

