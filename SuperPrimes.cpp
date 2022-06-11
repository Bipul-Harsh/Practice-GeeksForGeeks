// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int superPrimes(int n)
	{
	    // As all prime numbers are odd beside 2
	   //So adding them up will give even numbers which are not prime
	   //So we basically need to check if prime + 2 gives prime or not
	    
		//For Super Primes
		vector<bool>primeRecord(n+1, true);
	    primeRecord[0]=false;
	    primeRecord[1]=false;
	    for(int val=2; val*val<n; val++){
            if(primeRecord[val]){
                for(int nonPrime=val*val; nonPrime<=n; nonPrime+=val)
                    primeRecord[nonPrime]=false;
            }
        }
	    int spCount=0;
	    for(int val=5; val<=n; val++){
	         //means if adding 2 to val-2 gives prime?
	        if(primeRecord[val] && primeRecord[val-2])
	            spCount++;
	    }
	    return spCount;
	}
};

// { Driver Code Starts.

int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
   		Solution ob;
   		cout << ob.superPrimes(n) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends
