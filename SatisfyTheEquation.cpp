//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int A[], int N) {
        // code here
        unordered_map<int, pair<int, int>> sumCord;
        set<vector<int>> sortedComb;
        vector<int> comb(4, -1);
        
        for(int itr1=0; itr1<N; itr1++){
            for(int itr2=itr1+1; itr2<N; itr2++){
                int sum = A[itr1] + A[itr2];
                if(sumCord.find(sum) != sumCord.end()){
                    comb[0] = sumCord[sum].first;
                    comb[1] = sumCord[sum].second;
                    comb[2] = itr1;
                    comb[3] = itr2;
                    
                    if(comb[0] != comb[2] && comb[1] != comb[2] && comb[0] != comb[3] && comb[1] != comb[3])
                        sortedComb.insert(comb);
                } else {
                    sumCord[sum] = {itr1, itr2};
                }
            }
        }
        if(comb[0] == -1)
            return comb;
        
        return *sortedComb.begin();
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends