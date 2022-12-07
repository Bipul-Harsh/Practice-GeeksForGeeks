//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        // code here
        int lDistCnt = 0, rDistCnt = 0;
        unordered_map<int, int>lCnt, rCnt;
        for(int ind=0; ind<N; ind++){
            if(rCnt[A[ind]] == 0){
                rCnt[A[ind]] = 1;
                ++rDistCnt;
            } else {
                ++rCnt[A[ind]];
            }
        }
        vector<int>res;
        for(int ind=0; ind<N; ind++){
            if(--rCnt[A[ind]] == 0){
                --rDistCnt;
            }
            res.push_back(lDistCnt-rDistCnt);
            if(lCnt[A[ind]] == 0){
                lCnt[A[ind]] = 1;
                ++lDistCnt;
            }
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends