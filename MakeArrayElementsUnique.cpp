//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        // Code here
        if(N == 1)
            return 0;
        sort(arr.begin(), arr.end());
        long long int cnt = 0;
        for(int ind=1; ind<N; ind++){
            if(arr[ind] <= arr[ind-1]){
                cnt += (arr[ind-1]+1) - arr[ind];
                arr[ind] = arr[ind-1]+1;
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends