//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        vector<int> ans;
        for(int i=0; i<query.size(); i++){
            ans.push_back(solve(query[i]));
        }
        return ans;
    }
    int solve(long long int n){
        n = sqrt(n);
        bool prime[n+1];
        memset(prime, true, sizeof(prime));
        for(int i=2; i*i<=n; i++){
            if(prime[i]==true){
                for(int j=i*i; j<=n; j=j+i){
                    prime[j] = false;
                }
            }
        }
        int cnt = 0;
        for(int i=2; i<=n; i++){
            if(prime[i]) cnt++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends