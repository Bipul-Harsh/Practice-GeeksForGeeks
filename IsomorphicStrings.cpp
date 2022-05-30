// { Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        // Your code here
        if(str1.length() != str2.length())
            return false;
        
        vector<int>map1(26, -1);
        vector<int>map2(26, -1);
        for(int ind=0; ind<str1.length(); ind++){
            int val1 = str1[ind]-'a';
            int val2 = str2[ind]-'a';
            if( map1[val1] == -1 ){
                if( map2[val2] != -1 )
                    return false;
                else{
                    map1[val1] = val2;
                    map2[val2] = val1;
                }
            }
            else if( map1[val1] != val2 || map2[val2] != val1)
                return false;
        }
        return true;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends