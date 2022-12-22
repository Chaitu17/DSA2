#include<bits/stdc++.h>
using namespace std;

void dfsRec(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &arr) {
	arr.push_back(node);
	vis[node] = 1;
	for(auto it : adj[node]) {
		if(!vis[it]) {
			dfsRec(it, adj, vis, arr);
		}
	}
}

vector<int> dfs(int V, vector<vector<int>> &adj) {
	vector<int> arr;
	vector<int> vis(V+1, 0);
	for(int i=1; i<=V; ++i) {
		if(!vis[i]) {
			dfsRec(i, adj, vis, arr);
		}
	}
	return arr;
}

int main() {
	int v,e;
	cin >> v >> e;
	vector<vector<int>> adj(v+1);
	vector<int> ans;
	for(int i=1; i<=e; ++i) {
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ans = dfs(v, adj);
	for(int i=0; i<v; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}


