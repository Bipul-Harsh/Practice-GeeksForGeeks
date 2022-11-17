//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        // code here 
        int swaps = 0, c = 0, o = 0, uc = 0;
        
        for(auto ch : S){
            if(ch == ']'){
                ++c;
            } else {
                ++o;
                if(uc > 0){
                    swaps += uc;
                }
            }
            
            uc = c - o;
        }
        return swaps;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
} 
// } Driver Code Ends