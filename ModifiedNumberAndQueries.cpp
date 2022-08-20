//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
int primefactors_sum(int n)

{
    vector<int>v;
    if(n%2 == 0){
        v.push_back(2);
        while(n%2 == 0)
            n/=2;
    }
    for(int i=3;i<=sqrt(n);i=i+2)
    {
        if(n%i == 0){
            v.push_back(i);
            while(n%i == 0)
                n/=i;
        }
    }
    if(n>2)
    v.push_back(n);
    return accumulate(v.begin(),v.end(),0);
}
class Solution {
  public:
    int sumOfAll(int l, int r)
    {
        vector<int>v;
       for(int i=l;i<=r;i++){
           if(i==1)
            v.push_back(1);
         else
          v.push_back(primefactors_sum(i));
       }
       return accumulate(v.begin(),v.end(),0);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin>>l>>r;
        Solution ob;
        cout<<ob.sumOfAll(l,r)<<endl;
    }
    return 0;
}

// } Driver Code Ends