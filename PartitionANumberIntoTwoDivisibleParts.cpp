// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string stringPartition(string S, int a, int b){
        // code here
        if(S.length()<2)
            return "-1";
        int end;
        int s1, s2;
        int len = S.length();
        for(int prt=1; prt<len; prt++){
            s1 = stoi(S.substr(0, prt));
            s2 = stoi(S.substr(prt, len));
            if(s1%a == 0 && s2%b == 0)
                return S.substr(0, prt)+" "+S.substr(prt, len);
        }
        return "-1";
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {   
        int a,b;
        string S;
        cin >> S >> a >> b;
        Solution ob;
        cout << ob.stringPartition(S,a,b) << endl;
    }
    return 0; 
}   // } Driver Code Ends