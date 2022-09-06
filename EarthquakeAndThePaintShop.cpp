//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct alphanumeric {
    string name;
    int count;
};
class Solution {
  public:
    vector<alphanumeric> sortedStrings(int N, vector<string> A) {
        // code here
        vector<alphanumeric> ans;
        
        sort(A.begin(), A.end(), [](string s1, string s2){
            for(int ind=0; ind<43; ind++){
                if(s1[ind] < s2[ind])
                    return true;
                if(s1[ind] > s2[ind])
                    return false;
            }
            return true;
        });
        
        ans.push_back({A[0], 1});
        int lastInd = 0;
        for(int ind=1; ind<A.size(); ind++){
            if(A[ind] == A[ind-1])
                ++ans[lastInd].count;
            else{
                ans.push_back({A[ind], 1});
                ++lastInd;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        cin.ignore();
        vector<string> v;
        for (int i = 0; i < N; i++) {
            string s;
            getline(cin, s);
            v.push_back(s);
        }
        Solution ob;
        vector<alphanumeric> ans = ob.sortedStrings(N, v);
        for (auto u : ans) cout << u.name << " " << u.count << "\n";
    }
}
// } Driver Code Ends