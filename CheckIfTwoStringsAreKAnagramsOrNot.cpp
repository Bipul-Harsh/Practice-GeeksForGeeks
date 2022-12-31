//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    bool areKAnagrams(string str1, string str2, int k) {
        // code here
        if(str1.length() != str2.length())
            return false;
            
        unordered_map<char, int>cc;
        for(auto ch : str1){
            ++cc[ch];
        }
        
        int chTC = 0;
        for(auto ch : str2){
            if(--cc[ch] < 0){
                ++chTC;
            }
        }
        if(chTC > k)
            return false;
        
        return true;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int k;
		cin>>k;
		Solution ob;
		if(ob.areKAnagrams(str1, str2, k) == true)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
}
// } Driver Code Ends