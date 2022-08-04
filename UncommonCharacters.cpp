//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            // code here
            string ans;
            vector<int>ac(26, 0);
            vector<int>bc(26, 0);
            for(int ind=0; ind<A.length(); ind++){
                ac[A[ind]-'a'] = 1;
            }
            
            for(int ind=0; ind<B.length(); ind++){
                bc[B[ind]-'a'] = 1;
            }
            
            
            for(int ind=0; ind<26; ind++){
                if(ac[ind] != bc[ind]){
                    ans += 'a'+ind;
                }
            }
            
            if(!ans.length())
                return "-1";

            return ans;
            
        }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends