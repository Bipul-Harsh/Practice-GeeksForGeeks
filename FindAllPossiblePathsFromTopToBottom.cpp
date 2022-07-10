// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    void makePossibleMoves(int n, int m, vector<vector<int>>grid, vector<vector<int>>&res, int i=0, int j=0, vector<int>path={}){
        if(i == n-1 && j == m-1){
            path.push_back(grid[i][j]);
            res.push_back(path);
            return;
        }
        
        if(i >= n || j >= m)
            return;
        
        path.push_back(grid[i][j]);
        makePossibleMoves(n, m, grid, res, i+1, j, path);
        makePossibleMoves(n, m, grid, res, i, j+1, path);
    }
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        // code here
        vector<vector<int>>res;
        int lvl=0;
        makePossibleMoves(n, m, grid, res);
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends