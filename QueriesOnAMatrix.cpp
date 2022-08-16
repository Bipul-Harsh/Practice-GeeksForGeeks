//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {
        // Code here
        vector<vector<int>>ans(n, vector<int>(n, 0));
        
        for(int i=0; i<Queries.size(); i++){
            int x1 = Queries[i][0];
            int y1 = Queries[i][1];
            int x2 = Queries[i][2];
            int y2 = Queries[i][3];
            
            for(int r=x1; r<=x2; r++){
                ans[r][y1]++;
                
                if(y2+1 < n)
                    ans[r][y2+1]--;
            }
            
        }
        for(int r=0; r<n; r++){
            for(int c=1; c<n; c++){
                ans[r][c] += ans[r][c-1];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;
        vector<vector<int>> Queries;
        for (int i = 0; i < q; i++) {
            vector<int> cur(4);
            for (int j = 0; j < 4; j++) cin >> cur[j];
            Queries.push_back(cur);
        }
        Solution obj;
        vector<vector<int>> ans = obj.solveQueries(n, Queries);
        for (auto i : ans) {
            for (auto j : i) cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends
