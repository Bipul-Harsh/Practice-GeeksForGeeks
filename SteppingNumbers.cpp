//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    int dfs(int n , int no){
        if (n < 0)
        return 0;
    
        if (no > n)
        return 0;
        
        int op = 1;
        
        for (int i = 0 ; i <= 9 ; i++){
           int dig = no%10;
           if (abs(dig-i) == 1 or (no == 0 and i != 0)){
               op = op + dfs(n , (no*10 + i));
           }
        }
        
        return op;
    }

    int steppingNumbers(int n, int m)
    {
       return dfs(m , 0) - dfs(n-1 , 0);
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends