//Link to the problem https://codeforces.com/contest/1420/problem/A
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long int
int merge(ll arr[],ll temp[],ll left,ll mid,ll right)
{
	int count = 0;
	int i = left;
	int j = mid;
	int k = left;
	while((i <= mid - 1) && (j <= right))
	{
		if(arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
		{
			temp[k++] = arr[j++];
			count = count + (mid - i);
		}
	}
	
	while(i <= mid - 1)
		temp[k++] = arr[i++];
		
	while(j <= right)
		temp[k++] = arr[j++];
		
	for(i=left;i<=right;i++)
		arr[i]=temp[i];
		
	return count;
}

int mergeSort(ll arr[],ll temp[],ll left,ll right)
{
	int mid, count = 0;
	if(right > left)
	{
		mid = (right+left)/2;
		
		count = mergeSort(arr, temp, left, mid);
		count += mergeSort(arr, temp, mid+1,right);
		
		count += merge(arr, temp, left, mid+1, right);
	}
	return count;
}

int countSwaps(ll arr[],ll n)
{
	ll temp[n];
	return mergeSort(arr, temp, 0, n-1);
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int z=1;z<=t;z++)
	{
		ll n;
		scanf("%lld",&n);
		ll arr[n];
		for(ll i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
		}
		ll max_allowed = (n * (n-1) / 2) - 1;
		ll count = countSwaps(arr, n);
		if(max_allowed < count)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
}

/*
Input
3
5
5 3 2 1 4
6
2 2 2 2 2 2
2
2 1


Output
YES
YES
NO
*/
