// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


int transitionPoint(int arr[], int n) {
    //Time: O(logn)
    //Space: O(1)
    // code here
    int start = 0;
    int end = n-1;
    int mid;
    if(arr[0]==1)
        return 0;
    if(arr[n-1]==0)
        return -1;
    while(start <= end){
        mid = start + (end-start);
        if(arr[mid]==0 && arr[mid+1]!=arr[mid])
            return mid+1;
        if(arr[mid]==1)
            end = mid-1;
        else
            start = mid+1;
    }
    return -1;
}