//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        // code here
        int rc = 0, gc = 0, bc = 0;
        for(int ind=0; ind<n; ind++){
            if(a[ind] == 'R')
                ++rc;
            else if(a[ind] == 'G')
                ++gc;
            else
                ++bc;
        }
        
        if(rc == n || gc == n || bc == n)
            return n;
        
        if((rc%2 == gc%2) && (gc%2 == bc%2))
            return 2;
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends