// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> permute(vector<vector<int>> &arr, int n);


int main() {
    
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> arr(n);
        
        for(int i=0;i<n;i++)
        {
            int a, b;
            cin>> a>> b;
            arr[i].push_back(a);
            arr[i].push_back(b);
        }
        
        vector<int> ans;
        ans = permute(arr, n);
        for(int i=0;i<n;i++)
            cout << ans[i] << "\n";
        
    }
    
	return 0;
}// } Driver Code Ends


bool check(pair<int, int>p1, pair<int, int>p2)
{
    if(p1.first<p2.first)
    {
        return true;
    }
    else if(p1.first==p2.first && p1.second<p2.second)
    {
        return true;
    }else
    {
        return false;
    }
}

vector<int> permute(vector<vector<int>> &arr, int n)
{
    
    // Complete the function
    vector<pair<int, int>>record;
    vector<int>ans;
    pair<int, int>info;
    for(int ind=0; ind<n; ind++){
        info.first = arr[ind][0]+arr[ind][1];
        info.second = ind+1;
        record.push_back(info);
    }
    sort(record.begin(), record.end(), check);
    for(int ind=0; ind<n; ind++){
        ans.push_back(record[ind].second);
    }
    return ans;
}