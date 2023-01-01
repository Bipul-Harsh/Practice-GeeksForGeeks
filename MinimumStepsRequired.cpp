//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    int ca = 0;
    int cb = 0;
    if(str[0] == 'a'){
        ++ca;
    } else {
        ++cb;
    }
    
    for(int ind=0; ind<str.length(); ind++){
        if(str[ind] == 'a' && str[ind-1] != 'a')
            ++ca;
        else if(str[ind] == 'b' && str[ind-1] == 'a')
            ++cb;
    }
    
    return min(ca, cb) + 1;
    
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends