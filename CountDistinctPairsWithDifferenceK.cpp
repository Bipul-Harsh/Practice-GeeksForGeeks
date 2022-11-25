//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalPairs(vector<int>nums, int k){
	    // Code here
	    map<int, int>valsCount;
	    int totalPairs = 0;
	    
	    for(auto val : nums){
	        ++valsCount[val];
	    }
	    
	    for(auto valCountPair : valsCount){
	        if(k == 0 && valCountPair.second > 0)
	            ++totalPairs;
	        else if(valsCount.find(valCountPair.first-k) != valsCount.end())
	            ++totalPairs;
	    }
	    
	    return totalPairs;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
		cin >> n >> k;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.TotalPairs(nums, k);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends