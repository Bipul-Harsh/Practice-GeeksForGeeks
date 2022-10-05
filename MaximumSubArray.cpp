//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    vector<int>res;
	    int sum = 0;
	    int maxSum = 0;
	    int maxStart=-1;
	    int maxEnd=-1;
	    int maxLen=-1;
	    
	    int ind=0;
	    while(ind < n){
	        sum = 0;
	        int start = ind;
	        int len = 0;
	        while(a[ind] >= 0 && ind<n){
	            sum += a[ind];
	            ++len;
	            ++ind;
	        }
	        if(sum > maxSum || (sum == maxSum && len < maxLen)){
	            maxStart = start;
	            maxEnd = ind-1;
	            maxLen = len;
	            maxSum = sum;
	        }
	        ++ind;
	    }
	    
	    if(!maxSum)
	        return vector<int>{-1};
	    
	    for(int ind=maxStart; ind<=maxEnd; ind++){
	        res.push_back(a[ind]);
	    }
	    
	    return res;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends