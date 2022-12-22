#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(int V, vector<vector<int>> &adj) {
    vector<int> vis(V+1, 0);
    vector<int> ans;
    for(int i=1; i<=V; ++i) {
        if(!vis[i]) {
            queue<int> gq;
            gq.push(i);
            vis[i] = 1;
            while(!gq.empty()) {
                int front = gq.front();
                gq.pop();
                ans.push_back(front);
                for(auto it : adj[front]) {
                    if(!vis[it]) {
                        gq.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    return ans;
}
 
int main() {
    int v,e;
    cin >> v >> e;
    vector<vector<int>> adj(v+1);
    for(int i=0; i<e; ++i) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> ans = bfs(v, adj);
    for(int i=0; i<v; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}


