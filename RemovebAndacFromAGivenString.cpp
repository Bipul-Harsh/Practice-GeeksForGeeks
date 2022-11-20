//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
  public:
    string stringFilter(string str) 
    { 
        //code here.
        string ans;
        for(int ind=0; ind<str.length(); ind++){
            if(str[ind] == 'a' && ind+1 <str.length() && str[ind+1] == 'c'){
                ++ind;
            }else if(str[ind] != 'b'){
                ans += str[ind];
            }
        }
        
        return ans;
    } 
};

//{ Driver Code Starts.

int main() 
{
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;
   		
   		Solution ob;
   		cout <<ob.stringFilter(s) << "\n";

   		
   	}

    return 0;
}
// } Driver Code Ends