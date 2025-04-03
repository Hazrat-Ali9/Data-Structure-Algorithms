class Solution {
    public int bestClosingTime(String customers) {
        int currPenalty = 0, minPenalty = 0, earliestHour = 0;
        for(int i=0; i<customers.length(); i++){
            char c = customers.charAt(i);
            if(c == 'Y') currPenalty--;
            else currPenalty++;
            if(currPenalty < minPenalty){
                minPenalty = currPenalty;
                earliestHour = i+1;
            }
        }
        return earliestHour;
    }
}