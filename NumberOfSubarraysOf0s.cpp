//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

long long int no_of_subarrays(int n, vector<int> &arr) {
    // Write your code here.
    arr.push_back(1);
    long long int cnt = 0;
    long long int s = 0;
    for(int ind=0; ind<n+1; ind++){
        if(arr[ind] == 1){
            cnt += (((s+1)*s)/2);
            s = 0;
        } else {
            ++s;
        }
    }
    
    return cnt;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends