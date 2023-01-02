//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string S)
{
    // your code here
    int s1 = 0; // 0 1 0
    int s2 = 0; // 1 0 1
    for(int ind=0; ind<S.length(); ind++){
        char ch = S[ind];
        if((ind%2 == 0 && ch=='1') || (ind%2 == 1 && ch == '0')){
            ++s1;
        } else if((ind%2 == 0 && ch=='0') || (ind%2 == 1 && ch == '1')){
            ++s2;
        }
    }
    
    return min(s2, s1);
}