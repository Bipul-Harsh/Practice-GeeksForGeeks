// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isRepeat(string s)
	{
	    // Your code goes here
	    int n = s.length();
	    if(n == 1)
	        return 0;
	       
	   int len = 1;
	   int ind = 1;
	   while(ind < n){
	       bool doDeviate = false;
	       for(int i=0; i<len; i++){
	           if(s[i] != s[ind+i]){
	               len = ++ind;
	               doDeviate = true;
	               break;
	           }
	       }
	       if(!doDeviate)
	        ind += len;
	   }
	   if(len > n/2)
	    return 0;
	   else
	    return 1;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;
        Solution ob;
   		cout << ob.isRepeat(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends