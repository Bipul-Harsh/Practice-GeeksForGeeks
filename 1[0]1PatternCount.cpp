//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{
    public:
        int patternCount(string S) 
        { 
            //code here.
            int cnt = 0;
            
            bool s1 = false;
            bool z = false;
            int ind=0;
            while(ind < S.length()){
                if(S[ind] == '1'){
                    ++ind;
                    while(S[ind] == '0')
                        ++ind;
                    if(S[ind] == '1' && S[ind-1] == '0')
                        ++cnt;
                } else {
                    ++ind;
                }
            }
            
            
            return cnt;
        } 

};

//{ Driver Code Starts.
int main() 
{ 
	int t;
	cin>>t;
	while(t--){
	    string S;
    	cin>>S;
    	Solution ob;
    	cout <<ob.patternCount(S) << endl; 
	}
	return 0; 
} 

// } Driver Code Ends