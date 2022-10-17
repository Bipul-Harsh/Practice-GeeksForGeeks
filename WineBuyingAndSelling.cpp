//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& Arr, int N){
      //Code here.
      vector<pair<int, int>>negArr;
      vector<pair<int, int>>posArr;
      int reqLeft = 0;
      for(int ind=0; ind<N; ind++){
          if(Arr[ind] < 0)
            negArr.push_back({abs(Arr[ind]), ind});
          else{
            posArr.push_back({Arr[ind], ind});
            reqLeft += Arr[ind];
          }
      }
      
      int negPos = 0, negLen = negArr.size();
      int posPos = 0, posLen = posArr.size();
      long long int res = 0;
      while(reqLeft){
          int negVal = negArr[negPos].first;
          int posVal = posArr[posPos].first;
          int reqComp = min(negVal, posVal);
          int dist = abs(negArr[negPos].second - posArr[posPos].second);
          res += reqComp * dist;
          reqLeft -= reqComp;
          
          if(negVal == posVal){
              ++negPos;
              ++posPos;
          } else if(negVal > posVal){
              negArr[negPos].first -= reqComp;
              ++posPos;
          } else {
              posArr[posPos].first -= reqComp;
              ++negPos;
          }
      }
      
      return res;
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
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends