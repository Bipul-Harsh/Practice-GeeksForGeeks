//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string str){    
        //code here
        int s = 0;
        int e = str.length()-1;
        int ns = 0;
        while(s <= e){
            if(str[s] != str[e]){
                ns += 1;
                s = 0;
                e = str.length() - 1 - ns;
                continue;
            }
            ++s;
            --e;
        }
        
        return ns;
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends