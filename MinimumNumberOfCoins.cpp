// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int>ans;
        vector<int>curr = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        while(N){
            for(int ind = curr.size()-1; ind>-1; ind--){
                int count = N / curr[ind];
                N = N % curr[ind];
                for(int itr=0; itr<count; itr++)
                    ans.push_back(curr[ind]);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends