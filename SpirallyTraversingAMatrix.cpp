// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int>ans;
        int left=0, right=c-1, top=0, bottom=r-1;
        while(left<=right && top<=bottom){

            for(int ind = left; ind <= right; ind++)
                ans.push_back(matrix[top][ind]);
            
            for(int ind = top+1; ind <= bottom; ind++)
                ans.push_back(matrix[ind][right]);
            
            for(int ind = right-1; ind >= left; ind--)
                ans.push_back(matrix[bottom][ind]);
            
            for(int ind = bottom-1; ind > top; ind--)
                ans.push_back(matrix[ind][left]);
                
            
            left++;right--;top++;bottom--;
        }
        
        vector<int>sliced = {ans.begin(), ans.begin()+r*c};
        return sliced;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
