//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string &str) {
        // your code here
        vector<bool>isPresent(26, false);
        for(auto ch:str){
            if(ch >= 'a' && ch <= 'z'){
                isPresent[ch-'a'] = true;
            } else if(ch >= 'A' && ch <= 'Z') {
                isPresent[ch-'A'] = true;
            }
        }
        for(int ind=0; ind<26; ind++)
            if(!isPresent[ind])
                return false;
        return true;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string str;
        getline(cin, str);
        Solution obj;
        if (obj.checkPangram(str) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends