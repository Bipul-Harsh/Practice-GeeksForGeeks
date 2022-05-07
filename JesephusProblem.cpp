// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
    int josephus(int n, int k)
    {
       //Your code here
       if(k==1)
        return n;
       vector<bool>person(n, true);
       int tk;
       int start=0;
       int rem=n;
       for(int itr=n; itr>1; itr--){
           tk = (k-1)%itr;
           while(tk){
               start = (start+1)%n;
               if(person[start])
                  tk--;
           }
           person[start]=false;
           while(!person[start])
            start = (start+1)%n;
       }
       return start+1;
    }
};



// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends