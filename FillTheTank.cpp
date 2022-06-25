// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {

public:
    long long minimum_amount(vector<vector<int>> &Edges, int num, int start, int *cap) {
        unordered_map<int, vector<int>> e;
        for (int i = 0; i < num - 1; ++i) {
            e[Edges[i][0] - 1].push_back(Edges[i][1] - 1);
            e[Edges[i][1] - 1].push_back(Edges[i][0] - 1);
        }

        vector<bool> visited(num, false);
        visited[start - 1] = true;

        return dfs(e, num, start - 1, cap, visited);
    }

    long long dfs(unordered_map<int, vector<int>> &e, int n, int s, int *cap, vector<bool> &visited) {
        long long maxv = 0, count = 0; 

        for (auto i : e[s]) {
            if (!visited[i]) {
                visited[i] = true;
                long long out = dfs(e, n, i, cap, visited);
                if (out == -1) {
                    return -1;
                }

                maxv = max(maxv, out);
                count++;
            }
        }

        long long result = maxv * count + cap[s];
        if (result > 1e18) {
            return -1;
        }
        return result;
    }
};

// { Driver Code Starts.


int main()
 {
	int T;
	cin>> T;
	while (T--)
	{
	    int num, start;
	    cin>>num>>start;
	    int cap[num];
	    for(int i = 0; i<num; i++)
	        cin>>cap[i];
	    
	    vector<vector<int>> Edges(num-1);
	    for(int i=1;i < num;i++){
	        int u, v; cin >> u >> v;
	        Edges[i-1].push_back(u);
	        Edges[i-1].push_back(v);
	    }
	    
	    
    	Solution obj;
	    long long ans = obj.minimum_amount(Edges, num, start, cap);
	    cout << ans << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends