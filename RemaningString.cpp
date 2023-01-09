//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	string printString(string &S, char ch, int count)
	{
	    // Your code goes here
	    int s = 0;
	    for(int ind=0; ind<S.length(); ind++){
	        if(S[ind] == ch){
	            --count;
	            if(!count){
	                s = ind+1;
	                break;
	            }
	        }
	    }
	    
	    if(count > 0 || s >= S.length())
	        return "Empty string";
	   
	   return S.substr(s, S.length());
	}
};

//{ Driver Code Starts.

int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		char ch;
   		int count;

   		cin >> s >> ch >> count;
   		Solution ob;
   		cout << ob.printString(s, ch, count) << "\n";
   		
   	}

    return 0;
}
// } Driver Code Ends