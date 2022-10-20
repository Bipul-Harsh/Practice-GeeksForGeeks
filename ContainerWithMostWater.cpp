//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long A[], int len)
{
    // Your code goes here
    int left = 0;
    int right = len-1;
    long long res = 0;
    while(left < right){
        int minHeight = min(A[left], A[right]);
        long long area = minHeight * (right-left);
        res = max(res, area);
        if(A[left] < A[right])
            ++left;
        else
            --right;
    }
    
    return res;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends