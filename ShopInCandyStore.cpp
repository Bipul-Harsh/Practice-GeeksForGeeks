// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies, candies+N);
        int candiesBought=0;
        int minPrice=0, maxPrice=0;
        int minInd=0, maxInd=N-1;
        vector<int>ans;
        while(candiesBought<N){
            candiesBought+=(K+1);
            minPrice += candies[minInd++];
            maxPrice += candies[maxInd--];
        }
        ans.push_back(minPrice);
        ans.push_back(maxPrice);
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
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends