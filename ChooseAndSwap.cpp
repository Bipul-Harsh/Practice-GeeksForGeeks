//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        // Code Here
        vector<int>charPresent(26, 0);
        for(int ind=0; ind<a.length(); ind++){
            int chInt = a[ind] - 'a';
            charPresent[chInt] = 1;
        }
        
        int pos=0;
        int al = a.length();
        char repMin, repMax;
        for(int ind=0; ind<26; ind++){
            char ch = 'a'+ind;;
            if(charPresent[ind]){
                if(a[pos] <= ch){
                    pos++;
                    while(pos < al && a[pos] <= ch)
                        pos++;
                } else if(ch < a[pos]) {
                    repMin = ch;
                    repMax = a[pos];
                    break;
                }
            }
            if(pos == al)
                break;
        }
        if(repMin && repMax)
            for(int ind=0; ind<al; ind++){
                if(a[ind] == repMin){
                    a[ind] = repMax;
                }
                else if(a[ind] == repMax)
                    a[ind] = repMin;
            }
        
        return a;
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}

// } Driver Code Ends