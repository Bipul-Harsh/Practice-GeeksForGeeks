// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:

    vector<string> permutation(string S){
        // Code Here
        vector<string>res;
        string str;
        res.push_back(str+S.at(0));
        for(int i=1; i<S.length(); i++){
            for(int j=0; j<res.size(); j+=2){
                str = res[j];
                res[j] = str + " " + S[i];
                res.insert(res.begin()+j+1, str + S[i]);
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends