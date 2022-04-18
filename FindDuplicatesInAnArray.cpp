// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        /**
        Reason I take two boolean array is to reduce mem allocation as a single int takes 4bytes and 4*100000 is larges than two boolean array of same size
        */
        bool check[100001];
        bool done[100001];
        vector<int>result;
        for(int ind=0; ind<=100001; ind++){
            check[ind]=false;
            done[ind]=false;
        }
        for(int ind=0; ind<n; ind++)
            if(check[arr[ind]] && !done[arr[ind]]){
                result.push_back(arr[ind]);
                done[arr[ind]]=true;
            }
            else
                check[arr[ind]]=true;
        if(result.size()==0)
            result.push_back(-1);
        sort(result.begin(), result.end());
        return result;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
