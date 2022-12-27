//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution{
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        sort(arr.begin(), arr.end());
        int ms = INT_MAX;
        int n = arr.size();
        for(int i=0; i<n; i++){
            int a = arr[i];
            int l = i+1;
            int r = n-1;
            while(l < r){
                int s = a + arr[l] + arr[r];
                if(s == target)
                    return s;
                if(abs(target-s) < abs(target - ms))
                    ms = s;
                if(abs(target-s) == abs(target-ms))
                    ms = max(s, ms);
                if(s > target)
                    --r;
                else
                    ++l;
            }
        }
        
        return ms;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        
        int n,target;
        cin >> n >> target;
        
        vector<int> vec(n);
        
        for(int i = 0 ; i < n ; ++ i ) 
            cin >> vec[i];
        Solution obj;
        cout << obj.threeSumClosest(vec, target) << "\n";
    }
}

//Position this line where user code will be pasted.

// } Driver Code Ends