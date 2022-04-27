// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    long long int killinSpree(long long int n)
    {
        // Code Here
        long long int start=0, end=sqrt(n)+1, mid, strengthCombined;
        while (start <= end) {
            mid = start + (end - start) / 2;
            strengthCombined = mid * (mid + 1) * (2 * mid + 1) / 6;

            if (n == strengthCombined) 
                return mid;
            else if (n > strengthCombined)
                start = mid + 1;
            else 
                end = mid - 1;
        }
        return end;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n; cin>>n;
        Solution obj;
        long long int ans = obj.killinSpree(n);
        cout<<ans<<"\n";
    }
    return 0;
}
  // } Driver Code Ends