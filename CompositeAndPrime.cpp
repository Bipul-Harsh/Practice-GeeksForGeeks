//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define MVAL 10e5+1
class Solution {
	public:
	    
		int Count(int L, int R){
		    // Code here
		    vector<bool>isPrime(R+1, true);
		    isPrime[0] = false; isPrime[1] = false;
		    for (int i = 2; i <= R; i++)	{
        		if(isPrime[i]){
        			for (int j = 2; i*j <= R; j++)	{
        				isPrime[i*j] = false;
        			}
        		}
        	}
		    
		    
		    int primeCount = 0;
		    int compositeCount = 0;
		    for(int val=L; val<=R; val++){
		        if(val == 0 || val == 1)
		            continue;
		        if(isPrime[val])
		            primeCount++;
		        else
		            compositeCount++;
		    }
		    
		  //  cout<<primeCount<<' '<<compositeCount<<endl;
		    return compositeCount - primeCount;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int L, R;
		cin >> L >> R;
		Solution obj;
		int ans = obj.Count(L, R);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends