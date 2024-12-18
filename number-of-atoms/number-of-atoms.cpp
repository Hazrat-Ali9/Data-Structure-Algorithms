class Solution {
public:
    string countOfAtoms(string formula) {
        // Stack to keep track of the atoms and their counts
        stack<unordered_map<string, int>> stack;
        stack.push(unordered_map<string, int>());

        // Index to keep track of the current character
        int index = 0;

        // Parse the formula
        while (index < formula.length()) {
            // If left parenthesis, insert a new hashmap to the stack. It will
            // keep track of the atoms and their counts in the nested formula
            if (formula[index] == '(') {
                stack.push(unordered_map<string, int>());
                index++;
            }

            // If right parenthesis, pop the top element from the stack
            // Multiply the count with the multiplicity of the nested formula
            else if (formula[index] == ')') {
                unordered_map<string, int> currMap = stack.top();
                stack.pop();
                index++;
                string multiplier;
                while (index < formula.length() && isdigit(formula[index])) {
                    multiplier += formula[index];
                    index++;
                }
                if (!multiplier.empty()) {
                    int mult = stoi(multiplier);
                    for (auto& [atom, count] : currMap) {
                        currMap[atom] = count * mult;
                    }
                }

                for (auto& [atom, count] : currMap) {
                    stack.top()[atom] += count;
                }
            }

            // Otherwise, it must be a UPPERCASE LETTER. Extract the complete
            // atom with frequency, and update the most recent hashmap
            else {
                string currAtom;
                currAtom += formula[index];
                index++;
                while (index < formula.length() && islower(formula[index])) {
                    currAtom += formula[index];
                    index++;
                }

                string currCount;
                while (index < formula.length() && isdigit(formula[index])) {
                    currCount += formula[index];
                    index++;
                }

                int count = currCount.empty() ? 1 : stoi(currCount);
                stack.top()[currAtom] += count;
            }
        }

        // Sort the final map
        map<string, int> finalMap(stack.top().begin(), stack.top().end());

        // Generate the answer string
        string ans;
        for (auto& [atom, count] : finalMap) {
            ans += atom;
            if (count > 1) {
                ans += to_string(count);
            }
        }

        return ans;
    }
};