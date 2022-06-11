// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    long long countKdivPairs(int A[], int n, int K)
    {
        //code here
        long long pairCount = 0;
        vector<long>rec(K, 0);
        
        for(int ind=0; ind<n; ind++){
            rec[A[ind]%K]++;
        }
        
        pairCount += (rec[0] * (rec[0] - 1)) / 2;
        if(K%2 == 0){
            pairCount += (rec[K/2] * (rec[K/2] - 1)) / 2;
        
            for(int val = 1; val < K/2; val++){
                pairCount += rec[val] * rec[K-val];
            }
        } else {
            for(int val = 1; val <= K/2; val++){
                pairCount += rec[val] * rec[K-val];
            }            
        }
        
        return pairCount;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends
