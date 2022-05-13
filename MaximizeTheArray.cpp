// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> maximizeArray(int arr1[], int arr2[], int n) {
            // code here 
        vector<int>combine;
        vector<int>ans;
        int max, min;
        for(int ind=0; ind<n; ind++){
            combine.push_back(arr1[ind]);
            combine.push_back(arr2[ind]);
        }
        sort(combine.begin(), combine.end(), [](int val1, int val2){return val1>val2;});
        max = combine[0];
        min = combine[0];
        int ind=1;
        int cnt=n-1;
        while(cnt && ind<2*n){
            if(combine[ind]!=combine[ind-1]){
                min = combine[ind];
                cnt--;
            }
            ind++;
        }
        // cout<<min<<' '<<max<<endl;
        map<int, bool>visited;
        for(int ind=0; ind<n; ind++)
            if(arr2[ind]>=min && arr2[ind]<=max && !visited[arr2[ind]]){
                ans.push_back(arr2[ind]);
                visited[arr2[ind]] = true;
            }
        for(int ind=0; ind<n; ind++)
            if(arr1[ind]>=min && arr1[ind]<=max && !visited[arr1[ind]]){
                ans.push_back(arr1[ind]);
                visited[arr1[ind]] = true;
            }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr1[n], arr2[n];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.maximizeArray(arr1, arr2, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends