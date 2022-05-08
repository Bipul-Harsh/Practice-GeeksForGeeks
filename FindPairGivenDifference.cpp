// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    //code
    bool pairCount = false;
    sort(arr, arr+size, [](int a, int b){return a>=b;});
    int start, end, mid, check;
    for(int ind=0; ind<size-1 && arr[ind]>n && !pairCount; ind++){
        if(arr[ind]==-1)
            continue;
        start = ind+1;
        end = size-1;
        check = arr[ind]-n;
        while(start<=end){
            mid = start + (end-start)/2;
            if(check==arr[mid]){
                pairCount = true;
                break;
            }
            else if(arr[mid]>check)
                start = mid+1;
            else
                end = mid-1;
        }
    }
    return pairCount;
}