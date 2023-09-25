//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	bool isSetBit(char ch){
	    return ch == '1';
	}
	int isDivisible(string s){
	    //complete the function here
	    int oCount = 0;
	    int eCount = 0;
	    
	    for(int ind=0; ind<s.size(); ind+=2){
	        if(isSetBit(s[ind]))
	            ++oCount;
	    }
	    
	    for(int ind=1; ind<s.size(); ind+=2){
	        if(isSetBit(s[ind]))
	            ++eCount;
	    }
	    
	    if((oCount - eCount)%3 == 0)
	        return 1;
	    return 0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends