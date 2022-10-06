//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method*/
     int max_path_sum(int A[], int B[], int l1, int l2)
    {
    
        //Your code here
        int ai = 0, bi = 0;
        int maxSum = 0;
        
        int sum1 = 0;
        int sum2 = 0;
        while(ai < l1 && bi < l2){
            if( A[ai] < B[bi] ){
                sum1 += A[ai];
                ++ai;
            } else if(B[bi] < A[ai]){
                sum2 += B[bi];
                ++bi;
            } else {
                maxSum += max(sum1, sum2);
                maxSum += A[ai];
                ++ai;
                ++bi;
                sum1 = 0; sum2 = 0;
            }
        }
        
        for(ai; ai<l1; ai++)
            sum1 += A[ai];
        for(bi; bi<l2; bi++)
            sum2 += B[bi];
        maxSum += max(sum1, sum2);
        
        return maxSum;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;
        fflush(stdin);
        int a[N],b[M];
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<M;i++)
            cin>>b[i];
        Solution obj;
        int result = obj.max_path_sum(a,b,N,M);
        cout<<result<<endl;
    }
}


// } Driver Code Ends