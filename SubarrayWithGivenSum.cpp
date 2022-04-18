// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution

//code starts here
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        int sum;
        int startPos=0, endPos=0;
        vector<int>result;
        while(endPos<n){
            if(arr[endPos]>s){
                endPos++;
                startPos = endPos;
                continue;
            }
            if(arr[endPos]==s){
                startPos = endPos;
                break;
            }
            sum += arr[endPos];
            while(startPos<endPos && sum>s){
                sum -= arr[startPos];
                startPos++;
            }
            if(sum==s)
                break;
            endPos++;
        }
        if(endPos>=n){
            result.push_back(-1);
        }else{
            result.push_back(startPos+1);
            result.push_back(endPos+1);
        }
        return result;
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
