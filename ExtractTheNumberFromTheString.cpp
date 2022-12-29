//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    long long ExtractNumber(string S){
        
        //code here
        long long ans = -1;
        stringstream ss(S);
        string word;
        while (ss >> word) {
            bool has_nine = false;
            for (char c : word) {
                if (c == '9') {
                    has_nine = true;
                    break;
                }
            }
            if (!has_nine && isdigit(word[0])) { 
                long long num = stoll(word);
                ans = max(ans, num); 
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	string tc;
   	getline(cin, tc);
   	t = stoi(tc);
   	while(t--)
   	{
   		string s;
   		getline(cin, s);

   	
        Solution ob;
   		cout << ob.ExtractNumber(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends