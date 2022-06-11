// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    // your code here
    int cnt = 0;
    int maxCnt = 0;
    vector<int>chInd(26, -1);
    int start=0;
    for(int i=0; i < S.length(); i++){
        int chInt = S[i] - 'a';
        
        if(chInd[chInt] == -1 || chInd[chInt] < start){
            chInd[chInt] = i;
            ++cnt;
        } else {
            if(cnt > maxCnt)
                maxCnt = cnt;
            cnt = i - chInd[chInt];
            start = chInd[chInt]+1;
            chInd[chInt] = i;
        }
    }
    return max(cnt, maxCnt);
}