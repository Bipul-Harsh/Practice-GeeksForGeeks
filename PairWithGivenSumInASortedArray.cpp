//{ Driver Code Starts
#include <bits/stdc++.h>


using namespace std;




// } Driver Code Ends

class Solution{
  public:
    int Countpair(int arr[], int n, int sum){
        
        // Complete the function
        int f = 0, s = n-1;
        int cnt = 0;
        
        for(s; s>=0 && arr[s] >= sum; s--);
        // cout<<s<<endl;
        while(f < s){
            int S = arr[f] + arr[s];
            if(S == sum){
                ++cnt;
                ++f;
                --s;
                // cout<<arr[f]<<' '<<arr[s]<<endl;
            } else if(S < sum){
                ++f;
            } else {
                --s;
            }
        }
        
        return cnt ? cnt : -1;
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
        int arr[n+1];
        
        for(int i=0;i<n;i++)
        cin>>arr[i];

        int sum;
        cin>>sum;
        Solution obj;
        cout << obj.Countpair(arr, n, sum) << endl;
        
    }
	return 0;
}

// } Driver Code Ends