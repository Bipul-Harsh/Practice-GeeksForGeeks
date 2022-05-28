// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int shortestPath( int x, int y){ 
        // code here 
        vector<int> x_ancestors = {x};
        vector<int> y_ancestors = {y};
        int temp;
        
        temp = x;
        while(temp){
            temp/=2;
            x_ancestors.push_back(temp);
        }
        
        temp = y;
        while(temp){
            temp/=2;
            y_ancestors.push_back(temp);
        }
        
        int xs = x_ancestors.size();
        int ys = y_ancestors.size();
        int m = min(xs, ys);
        int ind=0;
        for(; ind<m; ind++){
            if(x_ancestors[xs-ind-1] != y_ancestors[ys-ind-1])
                break;
        }
        
        return (xs-ind)+(ys-ind);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<< ob.shortestPath(x,y) << endl;
    }
    return 0; 
}   // } Driver Code Ends