//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
        // code here
        vector<int> alphaCount(26, 0);
        for(int ind=0; ind<arr.length(); ind++){
            ++alphaCount[arr[ind] - 'a'];
        }
        
        string ans = "";
        for(int ind=0; ind<26; ind++){
            for(int cnt=0; cnt<alphaCount[ind]; cnt++){
                ans += 'a'+ind;
            }    
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    }
    return 0;
}

// } Driver Code Ends