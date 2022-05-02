// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
class Solution{
  public:
    int maxLen(int arr[], int N)
    {
        unordered_map<int, int>record;
        int cummulative_sum = 0;
        int maxSubArray=0;
        int size;
        for(int ind=0; ind<N; ind++){
            cummulative_sum += arr[ind]==0?-1:1;
            if(!cummulative_sum){
                if(ind+1 > maxSubArray)
                    maxSubArray = ind+1;
            }
            else if(!record[cummulative_sum]){
                record[cummulative_sum]=ind+1;
            }
            else{
                size = (ind+1-record[cummulative_sum]);
                if(size > maxSubArray)
                    maxSubArray = size;
            }
        }
        return maxSubArray;
    }
};


// { Driver Code Starts.

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends