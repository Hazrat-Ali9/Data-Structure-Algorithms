class Solution {
public:
    static bool comp(pair<int, int> &a, pair<int, int> &b){
        return a.second > b.second;
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> vp;
        for(int i=0; i<nums1.size(); i++){
            vp.push_back({nums1[i], nums2[i]});
        }
        sort(vp.begin(), vp.end(), comp);
        priority_queue<int, vector<int>, greater<>> pq;
        long long sum = 0;
        for(int i=0; i<k; i++){
            sum += vp[i].first;
            pq.push(vp[i].first);
        }
        long long ans = sum * vp[k-1].second;
        for(int i=k; i<nums1.size(); i++){
            sum += vp[i].first - pq.top(); pq.pop();
            pq.push(vp[i].first);
            ans = max(ans, sum*vp[i].second);
        }
        return ans;
    }
};