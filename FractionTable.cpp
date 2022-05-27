// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> numAndDen(int n, int d) {
        // code here
        vector<int>ans={1,1};
        
        int num = 10000;
        int den = 10000;
        double given = 0.1*n/d;
        double closest = 100000.0;

        while(num > 0 && den > 0){
            for(;0.1*num/den>=given;num--);
            for(;0.1*num/den<given;den--);
            if(__gcd(num, den+1)!=1 || (__gcd(num, n)!=1 && __gcd(den+1, d)!=1))
                continue;
            double current = 0.1*num/(den+1);
            if((given - current) < closest){
                ans[0] = num;
                ans[1] = den+1;
                closest = given - current;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,d;
        cin >> n >> d;
        Solution ob;
        vector<int>ans=ob.numAndDen(n,d);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends