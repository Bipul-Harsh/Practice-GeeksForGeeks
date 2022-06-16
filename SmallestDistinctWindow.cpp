// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here 
        int left = 0;
        int right = 0;
        int len = str.length();
        int totalUniqueCount = 0;
        int smallest = len;
        unordered_map<char, int>count;
        
        for(int ind=0; ind<len; ind++)
            if(!count[str[ind]]){
                ++totalUniqueCount;
                ++count[str[ind]];
            }
        

        int uniqueCount=0;
        count = {};
        for(int ind=0; ind<len; ind++){
            if(!count[str[ind]])
                uniqueCount++;
            
            if(uniqueCount==totalUniqueCount){
                right = ind;
                break;
            }
            count[str[ind]]++;
        }
        int currLen = right;
        for(int ind=right; ind<len; ind++){
            ++count[str[ind]];
            ++currLen;
            while(count[str[left]] > 1){
                --count[str[left++]];
                --currLen;
            }
            if(currLen < smallest)
                smallest = currLen;
        }
        return smallest;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends