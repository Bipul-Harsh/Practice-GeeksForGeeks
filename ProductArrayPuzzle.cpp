// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here        
        long long int prod = 1;
        vector<long long int>ans(n, 0);
        if(n == 1){
            ans = {1};
            return ans;
        }
        if(n==2){
            ans = {nums[1], nums[0]};
            return ans;
        }
        int zeroCount=0;
        for(int ind=0; ind<n; ind++)
            if(nums[ind]!=0)
                prod *= nums[ind];
            else
                zeroCount++;
        if(zeroCount>1)
            return ans;
        if(zeroCount==1){
            for(int ind=0; ind<n; ind++)
                if(nums[ind]==0)
                    ans[ind] = prod;
            return ans;
        }
        for(int ind=0; ind<n; ind++)
            ans[ind] = prod/nums[ind];
        return ans;
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends