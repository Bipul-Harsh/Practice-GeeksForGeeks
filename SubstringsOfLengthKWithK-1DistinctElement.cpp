//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int countOfSubstrings(string S, int K) {
        // code here
        int uniqueCount = 0;
        int ans = 0;
        vector<int>charArray(26, 0);
        for(int ind=0; ind<K-1; ind++){
            int charVal = S[ind] - 'a';
            if(!charArray[charVal])
                ++uniqueCount;
            ++charArray[charVal];
        }
        for(int ind=K-1; ind<S.length(); ind++){
            int charVal = S[ind] - 'a';
            if(!charArray[charVal])
                ++uniqueCount;
            charArray[charVal]++;
            if(uniqueCount == K-1)
                ++ans;
            charVal = S[ind-(K-1)] - 'a';
            --charArray[charVal];
            if(!charArray[charVal])
                --uniqueCount;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}
// } Driver Code Ends