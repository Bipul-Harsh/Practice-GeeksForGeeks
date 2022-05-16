// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    unordered_map<int, int>rec;
	    int sum = 0;
	    int rem;
	    int length = 0;
	    
	    for(int ind=0; ind<n; ind++){
	        sum += arr[ind];
	        rem = ((sum%k)+k)%k;
	        
	        if(!rem)
	            length = (ind+1);
	        else if(rec[rem])
	            length = max(length, (ind+1)-rec[rem]);
	        else
	            rec[rem] = ind+1;
	    }
	    
	    return length;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends