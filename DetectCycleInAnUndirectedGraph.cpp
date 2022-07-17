//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    int find_parent(vector<int>g, int v){
        while(g[v] >= 0){
            v = g[v];
        }
        
        return v;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>g(V, -1);
        
        for(int ind=0; ind<V; ind++){
            for(int sind=0; sind<adj[ind].size(); sind++){
                if(adj[ind][sind] < ind)
                    continue;
                int v1 = ind;
                int v2 = adj[ind][sind];
                
                int v1_parent = find_parent(g, v1);
                int v2_parent = find_parent(g, v2);
                // cout<<v1<<' '<<v1_parent<<' '<<v2<<' '<<v2_parent<<endl;
                if(v1_parent == v2_parent)
                    return true;
                
                g[v1_parent]--;
                g[v2_parent] = v1_parent;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends