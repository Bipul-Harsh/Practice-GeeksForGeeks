//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    bool isLower(char ch){
        if(ch >= 'a' && ch <= 'z')
            return true;
        return false;
    }
    int countSubstring(string S)
    {
        // code here
        int tc = 0;
        int l = S.length();
        for(int i=0; i<l; i++){
            int lc = 0;
            int uc = 0;
            for(int j=i; j<l; j++){
                if(isLower(S[j]))
                    ++lc;
                else 
                    ++uc;
                if(lc == uc)
                    ++tc;
            }
        }
        
        return tc;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends