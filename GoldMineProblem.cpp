// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        if(n==1){
            int ans=0;
            for(int ind=0; ind<m; ind++)
                ans += M[0][ind];
            return ans;
        }
        for(int c=m-2; c>=0; c--){
            M[0][c] += max(M[0][c+1], M[1][c+1]);
            M[n-1][c] += max(M[n-1][c+1], M[n-2][c+1]);
            for(int r=1; r<n-1; r++){
                M[r][c] += max(M[r][c+1], max(M[r-1][c+1], M[r+1][c+1]));
            }
        }
        int ans=0;
        for(int ind=0; ind<n; ind++)
            ans = max(ans, M[ind][0]);
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends