//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        // code here
        int r_start = 0, r_end = R-1;
        int c_start = 0, c_end = C-1;
        
        vector<int>traverse;
        
        while(r_start <= r_end && c_start <= c_end){
            int rind, cind;
            
            // left to right
            for(cind=c_start; cind <= c_end; cind++){
                traverse.push_back(a[r_start][cind]);
            }
            
            // top to bottom
            for(rind=r_start+1; rind <= r_end; rind++){
                traverse.push_back(a[rind][c_end]);
            }
            
            // right to left
            if(r_start != r_end)
            for(cind=c_end-1; cind >= c_start; cind--){
                traverse.push_back(a[r_end][cind]);
            }
            
            // bottom to top
            if(c_start != c_end)
            for(rind=r_end-1; rind > r_start; rind--){
                traverse.push_back(a[rind][c_start]);
            }
            
            ++r_start;
            ++c_start;
            --r_end;
            --c_end;
        }
        
        reverse(traverse.begin(), traverse.end());
        return traverse;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends