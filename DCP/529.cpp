#include<iostream>
#include<vector>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<bits/stdc++.h>
#include<string.h>
#define ll long long int
using namespace std;
int pallindrome(string str,ll start,ll end)
{
	ll len = end - start + 1;
	ll i,j;
	for(i=start,j=end;i<=start+len/2&&j>=start+len/2;i++, j--)
	{
		if(str[i]!=str[j])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		string str;
		cin>>str;
		map<char, vector<int> > stringMap;
		map<char, vector<int> >::iterator itr, itr2;
		vector<int> temp2;
		int tempCheck = 0;
		for(ll i=0;i<str.length();i++)
		{
			itr = stringMap.find(str[i]);
			if(itr == stringMap.end())
			{
				vector<int> temp;
				temp.push_back(i);
				stringMap.insert({str[i], temp});	
			}
			else{
				itr->second.push_back(i);
			}	
		}

		for(ll i=0;i<str.length();i++)
		{
			itr = stringMap.find(str[i]);
			vector<int>::iterator remove;
			
			while(itr->second.front() < i && !itr->second.empty())
			{
				remove = itr->second.begin();
				itr->second.erase(remove);
			}
			ll y=-1;
			tempCheck=0;
			while(!itr->second.empty()&&tempCheck==0)
			{
				y++;
				ll last_value = itr->second.back();
				tempCheck = pallindrome(str, itr->second.front(), itr->second.back());
				
				if(tempCheck==1)
				{
					for(ll p=itr->second.front();p<=last_value;p++)
					{
						cout<<str[p];	
					}
					cout<<"\n";
					i = last_value;	
				}
				itr->second.resize(itr->second.size()-1);	
			}
		}
	}
}
