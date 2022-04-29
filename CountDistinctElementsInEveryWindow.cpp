// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        vector<int>ans;
        unordered_map<int, int>record;
        int distinctElement = 0;
        for(int ind=0; ind<k; ind++){
            if(!record[A[ind]]){
                distinctElement++;
            }
            record[A[ind]]++;
        }
        ans.push_back(distinctElement);
        for(int ind=k; ind<n; ind++){
            if(--record[A[ind-k]]==0)
                distinctElement--;
            if(record[A[ind]]==0)
                distinctElement++;
            record[A[ind]]++;
            ans.push_back(distinctElement);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends