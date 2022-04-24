// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPrime(long long num){
        for(int val=2; val<=sqrt(num); val++)
            if(num%val==0)
                return false;
        return true;
    }
    long long primeProduct(long long L, long long R){
        // code here
        long long ans=1;
        for(int num=L; num<=R; num++)
            if(isPrime(num)){
                ans = (ans*num)%1000000007;
            }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}  // } Driver Code Ends