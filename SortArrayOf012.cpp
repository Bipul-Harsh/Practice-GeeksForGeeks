// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // coode here 
        int toSwap=-1;
        for(int ind=0; ind<n; ind++)
            if(a[ind]){
                toSwap = ind;
                break;
            }
        if(toSwap==-1)
            return;
        for(int ind=0; ind<n; ind++){
            if(a[ind]==0 && ind>toSwap){
                swap(a[ind],a[toSwap]);
                toSwap++;
            }
        }
        for(int ind=toSwap; ind<n; ind++)
            if(a[ind]==2){
                toSwap=ind;
                break;
            }
        if(a[toSwap]!=2)
            return;
        for(int ind=toSwap; ind<n; ind++){
            if(a[ind]==1 && ind>toSwap){
                swap(a[ind], a[toSwap]);
                toSwap++;
            }
        }
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends
