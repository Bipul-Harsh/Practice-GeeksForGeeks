//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum number of consecutive steps 
    //to gain an increase in altitude with each step.
    int maxStep(int A[], int N)
    {
       //Your code here
       int maxInc = 0;
       int inc = 0;
       for(int ind=1; ind<N; ind++){
           if(A[ind] > A[ind-1]){
               ++inc;
           } else {
               if(inc > maxInc){
                   maxInc = inc;
               }
               inc = 0;
           }
       }
       if(inc > maxInc){
           maxInc = inc;
       }
       
       return maxInc;
    }
};

//{ Driver Code Starts.


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    Solution ob;
	    cout << ob.maxStep(a, n) << endl;
	}
	return 0;
}
// } Driver Code Ends