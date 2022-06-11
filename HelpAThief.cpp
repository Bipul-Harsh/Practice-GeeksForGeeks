// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxCoins(int A[], int B[], int T, int N) {
        // code here
        vector<pair<int, int>>platesCoins;
        for(int ind=0; ind<N; ind++){
            platesCoins.push_back(make_pair(A[ind], B[ind]));
        }
        sort(platesCoins.begin(), platesCoins.end(), [](pair<int, int>a, pair<int, int>b){
            return a.second > b.second;
        });
        
        
        int maxGold = 0;
        for(int ind=0; ind<N && T; ind++){
            if(platesCoins[ind].first < T){
                maxGold += platesCoins[ind].first * platesCoins[ind].second;
                T -= platesCoins[ind].first;
            }else{
                maxGold += T * platesCoins[ind].second;
                T = 0;
            }
        }
        
        return maxGold;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends