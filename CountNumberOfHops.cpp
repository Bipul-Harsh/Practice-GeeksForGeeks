// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        // your code here
        long long arr[3] = {1, 1, 2};
        long long temp;
        if(n<3)
            return arr[n];
        for(int itr=3; itr<=n; itr++){
            temp = arr[2];
            arr[2] = ((arr[0]+arr[1])%1000000007 + arr[2])%1000000007;
            arr[0] = arr[1];
            arr[1] = temp;
        }
        return arr[2];
    }
};


// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}
  // } Driver Code Ends