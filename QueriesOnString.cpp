// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<int>SolveQueris(string str, vector<vector<int>>Query){
	    // Code here
	    vector<int>ans;
	    for(int i=0; i<Query.size(); i++){
	        vector<bool>visited(26,false);
	        int distinctCount = 0;
	        for(int ind=Query[i][0]-1; ind<Query[i][1];ind++){
	            if(!visited[str[ind]-'a']){
	                distinctCount++;
	                visited[str[ind]-'a']=true;
	            }
	        }
	        ans.push_back(distinctCount);
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		int q;
		cin >> q;
		vector<vector<int>>Query;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			Query.push_back({l, r});
		}
		Solution obj;
		vector<int> ans = obj.SolveQueris(str, Query);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends