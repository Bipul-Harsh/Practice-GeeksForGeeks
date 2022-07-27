//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
int MinimumExchange(vector<vector<char>>matrix){
    // Code here
    // checking for ABAB pattern
    int swpChr = 0;
    int wrongCharAB = 0;
    for(int r=0; r<matrix.size(); r++){
        for(int c=0; c<matrix[0].size(); c++){
            if(matrix[r][c] != 'A'+swpChr)
                wrongCharAB++;
            swpChr = !swpChr;
        }
        if(matrix[0].size()%2 == 0)
            swpChr = !swpChr;
    }
    
    swpChr = 1;
    int wrongCharBA = 0;
    for(int r=0; r<matrix.size(); r++){
        for(int c=0; c<matrix[0].size(); c++){
            if(matrix[r][c] != 'A'+swpChr)
                wrongCharBA++;
            swpChr = !swpChr;
        }
        if(matrix[0].size()%2 == 0)
            swpChr = !swpChr;
    }
    
    if(wrongCharBA%2 == 0)
        wrongCharBA /= 2;
    if(wrongCharAB%2 == 0)
        wrongCharAB /= 2;
    return min(wrongCharBA, wrongCharAB);
}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>matrix(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MinimumExchange(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends