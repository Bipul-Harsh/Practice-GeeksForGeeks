//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
	int findInd(int val, int *arr, int n){
	    int s = 0;
	    int l = n-1;
	    while(s <= l){
	        int m = s + (l - s)/2;
	        if(arr[m] == val)
	            return m;
	        else if(arr[m] < val)
	            s = m+1;
	        else
	            l = m-1;
	    }
	    return -1;
	}
	void convert(int arr[], int n) {
	    // code here
	    int ca[n];
	    for(int ind=0; ind<n; ind++)
	        ca[ind] = arr[ind];
	    sort(ca, ca+n);
	    
	    for(int ind=0; ind<n; ind++){
	        int pos = findInd(arr[ind], ca, n);
	        arr[ind] = pos;
	    }
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.convert(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends