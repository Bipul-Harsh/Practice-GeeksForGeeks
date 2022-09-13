//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            //  code here
            vector<int> row={0}, col={0};
            
            for(auto cord:enemy){
                row.push_back(cord[0]);
                col.push_back(cord[1]);
            }
            
            sort(row.begin(), row.end());
            sort(col.begin(), col.end());
            
            row.push_back(n+1);
            col.push_back(m+1);
            
            int maxUnblockR = 0;
            int maxUnblockC = 0;
            for(int ind=1; ind<row.size(); ind++){
                int unblockR = row[ind] - row[ind-1] - 1;
                int unblockC = col[ind] - col[ind-1] - 1;
                maxUnblockR = max(unblockR, maxUnblockR);
                maxUnblockC = max(unblockC, maxUnblockC);
            }
            
            // cout<<maxUnblockR<<' '<<maxUnblockC<<endl;
            return maxUnblockR * maxUnblockC;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends