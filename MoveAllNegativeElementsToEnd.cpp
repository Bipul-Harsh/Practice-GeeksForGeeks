// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        // Your code goes here
        int rec[n];
        int negInd = n-1;
        int posInd = 0; 
        
        for(int ind=0; ind<n; ind++)
            if(arr[ind]<0){
                rec[negInd--] = arr[ind];
                
            }else{
                rec[posInd++] = arr[ind];
            }
        
        for(int ind=0; ind<posInd; ind++)
            arr[ind] = rec[ind];
        for(int ind=negInd+1; ind<n; ind++)
            arr[ind] = rec[n - (ind -negInd)];
        
        
    }
};

// { Driver Code Starts.
int main() {
	// your code goes here
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
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}
  // } Driver Code Ends