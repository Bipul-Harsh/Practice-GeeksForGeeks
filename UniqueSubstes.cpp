// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    static bool compare(vector<int>a1, vector<int>a2){
        int i=0;
        while(i<a1.size() && i<a2.size()){
            if(a1[i]<a2[i])
                return true;
            if(a1[i]>a2[i])
                return false;
            i++;
        }
        if(a1.size()<=a2.size())
            return true;
        return false;
    }    
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        sort(arr.begin(), arr.end());
        vector<vector<int>>result;
        vector<int>res;
        result.push_back(res);
        int ind=0;
        while(ind<n){
            vector<int>elem = {arr[ind]}; //elem
            vector<vector<int>>toMerge;  //toMerge
            toMerge.push_back(elem);
            while((ind+1)<n && arr[ind+1]==arr[ind]){
                elem.push_back(arr[ind]);
                toMerge.push_back(elem);
                ind++;
            }
            int rn = result.size();
            for(int ind=0; ind<toMerge.size(); ind++){
                for(int sind=1; sind<rn; sind++){
                    vector<int>merged(toMerge[ind].size()+result[sind].size());
                    merge(result[sind].begin(),result[sind].end(),toMerge[ind].begin(),toMerge[ind].end(),merged.begin());
                    result.push_back(merged);
                }
            }
            for(int ind=0; ind<toMerge.size(); ind++)
                result.push_back(toMerge[ind]);
            ind++;
        }
        sort(result.begin(), result.end(), compare);
        return result;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends