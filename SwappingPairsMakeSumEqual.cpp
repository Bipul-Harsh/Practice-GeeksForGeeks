// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	
	int doExist(int Max[], int n, int Min[], int m, int diff){
	    sort(Max, Max+n);
	    sort(Min, Min+m);
	    
	    for(int i=0; i<n; i++){
	        int key = Max[i] - diff;
	        int mid;
	        int left = 0;
	        int right = m;
	        while(left <= right){
	            mid = left + (right - left)/2;
	            if(Min[mid] == key)
	                return 1;
	            else if(Min[mid] < key)
	                left = mid+1;
	            else
	                right = mid-1;
	        }
	    }
	    return -1;
	}
	
	int findSwapValues(int A[], int n, int B[], int m)
	{
        // Your code goes here
        int asum = 0, bsum = 0;
        for(int ind=0; ind<n; ind++)
            asum += A[ind];
        for(int ind=0; ind<m; ind++)
            bsum += B[ind];
        
        int diff = abs(asum - bsum);
        if(diff%2 == 1)
            return -1;
        if(asum > bsum)
            return doExist(A, n, B, m, diff/2);
        else
            return doExist(B, m, A, n, diff/2);
	}
 

};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}





  // } Driver Code Ends