// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int binSearch(int A[], int l, int h, int key){
        int mid;
        while(l <= h){
            mid = l + (h-l)/2;
            if(A[mid] == key)
                return mid;
            else if(A[mid] > key)
                h = mid-1;
            else
                l = mid+1;
        }
        return -1;
    }
    
    int findEnd(int A[], int l, int h){
        int mid;
        int start = l;
        int end = h;
        while(start <= end){
            mid = start + (end - start)/2;
            if((mid == l || A[mid-1] < A[mid]) && (mid < h && A[mid] < A[mid+1])){
                if(A[mid] > A[l])
                    start = mid+1;
                else
                    end = mid-1;
            } else {
                break;
            }
        }
        if(mid == h || A[mid] > A[mid + 1])
            return mid;
        if(A[mid] < A[mid-1])
            return mid-1;
    }
    
    int search(int A[], int l, int h, int key){
    //complete the function here
        int fe = findEnd(A, l, h);

        int loc = binSearch(A, l, fe, key);
        if(loc != -1)
            return loc;
        
        loc = binSearch(A, fe+1, h, key);
        return loc;
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends