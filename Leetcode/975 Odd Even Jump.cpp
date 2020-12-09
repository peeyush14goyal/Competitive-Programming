#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/* This comparision signifies to sort first on the basis of first number that is value in our case else if same 
then return lower index*/
bool comp1(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.first < p2.first)
		return 1;
	
	if(p1.first > p2.first)
	{
		return 0;
	}
	
	if(p1.second < p2.second)
	{
		return 1;
	}
	
	return 0;
}

bool comp2(pair<int, int> p1, pair<int, int> p2)
{
	if(p1.first < p2.first)
	{
		return 1;
	}
	if(p1.first > p2.first)
	{
		return 0;
	}
	if(p1.second > p2.second)
	{
		return 1;
	}
	return 0;
}

int oddEvenJumps(vector<int>& arr)
{
	int n = arr.size();
	
	if(!n)
	{
		return 0;
	}
	
	vector<pair<int, int> > v;
	for(int i=0;i<n;i++)
	{
		v.push_back({arr[i], i});
	}
	sort(v.begin(), v.end(), comp1);
	
	cout<<"After sorting 1 we have: \n";
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i].first<<" "<<v[i].second<<"\n";
	}
	cout<<"\n";
	
	int index[2][n];
	
	stack<int> stk;
	
	for(int i=0;i<n;i++)
	{
		while(!stk.empty() && v[i].second > stk.top())
		{
			cout<<"Stack Top is "<<stk.top()<<"\n";
			cout<<"Index 1 is 0. It is less than "<<v[i].second<<"\n\n";
			index[0][stk.top()] = v[i].second;
			cout<<"Top value is popped out "<<stk.top()<<"\n";
			stk.pop();
		}
		cout<<"Value pushed in stack is "<<v[i].second<<"\n\n";
		stk.push(v[i].second);
	}
	cout<<"Assigning remaining elements: \n";
	while(!stk.empty())
	{
		cout<<"Value pushed is "<<n<<" on "<<"[0]["<<stk.top()<<"]\n";
		index[0][stk.top()] = n;
		stk.pop();
	}
	cout<<"Index array is: ";
	for(int i=0;i<n;i++)
	{
		cout<<index[0][i]<<" ";
	}
	sort(v.begin(), v.end(), comp2);
	
	cout<<"After sorting 2 we have: \n";
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i].first<<" "<<v[i].second<<"\n";
	}
	cout<<"\n";
	
	for(int i=n-1;i>=0;i--)
	{
		while(!stk.empty() and v[i].second > stk.top())
		{
			cout<<"Stack Top is "<<stk.top()<<"\n";
			cout<<"Index 1 is 1. It is less than "<<v[i].second<<"\n\n";
			index[1][stk.top()] = v[i].second;
			cout<<"Top value is popped out "<<stk.top()<<"\n";
			stk.pop();
		}
		cout<<"Value pushed in stack is "<<v[i].second<<"\n\n";
		stk.push(v[i].second);
	}
	cout<<"Assigning remaining elements: \n";
	while(!stk.empty())
	{
		cout<<"Value pushed is "<<n<<" on "<<"[1]["<<stk.top()<<"]\n";
		index[1][stk.top()] = n;
		stk.pop();
	}
	
	cout<<"Index array is: ";
	for(int i=0;i<n;i++)
	{
		cout<<index[1][i]<<" ";
	}
	
	int dp[2][n];
	dp[0][n-1] = 1;
	dp[1][n-1] = 1;
	int ans = 1;
	/*Below we have applied Dynamic Programming
	Working of algo
	We have created a 2D array dp[2][n]
	First index has values 0 and 1 => 0 signifies odd and 1 signifies even
	We have to make the jumps alternatively. So we check whether a path exists 
	to reach the end of the array.
	dp[0][n-1] and dp[1][n-1]  = 1 because we are standing on last point so assigned 1.
	Initially using 2 stacks we got the index for each element that it can go to during odd jump and even jump
	So using them we check in backward direction does a path exist or not
	*/
	for(int i=n-2;i>=0;i--)
	{
		int odd = index[0][i];
		int even = index[1][i];
		if(odd != n)
		{
			dp[0][i] = dp[1][odd];
		}
		else
		{
			dp[0][i] = 0;
		}
		if(even != n)
		{
			dp[1][i] = dp[0][even];
		}
		else
		{
			dp[1][i] = 0;
		}
		
		if(dp[0][i])
		{
			ans++;
		}
	}
	cout<<"Odd dp is: ";
	for(int i=0;i<n;i++)
	{
		cout<<dp[0][i]<<" ";	
	}
	cout<<"Even dp is: ";
	for(int i=0;i<n;i++)
	{
		cout<<dp[1][i]<<" ";	
	}	
	return ans;
}
int main()
{
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(13);
	vec.push_back(12);
	vec.push_back(14);
	vec.push_back(15);
	cout<<"We have vector: ";
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i]<<" ";
	}
	cout<<"\n";
	cout<<oddEvenJumps(vec);
}
