//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string A, string B)
	{
	    string ans;
	 
	    int sizeA = A.size()-1;
	    int sizeB = B.size()-1;
	    
	    int carry = 0;
	    int res = 0;
	    for(int i=sizeA, j=sizeB;i>=0 || j>=0;i--,j--) {
	        int a = (i>=0)?A[i]-48:0;
	        int b = (j>=0)?B[j]-48:0;
	        
	        res = a ^ b ^ carry;
	        ans += to_string(res);
	        
	        if(a == 1 && b == 1) carry = 1;
	        else if(a == 0 && b == 0 && carry == 1) carry = 0;
	        else if((a == 1 || b == 1) && carry == 1) carry = 1;
	    }
	    
	    if(carry == 1) ans += to_string(carry);
	    
	    while(ans.back() == '0') {
	        ans.pop_back();
	    }
	    
	    reverse(ans.begin(), ans.end());
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends