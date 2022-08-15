//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
        vector<int> common_element(vector<int>v1,vector<int>v2)
    {
        // Your code here
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        vector<int>ans;
        
        int ind1=0, ind2=0;
        int v1l=v1.size(), v2l=v2.size();
        while(ind1 < v1l && ind2 < v2l){
            if(v1[ind1] == v2[ind2]){
                ans.push_back(v1[ind1]);
                ++ind1;
                ++ind2;
            }
            while(ind1 < v1l && v1[ind1] < v2[ind2]){
                ++ind1;
            }
            while(ind2 < v2l && v2[ind2] < v1[ind1]){
                ++ind2;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int>v1(n,0);
        for(int i=0;i<n;i++)
        {
            cin>>v1[i];
        }
        int m;
        cin>>m;
        vector<int>v2(m,0);
        for(int i=0;i<m;i++)
        {
            cin>>v2[i];
        }
        Solution ob;
        vector<int>result;
        result=ob.common_element(v1,v2);
        for(auto i:result)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        
    }
}
// } Driver Code Ends