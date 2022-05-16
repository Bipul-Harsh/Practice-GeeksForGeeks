// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        int minHt = arr[0];
        int maxHt = arr[n-1];
        int minHtDiff = maxHt - minHt;
        
        for(int ind=0; ind<n; ind++){
            if(arr[ind] < k)
                continue;
            
            minHt = min(arr[0]+k, arr[ind]-k);
            maxHt = max(arr[n-1]-k, arr[ind-1]+k);
            
            minHtDiff = min(minHtDiff, maxHt-minHt);
        }
        
        return minHtDiff;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends