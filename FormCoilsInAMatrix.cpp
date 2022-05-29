// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    inline bool isValid(int r, int c, int size){
        if(r<0 || c<0 || r>=size || c>=size)
            return false;
        else
            return true;
    }
    int val(int r, int c, int size){
        return r*size+c+1;
    }
    vector<vector<int>> formCoils(int n) {
        
        // code here
        vector<vector<int>>ans={{},{}};
        int r,c,size,dist,vdir,hdir;
        
        size = n*4;
        
        // first coil
        r = size/2;
        c = size/2-1;
        dist = 2;
        vdir = -1;
        hdir = 1;
        ans[0].push_back(val(r, c, size));
        while(isValid(r, c, size)){
            for(int itr=0; itr<dist; itr++){
                r += vdir;
                if(isValid(r, c, size))
                    ans[0].push_back(val(r, c, size));
                else
                    break;
            }
            
            for(int itr=0; itr<dist; itr++){
                c += hdir;
                if(isValid(r, c, size))
                    ans[0].push_back(val(r, c, size));
                else
                    break;
            }
            
            hdir *= -1;
            vdir *= -1;
            dist += 2;
        }
        
        // second coil
        r = size/2-1;
        c = size/2;
        dist = 2;
        vdir = 1;
        hdir = -1;
        ans[1].push_back(val(r, c, size));
        while(isValid(r, c, size)){
            for(int itr=0; itr<dist; itr++){
                r += vdir;
                if(isValid(r, c, size))
                    ans[1].push_back(val(r, c, size));
                else
                    break;
            }
            
            for(int itr=0; itr<dist; itr++){
                c += hdir;
                if(isValid(r, c, size))
                    ans[1].push_back(val(r, c, size));
                else
                    break;
            }
            
            hdir *= -1;
            vdir *= -1;
            dist += 2;
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        vector<vector<int>> ptr = ob.formCoils(n);
        
        for(auto it: ptr)
        {
            for(int i: it)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends