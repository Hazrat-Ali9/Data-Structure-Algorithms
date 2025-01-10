class Solution {
public:
    int getLucky(string s, int k) {
        int num = 0;
        for(char c : s){
            int pos = c-'a'+1;
            while(pos > 0){
                num += pos%10;
                pos /= 10;
            }
        }
        for(int i=1; i<k; i++){
            int digitSum = 0;
            while(num > 0){
                digitSum += num%10;
                num /= 10;
            }
            num = digitSum;
        }
        return num;
    }
};