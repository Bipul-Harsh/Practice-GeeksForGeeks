//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        stack<int>st, temp;
        vector<int>ans;
        
        for(int ind=0; ind<N; ind++){
            if(st.size() == 0){
                if(asteroids[ind] < 0)
                    ans.push_back(asteroids[ind]);
                else
                    st.push(asteroids[ind]);
            } else {
                if(asteroids[ind] > 0)
                    st.push(asteroids[ind]);
                else{
                    while(st.size() > 0 && st.top() < abs(asteroids[ind]))
                        st.pop();
                    if(!st.size())
                        ans.push_back(asteroids[ind]);
                    else if(st.top() == abs(asteroids[ind]))
                        st.pop();
                }
            }
        }
        while(st.size()){
            temp.push(st.top());
            st.pop();
        }
        
        while(temp.size()){
            ans.push_back(temp.top());
            temp.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends