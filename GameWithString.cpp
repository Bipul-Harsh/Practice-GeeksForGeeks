//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        vector<int>chCnt(26, 0);
        for(auto ch : s){
            ++chCnt[ch-'a'];
        }
        
        while(k){
            sort(chCnt.begin(), chCnt.end(), greater<int>());
            --chCnt[0];
            --k;
        }
        
        int ans = 0;
        for(int ind=0; ind<26; ind++){
            ans += pow(chCnt[ind], 2);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends