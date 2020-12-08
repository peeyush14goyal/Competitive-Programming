/*
You are given an array A of size N. Your task is to find the minimum number of operations needed to convert the given array to 'Palindromic Array'.
Palindromic Array:
[23,15,23] is a ‘Palindromic Array’ but [2,0,1] is not.
The only allowed operation is that you can merge two adjacent elements in the array and replace them with their sum.

Input:
The first line of input contains an integer T denoting the number of test cases.The first line of each test case is N, where N is the size of array.The second line of each test case contains N space separated integers which is the input for the array.

Output:
Output the minimum number of operations required to make the given array a palindromic array.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= A[] <= 100
*/
#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		int i=0, j=n-1,sum=0,op=0;
		while(i<j)
		{
			if(arr[i]==arr[j])
			{
				i++;
				j--;
			}
			else if(arr[i]>arr[j])
			{
				j--;
				arr[j]+=arr[j+1];
				arr[j+1]=0;
				op++;
			}
			else if(arr[i]<arr[j])
			{
				i++;
				arr[i]+=arr[i-1];
				arr[i-1]=0;
				op++;
			}
		}
		cout<<op<<"\n";
	}
}
