//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        // code here 
        int lInd = 0;
        int seqLen = 0;
        int maxLen = 0;
        for(int rInd=0; rInd<n; rInd++){
            if(arr[rInd] == 'A'){
                ++seqLen;
            } else {
                if(m == 0){
                    while(arr[lInd++] == 'A' && lInd<=rInd){
                        --seqLen;
                    }
                } else {
                    ++seqLen;
                    --m;
                }
            }
            if(seqLen > maxLen)
                maxLen = seqLen;
        }
        return maxLen;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends