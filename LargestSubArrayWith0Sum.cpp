// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int, int> sumHistory;
        int maxSize=0;
        int size=0;
        int sum = 0;
        for(int ind=0; ind<n; ind++){
            sum += A[ind];
            if(sum == 0)
                size = ind+1;
            else if(!sumHistory[sum]){
                sumHistory[sum] = ind+1;
            }else{
                size = ind-sumHistory[sum]+1;;
            }
            if(size > maxSize)
                maxSize = size;
        }
        return maxSize;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends