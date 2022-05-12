// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int farthest = 0, jumps = 0, currentJumpEnd = 0;
        for(int ind=0; ind<n-1; ind++){
            farthest = max(farthest, ind + arr[ind]);
            if(currentJumpEnd == ind){
                if(farthest <= ind)
                    return -1;
                currentJumpEnd = farthest;
                jumps++;
                
            }
        }
        return jumps;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends