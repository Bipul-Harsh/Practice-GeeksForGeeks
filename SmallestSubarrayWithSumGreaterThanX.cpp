// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here   
        int sum = 0;
        int minLength = n+1;
        
        int start = 0;
        int end = 0;
        while(end<n){
            sum += arr[end];
            while(sum > x){
                if(end-start+1 < minLength)
                    minLength = end-start+1;
                
                sum -= arr[start];
                start++;
            }
            end++;
        }
        if(minLength<=n)
            return minLength;
        
        return 0;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}  // } Driver Code Ends