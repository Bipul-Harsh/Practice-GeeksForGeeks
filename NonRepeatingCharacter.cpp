// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
       char ans = '$';
       unordered_map<char, int>record;
       for(int ind=0; ind<S.length(); ind++){
           record[S[ind]]++;
       }
       for(int ind=0; ind<S.length(); ind++){
           if(record[S[ind]]==1){
            ans = S[ind];
            break;
           }
       }
       return ans;
    }

};

// { Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}
  // } Driver Code Ends