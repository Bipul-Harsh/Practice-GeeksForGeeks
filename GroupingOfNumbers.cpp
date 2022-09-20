//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int arr[], int N, int K) {
        // code here
        vector<int>count(K, 0);
        
        for(int ind=0; ind<N; ind++){
            ++count[arr[ind]%K];
        }
        
        int left = 1;
        int right = K-1;
        int len = 0;
        while(left <= right){
            if(left == right && count[left]>0){
                ++len;
                break;
            }
            len += max(count[left], count[right]);
            ++left;
            --right;
        }
        
        if(count[0] > 0)
            ++len;
        
        return len;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends