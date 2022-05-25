// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int gcd(int a, int b){
        if(b == 0)
            return a;
        return gcd(b, a%b);
    }
    
    int maxBinTreeGCD(vector<vector<int>> arr, int N) {
        // code here
        if(N<=2)
            return 0;
        
        sort(arr.begin(), arr.end());
        
        int maxGCD = 0;
        for(int ind=0; ind < arr.size()-1; ind++){
            if(arr[ind][0] == arr[ind+1][0]){
                maxGCD = max(maxGCD, gcd(arr[ind][1], arr[ind+1][1]));
            }
        }
        
        return maxGCD;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,u,v;
        cin>>N;
        
        vector<vector<int>> arr;
        
        for(int i=0; i<N-1; i++)
        {
            cin>>u>>v;
            vector<int> edge;
            edge.push_back(u);
            edge.push_back(v);
            arr.push_back(edge);
        }

        Solution ob;
        cout << ob.maxBinTreeGCD(arr,N) << endl;
    }
    return 0;
}  // } Driver Code Ends