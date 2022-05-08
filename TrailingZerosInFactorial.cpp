// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int trailingZeroes(int N)
    {
        // Write Your Code here
        int fcount = 0;
        int tcount = 0;
        int fval = 5;
        for(int val=5; val<=N; val*=5)
            fcount+=N/val;
        for(int val=2; val<=N; val*=2)
            tcount+=N/val;
        return min(fcount, tcount);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans  = ob.trailingZeroes(N);
        cout<<ans<<endl;
    }
    return 0;
}  // } Driver Code Ends