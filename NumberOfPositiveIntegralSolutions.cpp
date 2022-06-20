// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    long fact(int n){
        if(n==1)
            return 1;
        return n*fact(n-1);
    }
    
    int getNum(string s){
        int res = 0;
        for(char n : s){
            res = res*10 + (n - '0');
        }
        return res;
    }
    
    long posIntSol(string s)
    {
        int n = 0;
        int r = 0;
        for(int ind=0; ind<s.length(); ind++){
            if(s[ind] == '+')
                ++r;
            if(s[ind] == '='){
                n = getNum(s.substr(ind+1, s.length()))-1;
                break;
            }
        }
        // cout<<r<<' '<<n<<endl;
        if(r > n)
            return 0;
        else{
            long num = 1;
            for(int val = n-r+1; val<=n; val++)
                num *= val;
            long den = fact(r);
            return num/den;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends