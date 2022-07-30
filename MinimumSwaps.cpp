//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimumSwaps(int c[],int v[],int n,int k,int b,int T)
    {
        // code here
        for(int ind=0; ind<n; ind++){
            c[ind] += v[ind]*T;
        }
        
        int minSwaps = 0;
        for(int i=n-1; i>=0 && k--; i--){
            if(c[i] >= b)
                continue;
            int j = i-1;
            while(j >= 0 && c[j] < b)
                j--;
            
            if(j == -1)
                return -1;
            
            swap(c[i], c[j]);
            minSwaps += (i-j);
        }
        // cout<<"k: "<<k<<endl;
        if(k != -1 && k != 0)
            return -1;
        
        return minSwaps;
    }
};

//{ Driver Code Starts.
int main(){
    int t=1,testcases=1;
    cin>>t;
    while(t>=testcases)
    {
        int n,k,b,T;
        cin>>n>>k>>b>>T;
        int c[n];
        int v[n];
        for(auto &j:c)
            cin>>j;
        for(auto &j:v)
            cin>>j;
        Solution s;
        int ans=s.minimumSwaps(c,v,n,k,b,T);
        cout<<ans<<endl;
        testcases++;
    }
    // TIME;
    return 0;
}
// } Driver Code Ends