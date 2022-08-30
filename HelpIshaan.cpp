//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    bool isPrime(int val){
	        for(int d=2; d<=sqrt(val); d++)
	            if(val%d == 0)
	                return false;
	        return true;
	    }
		int NthTerm(int N){
		    // Code here
		    if(N == 1)
		        return 1;
		    if(isPrime(N))
		        return 0;
		    int lPrime, rPrime;
		    for(int val=N-1; val>1; val--)
		        if(isPrime(val)){
		            lPrime = val;
		            break;
		        }
		    for(int val=N+1; val<2*N; val++)
		        if(isPrime(val)){
		            rPrime = val;
		            break;
		        }

		    return min(abs(N - lPrime), abs(N - rPrime));
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		int ans = obj.NthTerm(N);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends