// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> shiftPile(int N, int n){
        // code here
        vector<int>res;
        towerOfHanoi(N, n, 1, 2, 3, res);
        return res;
    }
    
    void towerOfHanoi(int N, int &n, int from, int use, int to, vector<int>&res){
        if(N==0)
            return;
        
        towerOfHanoi(N-1, n, from, to, use, res);
        
        if(!(--n)){
            res.push_back(from);
            res.push_back(to);
        }
        
        towerOfHanoi(N-1, n, use, from, to, res);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends
