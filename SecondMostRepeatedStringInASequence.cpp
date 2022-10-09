//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string, int>m = {{"", 0}};
        string maxString="", secMaxString="";
        for(int ind=0; ind<n; ind++){
            ++m[arr[ind]];
            if(m[arr[ind]] >= m[maxString]){
                if(maxString != arr[ind])
                    secMaxString = maxString;
                maxString = arr[ind];
            } else if(m[arr[ind]] > m[secMaxString]){
                secMaxString = arr[ind];
            }
        }
        return secMaxString;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends