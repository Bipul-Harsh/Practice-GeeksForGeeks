//{ Driver Code Starts
#include <iostream>
using namespace std;
#include <stdio.h>
 
int findEquilibrium(int [], int );
 
int main() {
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		cout<<findEquilibrium (a,n)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends


/* You are required to complete this method*/
int findEquilibrium(int A[], int n)
{
  //Your code here
  for(int ind=1; ind<n; ind++){
      A[ind] += A[ind-1];
  }
  for(int ind=1; ind<n-1; ind++){
      if(A[ind-1] == A[n-1]-A[ind])
        return ind;
  }
  
  return -1;
}