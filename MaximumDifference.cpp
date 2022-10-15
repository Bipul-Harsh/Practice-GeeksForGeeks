//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method */
    int findMaxDiff(int A[], int n)
    {
      //Your code here
      vector<int>ls(n, 0);
      vector<int>rs(n, 0);
      
      for(int ind=1; ind<n; ind++){
          for(int sind=ind-1; sind>=0; sind--){
              if(A[sind] < A[ind]){
                ls[ind] = A[sind];
                break;
              }
          }
      }
      
      for(int ind=n-2; ind>=0; ind--){
          for(int sind=ind+1; sind<n; sind++){
              if(A[sind] < A[ind]){
                rs[ind] = A[sind];
                break;
              }
          }
      }
      
      int maxDiff = 0;
      for(int ind=0; ind<n; ind++){
          int diff = abs(ls[ind]-rs[ind]);
          maxDiff = max(diff, maxDiff);
      }
      
      return maxDiff;
    }
};

//{ Driver Code Starts.
int main()
{
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
   	cout<<ob.findMaxDiff(a,n)<<endl;
   }
    return 0;
}



// } Driver Code Ends