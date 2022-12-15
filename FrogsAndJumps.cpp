//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        vector<bool>isVisited(leaves, false);
        
        for(int ind=0; ind<N; ind++){
            int hop = frogs[ind];
            if(hop == 1)
                return 0;
            if(!isVisited[hop-1])
                for(int h=hop-1; h<leaves; h+=hop){
                    isVisited[h] = true;
                }
        }
        
        int cnt = 0;
        for(int ind=0; ind<leaves; ind++)
            if(isVisited[ind] == false)
                ++cnt;
                
        return cnt;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends