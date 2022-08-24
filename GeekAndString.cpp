//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
        // code here
        vector<int>prefixCounts(Q, 0);
        unordered_map<string, int> strCount;
        
        for(int ind=0; ind<N; ind++){
            string str = "";
            for(auto ch : li[ind]){
                str += ch;
                ++strCount[str];
            }
        }
        
        for(int ind=0; ind<Q; ind++){
            prefixCounts[ind] = strCount[query[ind]];
        }
        return prefixCounts;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int Q, N, i = 0, x;
	    cin>>N;
	    string s;
	    string li[N];
	    for(int i = 0;i < N;i++)
	        cin>>li[i];
	    cin>>Q; 
	    x = Q;
	    string query[Q];
	    while(Q--){
	        cin>>s;
	        query[i++] = s;
	    }
	    
	    Solution ob;
	    vector<int> ans = ob.prefixCount(N, x, li, query);
	    for(auto i: ans) 
	        cout<<i<<"\n";
    }
    return 0;
}
// } Driver Code Ends