//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<long long>sSum;
        map<int, long long>vCnt;
        
        for(auto val : arr){
            ++vCnt[val];
        }
        
        int pCnt = 0;
        long long pSum = 0;
        int pVal = 0;
        for(auto ko : vCnt){
            int nCnt = ko.second;
            vCnt[ko.first] = pSum + pVal * pCnt;
            pCnt = nCnt;
            pVal = ko.first;
            pSum = vCnt[ko.first];
        }
        
        for(auto val : arr){
            sSum.push_back(vCnt[val]);
        }
        
        return sSum;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends