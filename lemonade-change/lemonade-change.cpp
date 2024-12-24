class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // Count of $5 and $10 bills in hand
        int fiveDollarBills = 0;
        int tenDollarBills = 0;

        // Iterate through each customer's bill
        for (int customerBill : bills) {
            if (customerBill == 5) {
                // Just add it to our count
                fiveDollarBills++;
            } else if (customerBill == 10) {
                // We need to give $5 change
                if (fiveDollarBills > 0) {
                    fiveDollarBills--;
                    tenDollarBills++;
                } else {
                    // Can't provide change, return false
                    return false;
                }
            } else {  // customerBill == 20
                // We need to give $15 change
                if (tenDollarBills > 0 && fiveDollarBills > 0) {
                    // Give change as one $10 and one $5
                    fiveDollarBills--;
                    tenDollarBills--;
                } else if (fiveDollarBills >= 3) {
                    // Give change as three $5
                    fiveDollarBills -= 3;
                } else {
                    // Can't provide change, return false
                    return false;
                }
            }
        }
        // If we've made it through all customers, return true
        return true;
    }
};