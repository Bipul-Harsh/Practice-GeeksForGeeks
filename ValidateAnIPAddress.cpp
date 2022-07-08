// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int toDigit(char ch){
            return ch - '0';
        }
        int isValid(string s) {
            // code here
            int cnt=0;
            int val = -1;
            for(int ind = 0; ind<s.size(); ind++){
                if(s[ind] >= '0' && s[ind] <= '9'){
                    if(val==0)
                        return 0;
                    if(val == -1)
                        val = toDigit(s[ind]);
                    else
                        val = val*10 + toDigit(s[ind]);
                } else if(s[ind] == '.'){
                    if(val < 0 || val > 255)
                        return 0;
                    else{
                        val = -1;
                        ++cnt;
                    }
                }
                else
                    return 0;
            }
            if(val > -1){
                if(val > 255){
                    return 0;
                }
                cnt++;
            }
            if(cnt == 4 && s[s.length()-1]!='.')
                return 1;
            return 0;
        }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}  // } Driver Code Ends