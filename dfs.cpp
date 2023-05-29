//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Graph
{
	public:
		Graph(int V)
		{
			this->V = V;
			adj.resize(V);
		}

	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
		adj[w].push_back(v);
	}

	void DFS(int s)
	{
		vector<bool> visited(V, false);
		DFSUtil(s, visited);
	}

	void BFS(int s)
	{
		vector<bool> visited(V, false);
		queue<int> q;
		visited[s] = true;
		q.push(s);
		while (!q.empty())
		{
			int v = q.front();
			cout << v << " ";
			q.pop();
			for (int i = 0; i < adj[v].size(); ++i)
			{
				int u = adj[v][i];
				if (!visited[u])
				{
					visited[u] = true;
					q.push(u);
				}
			}
		}
	}

private:
	int V;
	vector<vector<int> > adj;
	void DFSUtil(int v, vector<bool> &visited)
	{
		visited[v] = true;
		cout << v << " ";
		for (int i = 0; i < adj[v].size(); ++i)
		{
			int u = adj[v][i];
			if (!visited[u])
			{
				DFSUtil(u, visited);
			}
		}
	}
};

int main()
{
	int edg = 0, nod = 6, s = 0, e = 0;
	cout << "Enter the no. of nodes in graph :" << endl;
	cin >> nod;
	Graph g(nod);
	cout << "Enter the no. of edges in graph :" << endl;
	cin >> edg;
	for (int i = 0; i < edg; i++)
	{
		cout << "Enter the starting and end virtex of edge no." << i + 1 << " : " << endl;
		cin >> s >> e;
		g.addEdge(s, e);
	}

	cout << "\nDFS traversal starting from vertex 0: \n";
	g.DFS(0);
	cout << endl;
	cout << "\nBFS traversal starting from vertex 0: \n";
	g.BFS(0);
	cout << endl;
	return 0;
}
