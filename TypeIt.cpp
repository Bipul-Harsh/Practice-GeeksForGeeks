//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
        int len = s.length();
        
        if(len <= 3)
            return len;
            
        int sInd1 = 0;
        int sInd2 = len/2;
        int s2Start = len/2;
        int maxSimilar = 0;
        while(sInd1 < s2Start){
            if(s[sInd1] == s[sInd2]){
                ++sInd2;
                ++maxSimilar;
            } else {
                --s2Start;
                sInd2 = s2Start;
                maxSimilar = 0;
                sInd1 = 0;
                continue;
            }
            ++sInd1;
        }
        
        return min(len, len - maxSimilar + 1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends