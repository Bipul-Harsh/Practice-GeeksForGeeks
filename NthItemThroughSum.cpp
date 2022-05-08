// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nthItem(int L1, int L2, int A[], int B[], int N)
    {
        // code here
        set<int>record;
        for(int ind=0; ind<L1; ind++){
            for(int sind=0; sind<L2; sind++){
                record.insert(A[ind]+B[sind]);
            }
        }
        if(record.size()<N)
            return -1;
        for(int ind=0; ind<N-1; ind++)
            record.erase(record.begin());
        auto ans = *(record.begin());
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int L1, L2, N;
        cin>>L1>>L2;
        int A[L1], B[L2];
        for(int i = 0;i < L1;i++)
            cin>>A[i];
        for(int i = 0;i < L2;i++)
            cin>>B[i];
        cin>>N;
        
        Solution ob;
        cout<<ob.nthItem(L1, L2, A, B, N)<<endl;
    }
    return 0;
}  // } Driver Code Ends