//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> map;
        
        for(auto &i : nums)
            map[i]++;
            
        for(auto i : map){
            pq.push({i.second, i.first});
        }
        
        nums.clear();
        
        while(k--){
            nums.emplace_back(pq.top().second);
            pq.pop();
        }
        
        return nums;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends