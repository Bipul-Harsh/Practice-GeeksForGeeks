// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool isValid(int r, int c, int n){
        if(r<0 || r>=n || c<0 || c>=n)
            return false;
        return true;
    }
    bool pathPossible(vector<vector<int>>&grid, int n, vector<vector<bool>>&visited, int r, int c){
        if(grid[r][c] == 2)
             return true;
        
        if(grid[r][c] == 0)
            return false;
        
        if(visited[r][c])
            return false;
        
        visited[r][c] = true;
        
        bool result=false;
        int loc[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        for(int ind=0; ind<8 && !result; ind++){
            if( isValid( r+loc[ind][0], c+loc[ind][1], n) ){
                result = pathPossible(grid, n, visited, r+loc[ind][0], c+loc[ind][1]);
            }
        }
        
        return result;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int si, sj;
        int len = grid.size();
        for(int i=0; i<len; i++)
            for(int j=0; j<len; j++)
                if(grid[i][j] == 1){
                    si = i;
                    sj = j;
                }
        vector<vector<bool>>visited;
        for(int i=0; i<len; i++)
            visited.push_back(vector<bool>(len, false));
        return pathPossible(grid, len, visited, si, sj);
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends