//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++
class Solution
{
   public:
    string ReFormatString(string S, int K){
    	int charCount = 0;
    	string charStr;
    	int l = S.length();
    	
    	for(int ind=0; ind<l; ind++){
    	    if(S[ind] != '-'){
    	        if(S[ind] >= 'a' && S[ind] <= 'z')
    	            S[ind] = 'A' + (S[ind]-'a');
    	        charStr += S[ind];
    	        charCount++;
    	    }
    	}
    	
    	int rem = charCount%K;
    	int csl = charStr.length();
    	string res;
    	if(rem == 0){
    	    for(int ind=0; ind<csl; ind++){
    	        if(ind && !(ind%K)){
    	            res += '-';
    	            res += charStr[ind];
    	        } else {
    	            res += charStr[ind];
    	        }
    	    }
    	} else {
    	    for(int ind=0; ind<rem; ind++){
    	        res += charStr[ind];
    	    }
    	    for(int ind=rem; ind<csl; ind++){
    	        if(!((ind-rem)%K)){
    	            res += '-';
    	            res += charStr[ind];
    	        }
    	        else
    	            res += charStr[ind];
    	    }
    	}
    	
    	return res;
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
	    int K;
	    cin >> K;
	    Solution ob;  
	    string ans=ob.ReFormatString(S, K);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends