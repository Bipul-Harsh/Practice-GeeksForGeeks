// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        string ans;
        int endInd=S.length();
        int startInd=S.length()-1;
        while(startInd>=0){
            if(S[startInd]=='.' && startInd+1<endInd){
                ans += S.substr(startInd+1, endInd-startInd-1)+'.';
                endInd=startInd;
            }
            startInd--;
        }
        ans += S.substr(startInd+1, endInd)+'.';
        return ans.substr(0, S.length());
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends