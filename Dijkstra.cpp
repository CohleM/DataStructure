#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define RFOR(a,n) for(int i = a;  i< n; i++)
#define FOR(n) RFOR(0,n)
using namespace std;

int main() {


	//keep in mind we wont use visited in this , because this works for weighted graph and one node's value 
	//can be decreased later so , we don't use visited . It we use it , it just becomes like BFS.

	int vertices = 9;
	//stores the edges and weight
	//adj = {edges,weight};
	vector<pii> adj[vertices];
	//min_heap
	priority_queue<pii,vector<pii> , greater<pii> > q;
	//final distance array . It contains the distance from source to all other vertices;
	int dist[vertices];
	bool vis[vertices] = {0};


	FOR(14)
	{
		int u,v,w; cin >>u>>v>>w;
		adj[u].pb(mp(v,w));
		adj[v].pb(mp(u,w));
	}




	//src = source vertex
	int src = 0;
	vis[src] = true;
	q.push(mp(0,src)); // 0 is the initial weight of source vertex
	dist[src] = 0;
	//initializing all the other distances INT_MAX
	RFOR(1,vertices)
	{
		q.push(mp(INT_MAX,i));
		dist[i] = INT_MAX;
	}

	while(!q.empty())
	{
		//wu =  working vertex;
		pii wu = q.top();
		int u = wu.second;
		q.pop();
		//int weight = wu.first;

		for(auto i = adj[u].begin(); i != adj[u].end(); i++)
		{
			int v = (*i).first;
			int iweight = (*i).second;
     //        cout <<u <<  "  "<<v<<"  " << iweight<<"  \n";

			if( dist[v] > dist[u] + iweight )
			{
				dist[v] = dist[u] + iweight;
				vis[v] = true;
				q.push(mp(dist[v], v));
			}
		}
	}

	for(auto a : dist) cout <<a <<"\n";

	return 0;
}
