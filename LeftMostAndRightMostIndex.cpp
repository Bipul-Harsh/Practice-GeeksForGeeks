//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        pair<long, long>res = {-1, -1};
        int len = v.size();
        int start = 0, end = len-1;
        int middle;
        
        while(start <= end){
            middle = start + (end - start)/2;
            if(v[middle] == x){
               if(res.first == -1){
                    if(middle-1 >= 0 && v[middle - 1] == x){
                        end = middle-1;
                    } else {
                        res.first = middle;
                        start = middle;
                        end = len;
                    }
               } else {
                   if(middle+1 < len && v[middle + 1] == x){
                        start = middle+1;
                    } else {
                        res.second = middle;
                        break;
                    }
               }
            } else if(v[middle] < x){
                start = middle+1;
            } else {
                end = middle - 1;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends