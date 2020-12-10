//BFS 399 Leetcode Evaluate Divison

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<double> calcEquation(vector<vector<string> >& equations, vector<double>& values, vector<vector<string> >& queries)
{
	// to take care of duplicate values
	map<pair<string, string>, double> m;
	// to implement BFS
	queue<pair<pair<string, string>, double> > q;
	// to store query results
	vector<double> res;
	for(int i=0;i<equations.size();++i)
	{
		m.insert({{equations[i][0], equations[i][0]}, 1.0});
		m.insert({{equations[i][1], equations[i][1]}, 1.0});
		m.insert({{equations[i][0], equations[i][1]}, values[i]});
		m.insert({{equations[i][1], equations[i][0]}, 1.0/values[i]});
		q.push({{equations[i][0], equations[i][1]}, values[i]});
		q.push({{equations[i][1], equations[i][0]}, 1.0/values[i]});
	}
	
	//BFS
	while(!q.empty())
	{
		auto front = q.front();	
		string n1 = q.front().first.first;
		string d1 = q.front().first.second;
		double v1 = q.front().second;
		
		for(int i=0;i<equations.size();++i)
		{
			string n2 = equations[i][0];
			string d2 = equations[i][1];
			double v2 = values[i];
			double v3 = 1.0/values[i];
			if(n1 == d2 && n2!=d1)
			{
				if(m.find({n2, d1})==m.end())
				{
					m.insert({{n2, d1}, v1*v2});
					q.push({{n2, d1}, v1*v2});
				}
				if(m.find({d1, n2})==m.end())
				{
					m.insert({{d1, n2}, 1.0/(v1*v2)});
					q.push({{d1, n2}, 1.0/(v1*v2)});
				}
			}
			else if(n2==d1 && n1!=d2)
			{
				if(m.find({n1, d2}) == m.end())
				{
					m.insert({{n1, d2}, v1*v2});
					q.push({{n1, d2}, v1*v2});
				}
				if(m.find({d2, n1})==m.end())
				{
					m.insert({{d2, n1}, 1.0/(v1*v2)});
					q.push({{d2, n1}, 1.0/(v1*v2)});
				}
			}
			if(n1==n2 && d1!=d2)
			{
				if(m.find({d2, d1}) == m.end())
				{
					m.insert({{d2, d1}, v1*v3});
					q.push({{d2, d1}, v1*v3});
				}
				if(m.find({d1, d2})==m.end())
				{
					m.insert({{d1, d2}, 1.0/(v1*v3)});
					q.push({{d1, d2}, 1.0/(v1*v3)});
				}
			}
			else if(n1!=n2 && d1==d2)
			{
				if(m.find({n1, n2})==m.end())
				{
					m.insert({{n1, n2}, v1*v3});
					q.push({{n1, n2}, v1*v3});
				}
				
				if(m.find({n2, n1})==m.end())
				{
					m.insert({{n2, n1}, 1.0/(v1*v3)});
					q.push({{n2, n1}, 1.0/(v1*v3)});
				}
			}
		}
		q.pop();
	}
	
	// Query Results
	for(int i=0;i<queries.size();++i)
	{
		if(m.find({queries[i][0], queries[i][1]})!=m.end())
		{
			res.push_back(m[{queries[i][0], queries[i][1]}]);
		}
		else
		{
			res.push_back(-1.0);
		}
	}
	return res;
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
