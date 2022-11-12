//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int shortestDistance(vector<string> &s, string word1, string word2)
	{
		// Your code goes here
		if(word1 == word2)
		    return 0;
		
		int ind1 = -1;
		int ind2 = -1;
		int ans = INT_MAX;
		for(int ind=0; ind<s.size(); ind++){
		    string word = s[ind];
		    if(word == word1){
		        if(ind2 != -1)
		            ans = min(ans, abs(ind - ind2));
		        ind1 = ind;
		    } else if(word == word2){
		        if(ind1 != -1)
		            ans = min(ans, abs(ind - ind1));
		        ind2 = ind;
		    }
		}
		
		return ans;
	}
};

//{ Driver Code Starts.

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

   		vector<string> s(n);
   		for(int i = 0; i < n; i++)
   			cin >> s[i];

   		string word1, word2;

   		cin >> word1 >> word2;
   		
   		Solution ob;

   		cout << ob.shortestDistance(s, word1, word2) << "\n";
   	}

    return 0;
}
// } Driver Code Ends