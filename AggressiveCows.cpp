//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool isMaxMinDist(vector<int>stalls, int n, int k, int maxMinDist){
        int noOfCowsPlaced = 1;
        int lastCowPos = stalls[0];
        for(int ind=1; ind<n; ind++){
            if(stalls[ind]-lastCowPos >= maxMinDist){
                ++noOfCowsPlaced;
                lastCowPos = stalls[ind];
            }
            if(noOfCowsPlaced == k)
                return true;
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(), stalls.end());
        int minDist = 0;
        int maxDist = stalls[n-1] - stalls[0];
        int midDist;
        int ans = -1;
        while(minDist <= maxDist){
            midDist = minDist + (maxDist - minDist)/2;
            if(isMaxMinDist(stalls, n, k, midDist)){
                minDist = midDist+1;
                ans = midDist;
            } else {
                maxDist = midDist-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends