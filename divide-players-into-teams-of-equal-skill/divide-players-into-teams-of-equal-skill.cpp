class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size(), totalSkill = 0;
        vector<int> skillFreq(1001,0);
        // Calculate total skill and skill frequency
        for(int x : skill){
            totalSkill += x;
            skillFreq[x]++;
        }
        // Check if total skill can be evenly distributed among teams
        if(totalSkill%(n/2) != 0) return -1;
        int targetTeamSkill = totalSkill/(n/2);
        long long totalChemistry = 0;
        // Calculate total chemistry while verifying valid team formations
        for(int x : skill){
            int partnerSkill = targetTeamSkill - x;
            // Check if a valid partner exists
            if(skillFreq[partnerSkill] == 0) return -1;
            totalChemistry += (long long)x * (long long)partnerSkill;
            skillFreq[partnerSkill]--;
        }
        // Return half of totalChemistry as each pair is counted twice
        return totalChemistry/2;
    }
    // Divide players into teams of equals skill
};