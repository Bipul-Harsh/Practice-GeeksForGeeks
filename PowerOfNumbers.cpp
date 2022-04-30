// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007

 // } Driver Code Ends
class Solution{
    public:
    //You need to complete this fucntion
    
    long long power(int N,int R)
    {
       //Your code here
        long long int ans=N;
        unordered_map<int, int>store;
        int power=1;
        while(power*2<=R){
            store[power]=ans;
            ans = (ans*ans)%1000000007;
            power*=2;
        }
        int ind=power;
        R-=ind;
        while(R){
            int getInd;
            for(getInd=ind;getInd>R;getInd/=2);
            R-=getInd;
            ans = (ans*store[getInd])%1000000007;
        }
        return ans;    
    }

};

// { Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}  // } Driver Code Ends