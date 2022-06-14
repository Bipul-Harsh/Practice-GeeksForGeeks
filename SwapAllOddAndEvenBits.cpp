// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
    	// Your code here
    	unsigned int evenMask = 0b10101010101010101010101010101010;
        unsigned int oddMask = 0b01010101010101010101010101010101;
        
        int oddBits = n & oddMask;
        int evenBits = n & evenMask;
        
        evenBits >>= 1;
        oddBits <<= 1;
        
        unsigned int ans = evenBits | oddBits;
        return ans;
    }
};

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;//testcases
	while(t--)
	{
		unsigned int n;
		cin>>n;//input n
		
		Solution ob;
		//calling swapBits() method
		cout << ob.swapBits(n) << endl;
	}
	return 0;
}  // } Driver Code Ends