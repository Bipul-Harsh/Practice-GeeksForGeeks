//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long X) {
        // code here
        int bitCount = 0;
        long long res = 0;
        while(X){
            ++bitCount;
            res <<= 1;
            if(X & 1){
                res |= 1;
            }
            X >>= 1;
        }
        return res << (32 - bitCount);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends