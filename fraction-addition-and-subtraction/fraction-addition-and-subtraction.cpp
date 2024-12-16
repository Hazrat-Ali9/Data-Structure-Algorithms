class Solution {
public:
    string fractionAddition(string expression) {
        int num=0, denom = 1, i=0;
        while(i < expression.size()){
            int currNum = 0, currDenom = 0;
            bool isNegative = false;
            //Check for sign
            if(expression[i] == '-' || expression[i] == '+'){
                if(expression[i] == '-') isNegative = true;
                //Move to next char
                i++;
            }
            //Build numerator
            while(isdigit(expression[i])){
                int val = expression[i] - '0';
                currNum = currNum * 10 + val;
                i++;
            }
            if(isNegative) currNum *= -1;
            //skip divisor
            i++;
            //Build denominator
            while(i<expression.size() && isdigit(expression[i])){
                int val = expression[i] - '0';
                currDenom = currDenom*10 + val;
                i++;
            }
            //add fraction together
            num = num * currDenom + currNum * denom;
            denom = denom * currDenom;
        }
        int gcd = abs(__gcd(num, denom));
        //reduce fractions
        num /= gcd;
        denom /= gcd;
        return to_string(num) + "/" + to_string(denom);
    }
};