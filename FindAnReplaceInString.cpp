// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string findAndReplace(string S ,int Q, int index[], string sources[], string targets[]) {
        // code here
        for(int ind = Q-1; ind > -1; ind--){
            int slen = sources[ind].length();
            int start = index[ind];
            
            string substr = S.substr(start, min(sources[ind].length(), S.length()-start));
            
            if(substr == sources[ind]){
                string first = S.substr(0, start);
                string last = S.substr(start+sources[ind].length());
                
                S = first + targets[ind] + last;
            }
        }
        return S;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}  // } Driver Code Ends