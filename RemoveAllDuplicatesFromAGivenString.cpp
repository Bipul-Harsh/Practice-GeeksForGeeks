//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    vector<bool>lower(26, 0);
	    vector<bool>upper(26, 0);
	    string res = "";
	    for(auto ch : str){
	        if(ch >= 'a' && ch <= 'z'){
	            if(!lower[ch-'a']){
	                res += ch;
	                lower[ch-'a'] = true;
	            }
	        } else {
	            if(!upper[ch-'A']){
	                res += ch;
	                upper[ch-'A'] = true;
	            }
	        }
	    }
	    
	    return res;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends