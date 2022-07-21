//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int *res = new int[2];
        
        long long int totalSum = 0;
        for(int ind=0; ind<n; ind++)
            totalSum += arr[ind];
        
        // Finding repeatitive value
        for(int ind=0; ind<n; ind++){
            int val = abs(arr[ind]);
            if(arr[val-1] < 0){
                res[0] = val;
                break;
            } else {
                arr[val-1] = -arr[val-1];
            }
        }
        
        // Finding missing value
        long long actualSum = (n%2) == 0 ? (n>>1)*(n+1) : ((n+1)>>1) * n;
        int diff = actualSum - totalSum;
        res[1] = res[0] + diff;
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends