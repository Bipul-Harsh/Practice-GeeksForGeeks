//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a, a+n);
        
        for(int ind=0; ind<n && a[ind] < 0 && k > 0; ind++){
            a[ind] *= -1;
            k--;
        }
        
        sort(a, a+n);
        if(k%2)
            a[0] *= -1;
        long long int sum = 0;
        for(int ind=0; ind<n; ind++)
            sum += a[ind];
        
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}
// } Driver Code Ends