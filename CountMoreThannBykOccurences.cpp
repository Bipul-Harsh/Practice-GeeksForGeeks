//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        // Your code here
        unordered_map<int, int>um;
        set<int>s;
        for(int ind=0; ind<n; ind++){
            if(um[arr[ind]] == 0){
                um[arr[ind]] = 1;
            } else {
                ++um[arr[ind]];
            }
            s.insert(arr[ind]);
        }
        
        int cnt = 0;
        for(auto val : s){
            int count = um[val];
            if(count > n/k)
                ++cnt;
        }
        
        return cnt;
    }
};


//{ Driver Code Starts.
int main() {
    int t, k;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends