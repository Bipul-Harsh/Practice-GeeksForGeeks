//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<int>ans;
        int jobDone = 0;
        int totalProfit = 0;
        vector<bool>slotAvailable(n, true);
        
        sort(arr, arr+n, [](Job j1, Job j2){
            if(j1.profit < j2.profit)
                return false;
            if(j1.profit > j2.profit)
                return true;
            return j1.dead < j2.dead;
        });
        
        for(int ind=0; ind<n; ind++){
            int slot = arr[ind].dead-1;
            if(slot >= n)
                slot = n-1;
            while(slot >= 0){
                if(slotAvailable[slot]){
                    slotAvailable[slot] = false;
                    ++jobDone;
                    totalProfit += arr[ind].profit;
                    break;
                }
                slot--;
            }
        }
        
        // for(int ind=0; ind<n; ind++){
        //     cout<<arr[ind].id<<' '<<arr[ind].dead<<' '<<arr[ind].profit<<endl;
        // }
        
        ans = {jobDone, totalProfit};
        
        return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends