// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findTime(string S1, string S2) {
        // code here
        vector<int>pos(26,0);
        for(int ind=0; ind<S1.length(); ind++)
            pos[S1[ind]-'a'] = ind;
        
        int curr = 0;
        int prev = 0;
        int res = 0;
        
        for(int ind=0; ind<S2.length(); ind++){
            curr = pos[S2[ind]-'a'];
            res += abs(prev-curr);
            prev = curr;
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends