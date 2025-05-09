class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freqMp;
        for(char &c : word) freqMp[c]++;
        priority_queue<int> freqQueue;
        for(auto x : freqMp) freqQueue.push(x.second);
        int cnt = 0, i = 0;
        while(!freqQueue.empty()){
            cnt += (1 + (i/8)) * freqQueue.top();
            freqQueue.pop();
            i++;
        }
        return cnt;
    }
};