//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSetBit(int val){
        int setBitCount = 0;
        while(val){
            if(val&1)
                ++setBitCount;
            val>>=1;
        }
        return setBitCount;
    }
    int msbPos(int val){
        int pos = 0;
        int posVal = 1;
        while(posVal <= val){
            ++pos;
            posVal <<= 1;
        }
        return pos;
    }
    int minVal(int a, int b) {
        // code here
        int b_setBits = countSetBit(b);
        int a_setBits = countSetBit(a);
        int res = 0;
        if(b_setBits <= a_setBits){
            while(b_setBits){
                int a_msbPos = msbPos(a);
                int val = 1 << (a_msbPos-1);
                res ^= val;
                a ^= val;
                --b_setBits;
            }
        } else {
            while(b_setBits){
                int a_msbPos = msbPos(a);
                if(b_setBits <= a_msbPos){
                    int val = 1 << (a_msbPos-1);
                    res ^= val;
                    a ^= val;
                } else {
                    int val = 1 << (b_setBits-1);
                    res ^= val;
                }
                --b_setBits;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends