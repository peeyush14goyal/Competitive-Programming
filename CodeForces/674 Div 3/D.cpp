#include<iostream>
#include<stdio.h>
#include<vector>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ll n;
	scanf("%lld",&n);
	ll arr[n+1],sum=0, ans=0,curr=1;
	map<int,int> check;
	map<int,int>::iterator it, it2;
	check.insert({0, 1});
	curr++;
	for(ll z=0;z<n;z++)
	{
		scanf("%lld",&arr[z]);
	}
	for(ll i=0;i<n;i++)
	{
		sum += arr[i];
		it = check.find(sum);

		if(it != check.end())
		{
			ans += 1;
			check.clear();
			check.insert({0, 1});
			curr = 2;
			sum = arr[i];
		}
		check.insert({sum, curr});
		curr++;
	}
	printf("%lld", ans);
}
