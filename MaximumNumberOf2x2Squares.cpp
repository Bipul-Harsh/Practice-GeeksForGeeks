//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long int numberOfSquares(long long int base)
    {
        //code here
        long long int n = (base-2)/2;
        long long ans = (n*(n+1))/2;
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		long long int base;
		cin >> base;

        Solution ob;
		cout << ob.numberOfSquares(base) << "\n";

	}

	return 0;
}

// } Driver Code Ends