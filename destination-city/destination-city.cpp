class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> s;
        for(int i=0; i<paths.size(); i++){
            s.insert(paths[i][0]);
        }
        for(int i=0; i<paths.size(); i++){
            string candi = paths[i][1];
            if(s.find(candi) == s.end()) return candi;
        }
        return "";
    }
};