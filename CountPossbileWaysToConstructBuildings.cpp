// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	   long long int ans = 0;
	   long long int a = 0, b = 1;
	   long long int mod = 1e9+7;
	   for(int itr=0; itr<=N; itr++){
	       long long int c = (a+b) % mod;
	       a = b;
	       b = c;
	       ans = c;
	   }
	   ans = (ans*ans)%mod;
	   return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends