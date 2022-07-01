// { Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        unordered_map<string, int>countVote;
        vector<string>ans;
        int maxCount = 0;
        for(int ind=0; ind<n; ind++){
            countVote[arr[ind]]++;
            if(countVote[arr[ind]] > maxCount){
                ans = {arr[ind]};
                maxCount = countVote[arr[ind]];
            }
            else if(countVote[arr[ind]] == maxCount)
                ans.push_back(arr[ind]);
        }
        if(ans.size() > 1){
            string lexSmaller = ans[0];
            for(int ind=1; ind<ans.size(); ind++){
                if(ans[ind] < lexSmaller)
                    lexSmaller = ans[ind];
            }
            ans = {lexSmaller};
        }
        int count = 0;
        for(int ind=0; ind<n; ind++){
            if(arr[ind] == ans[0])
                count++;
        }
        ans.push_back(to_string(count));
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}
  // } Driver Code Ends