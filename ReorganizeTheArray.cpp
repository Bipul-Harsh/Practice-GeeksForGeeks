//{ Driver Code Starts
#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int * Rearrange(int *arr,int n);

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    int *b = Rearrange(a,n);
	    for(int i=0;i<n;i++)
	        cout << b[i] <<" ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends


int * Rearrange(int *arr,int n){
    // Complete the function
    for(int ind=0; ind<n; ind++){
        while(arr[ind] != -1 && arr[ind] != ind){
            swap(arr[ind], arr[arr[ind]]);
        }
    }
    
    return arr;
}
