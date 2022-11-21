//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	vector<int> findSum(vector<int> &a, vector<int> &b) {
	    // code here
	    int td;
	    int aL = a.size();
	    int bL = b.size();
	    int minL = min(aL, bL);
	    int maxL = max(aL, bL);
	    vector<int>ans;
	    int rem = 0;
	    
	    for(int ind=0; ind<minL; ind++){
	        int sum = a[aL-(1+ind)] + b[bL - (1+ind)] + rem;
	        ans.push_back(sum%10);
	        rem = sum/10;
	    }
	    
	    for(int ind=0; ind < (maxL - minL); ind++){
	        int sum;
	        if(aL > bL){
	            sum = a[aL - (minL + 1 + ind)] + rem;
	        } else {
	            sum = b[bL - (minL + 1 + ind)] + rem;
	        }
	        rem = sum / 10;
	        ans.push_back(sum%10);
	    }
	    if(rem)
    	    ans.push_back(rem);
	    
	    reverse(ans.begin(), ans.end());
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        Solution ob;
        auto ans = ob.findSum(a, b);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends