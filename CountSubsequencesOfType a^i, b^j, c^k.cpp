// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        //code here
        long mod = 1e9+7;
        long aPos = 0, bPos = 0, cPos = 0;
        
        for(char ch : s){
            if(ch == 'a'){
                aPos = (aPos*2 + 1) % mod;
            } else if(ch == 'b'){
                bPos = (bPos*2 + aPos) % mod;
            } else {
                cPos = (cPos*2 + bPos) % mod;
            }
        }
        return cPos;
    }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends