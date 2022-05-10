// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void getSortedArrayBST(vector<int>nums, vector<int>&res, int start, int end){
        if(start>end)
            return;
        int mid = start + (end-start)/2;
        res.push_back(nums[mid]);
        getSortedArrayBST(nums, res, start, mid-1);
        getSortedArrayBST(nums, res, mid+1, end);
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        vector<int>sortedArrayBST;
        getSortedArrayBST(nums, sortedArrayBST, 0, nums.size()-1);
        return sortedArrayBST;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends