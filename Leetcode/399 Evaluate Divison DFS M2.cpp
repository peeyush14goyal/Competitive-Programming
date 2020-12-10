//DFS Approach 2 to 399 Evaluate Division
// M2
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

double dfs(unordered_map<string, vector<pair<string, double>>>& adj, string src, string target, 
unordered_map<string, bool>& visited, double ans)
{
	visited[src] = true;
	for(int i=0;i<adj[src].size(); i++)
	{
		string next = adj[src][i].first;
		if(next.compare(target)==0)
		{
			return ans*adj[src][i].second;
		}
		if(!visited[next])
		{
			double check = dfs(adj, next, target, visited, ans*adj[src][i].second);
			if(check != -1)
			{
				return check;
			}
		}
	}
	return -1;
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
{
	unordered_map<string, vector<pair<string, double>>> adj;
	int n = values.size();
	for(int i=0;i<n;i++)
	{
		adj[equations[i][0]].push_back({equations[i][1], values[i]});
		adj[equations[i][1]].push_back({equations[i][0], 1/values[i]});
	}
	vector<double> result;
	for(int i=0;i<queries.size();i++)
	{
		if(adj.count(queries[i][0]) == 0 || adj.count(queries[i][1]) == 0)
		{
			result.push_back(-1);
		}
		else
		{
			unordered_map<string, bool> visited;
			double ans = dfs(adj, queries[i][0], queries[i][1], visited, 1);
			result.push_back(ans);
		}
	}
	return result;
}

int main()
{
	vector<vector<string> > equations;
	vector<string> st;
	st.push_back("a");
	st.push_back("b");
	equations.push_back(st);
	st.clear();
	
	st.push_back("b");
	st.push_back("c");
	equations.push_back(st);
	st.clear();
	
	st.push_back("bc");
	st.push_back("cd");
	equations.push_back(st);
	st.clear();
	
	
	vector<vector<string> > queries;
	st.push_back("a");
	st.push_back("c");
	queries.push_back(st);
	st.clear();
	
	st.push_back("c");
	st.push_back("b");
	queries.push_back(st);
	st.clear();
	
	st.push_back("bc");
	st.push_back("cd");
	queries.push_back(st);
	st.clear();
	
	st.push_back("cd");
	st.push_back("bc");
	queries.push_back(st);
	st.clear();
	
	vector<double> values;
	values.push_back(1.5);
	values.push_back(2.5);
	values.push_back(5.0);
	
	vector<double> res ;
	res = calcEquation(equations, values, queries);
	cout<<"Result is: ";
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<" ";
	}
}
