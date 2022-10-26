//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    bool isLower(char ch){
        int lowerStart = 'a';
        int lowerEnd = lowerStart + 25;
        if(ch >= lowerStart && ch <= lowerEnd)
            return true;
        return false;
    }
    string caseSort(string str, int n)
    {
        // your code here
        vector<char>lowerChars;
        vector<char>upperChars;
        for(auto chr : str){
            if(isLower(chr))
                lowerChars.push_back(chr);
            else
                upperChars.push_back(chr);
        }
        
        sort(lowerChars.begin(), lowerChars.end());
        sort(upperChars.begin(), upperChars.end());
        
        string res = "";
        int ind1 = 0;
        int ind2 = 0;
        for(auto chr : str){
            if(isLower(chr))
                res += lowerChars[ind1++];
            else
                res += upperChars[ind2++];
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends