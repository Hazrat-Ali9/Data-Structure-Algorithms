class Solution {
public:
    bool parseBoolExpr(string expression) {
        int index = 0;
        return evaluate(expression, index);
    }

private:
    // Recursively parse and evaluate the boolean expression
    bool evaluate(string& expr, int& index) {
        char currChar = expr[index++];

        // Base cases: true ('t') or false ('f')
        if (currChar == 't') return true;
        if (currChar == 'f') return false;

        // Handle NOT operation '!(...)'
        if (currChar == '!') {
            index++;  // Skip '('
            bool result = !evaluate(expr, index);
            index++;  // Skip ')'
            return result;
        }

        // Handle AND '&(...)' and OR '|(...)'
        vector<bool> values;
        index++;  // Skip '('
        while (expr[index] != ')') {
            if (expr[index] != ',') {
                values.push_back(evaluate(
                    expr, index));  // Collect results of subexpressions
            } else {
                index++;  // Skip commas
            }
        }
        index++;  // Skip ')'

        // Manual AND operation: returns false if any value is false
        if (currChar == '&') {
            for (bool v : values) {
                if (!v) return false;
            }
            return true;
        }

        // Manual OR operation: returns true if any value is true
        if (currChar == '|') {
            for (bool v : values) {
                if (v) return true;
            }
            return false;
        }

        return false;  // This point should never be reached
    }
};