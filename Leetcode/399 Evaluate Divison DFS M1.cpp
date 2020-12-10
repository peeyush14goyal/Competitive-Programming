//DFS Approach to 399 Evaluate Division
// M1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//DFS
double find(map<string, map<string, double> >& m, string start, string end, map<string, bool>& vis)
{
	vis[start]=true;
	auto itr = m.find(start);
	auto it = (itr->second).find(end);
	if(it != (itr->second).end())
	{
		return it->second;
	}
	
	for(auto i=(itr->second).begin(); i!=(itr->second).end();i++)
	{
		double val = i->second;
		if(vis[i->first] == false)
		{
			val = val*find(m, i->first, end, vis);
			
			if(val>=0)
			{
				return val;
			}
			vis[i->first] = false;
		}
	}
	return -1;
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
{
	map<string, map<string, double>> m;
	vector<double> d;
	map<string, bool> vis;
	
	//Graph Creation
	for(int i=0;i<equations.size();i++)
	{
		m[equations[i][0]].insert({equations[i][1], values[i]});
		m[equations[i][1]].insert({equations[i][0], double(1/values[i])});
	}
	
	for(auto itm = m.begin(); itm!=m.end(); itm++)
	{
		vis.insert({itm->first, false});
	}
	
	for(int i=0;i<queries.size();i++)
	{
		if(m.find(queries[i][0]) == m.end() || m.find(queries[i][1]) == m.end())
		{
			d.push_back(-1);
		}
		else if(queries[i][0] == queries[i][1])
		{
			d.push_back(1);
		}
		else
		{
			for(auto ix = vis.begin(); ix != vis.end();ix++)
			{
				ix->second = false;
			}
			double val = find(m, queries[i][0], queries[i][1], vis);
			
			d.push_back(val);
		}
	}
	return d;
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
