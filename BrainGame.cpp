// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
    bool brainGame(vector<int>nums) {
        // Code here.
        vector<int> factors(1001, 0);

        for (int fact = 2; fact < 1001; ++fact) {
            for (int val = 2 * fact; val < 1001; val += i) {
                factors[val] = max(factors[val], 1 + factors[fact]);
            }
        }

        int result = 0;
        for (int ind = 0; ind < nums.size(); ++ind) {
            result = result ^ factors[nums[ind]];
        }

        return result != 0;
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
		Solution ob;
		bool ans = ob.brainGame(nums);
		if(ans)
			cout << "A\n";
		else cout << "B\n";
	}  
	return 0;
}  // } Driver Code Ends