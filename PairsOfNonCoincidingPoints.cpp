// { Driver Code Starts

#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    int numOfPairs(int X[], int Y[], int N) {
        // code here
        /**
         * On solving the equation of comparing euclidean and manhattan formula
         * Final Expression,
         *      
         *      2 * |x2-x1| * |y2-y1| = 0
         * 
         * so if two points gives above expr 0 then they follow both formula
         * - it means that either x2 gets equal to y
         * - or y2 gets equal to x will be our answer
         * 
         * Corner Case:
         * When both point are equal we have to avoud that count
         */
         unordered_map<int, int>xCount;
         unordered_map<int, int>yCount;
         unordered_map<string, int>xyCount;
         string xyStr;
         int ans=0;
         for(int ind=0; ind<N; ind++){
             xyStr = to_string(X[ind])+':'+to_string(Y[ind]);
             ans += xCount[X[ind]] + yCount[Y[ind]] - (2*xyCount[xyStr]);
             xCount[X[ind]]++;
             yCount[Y[ind]]++;
             xyCount[xyStr]++;
         }
         return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        int X[N], Y[N];
        
        for(int i=0; i<N; i++)
            cin>>X[i];
        for(int i=0; i<N; i++)
            cin>>Y[i];

        Solution ob;
        cout << ob.numOfPairs(X,Y,N) << endl;
    }
    return 0;
}  // } Driver Code Ends