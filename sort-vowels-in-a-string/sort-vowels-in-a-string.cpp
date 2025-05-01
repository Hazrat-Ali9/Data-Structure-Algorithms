class Solution {
public:
    bool isVowel(char &c){
        return (c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    string sortVowels(string s) {
        vector<char> v;
        for(int i=0; i<s.size(); i++){
            if(isVowel(s[i])) v.push_back(s[i]);
        }
        sort(v.begin(), v.end());
        for(int i=0, j=0; i<s.size(); i++){
            if(isVowel(s[i])) s[i] = v[j++];
        }
        return s;
    }
};