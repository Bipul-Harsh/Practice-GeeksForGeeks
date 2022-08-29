//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N) 
    { 
        // Your code here
        if(N == 1)
            return 0;
        int end=0;
        int maxVal = 0;
        int start = A[0];
        for(int ind=0; ind<=end; ind++){
            if(A[ind] > start)
                continue;
            int eind = N-1;
            while(eind > end && A[eind] < A[ind])
                --eind;
            int val = eind - ind;
            if(val > maxVal)
                maxVal = val;
            if(ind == eind)
                ++eind;
            end = eind;
            start = A[ind];
        }
        return maxVal;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends