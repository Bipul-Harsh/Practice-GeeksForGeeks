//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        //code here.
        int left = 0;
        int right = n-1;
        int mid;
        while(left <= right){
            mid = left + (right-left)/2;
            int size = right-left+1;
            if(mid % 2){
                if(arr[mid] == arr[mid-1])
                    left = mid + 1;
                else if(arr[mid] == arr[mid+1])
                    right = mid-1;
                else
                    return arr[mid];
            } else {
                if(arr[mid] == arr[mid+1])
                    left = mid + 2;
                else if(arr[mid] == arr[mid-1])
                    right = mid - 2;
                else
                    return arr[mid];
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends