// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int M, int N, vector<vector<int>> Mat) {
        // code here
        for(int red=0; red<min(M, N)/2; red++){
            int temp = Mat[0+red][0+red];
            for(int ind=1+red; ind<N-red; ind++){
                swap(Mat[0+red][ind], temp);
            }
            for(int ind=1+red; ind<M-red; ind++){
                swap(Mat[ind][N-red-1], temp);
            }
            for(int ind=N-red-2; ind>=0+red; ind--){
                swap(Mat[M-1-red][ind], temp);
            }
            for(int ind=M-2-red; ind>=0+red; ind--){
                swap(Mat[ind][0+red], temp);
            }
        }
        return Mat;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(N, M, Mat);
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}  // } Driver Code Ends