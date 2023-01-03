//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    string roundToNearest(string N) 
    { 
        // Complete the function
        int l = N.length();
        if((N[l-1] - '0') > 5){
            int ind=l-2;
            for(ind; ind>=0 && N[ind]=='9'; ind--){
                N[ind] = '0';
            }
            if(ind < 0)
                N = "1"+N;
            else
                N[ind] += 1;
        }
        l = N.length();
        N[l-1] = '0';
        return N;
    }  

};

//{ Driver Code Starts.

int main() {
    
    int t;cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout << ob.roundToNearest(s) << endl;
    }
    
	return 0;
}
// } Driver Code Ends