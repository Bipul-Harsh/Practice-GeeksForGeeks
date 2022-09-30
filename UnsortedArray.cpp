//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends


int findElement(int arr[], int n) {
    int pos = n-1;
    while( pos>0 && arr[pos] >= arr[pos-1] ){
        --pos;
    }
    
    if(pos == n-1)
        return -1;
    if(!pos)
        return arr[1];
    for(int ind=pos-1; ind>=0; ind--){
        while(pos < n-1 && arr[ind] > arr[pos])
            ++pos;
        if(pos == n-1)
            return -1;
    }
    return arr[pos];
}