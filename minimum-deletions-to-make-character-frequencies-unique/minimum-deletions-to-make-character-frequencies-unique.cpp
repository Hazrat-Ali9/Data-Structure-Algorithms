class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp;
        for(char c : s) mp[c]++;
        priority_queue<int> pq;
        for(auto x : mp) pq.push(x.second);
        int ans=0;
        while(pq.size() != 1){
            int top = pq.top(); pq.pop();
            if(top==pq.top() && top != 0){
                ans++;
                pq.push(top-1);
            }
        }
        return ans;
    }
};