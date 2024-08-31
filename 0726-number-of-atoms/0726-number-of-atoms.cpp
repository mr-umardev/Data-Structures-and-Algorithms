class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> elementCount;
    stack<map<string, int>> elementStack;
    elementStack.push({});
    int n = formula.size();
    
    for (int i = 0; i < n; ) {
        if (formula[i] == '(') {
            elementStack.push({});
            i++;
        } else if (formula[i] == ')') {
            auto top = elementStack.top();
            elementStack.pop();
            i++;
            int start = i;
            while (i < n && isdigit(formula[i])) i++;
            int multiplier = (start == i) ? 1 : stoi(formula.substr(start, i - start));
            for (auto& p : top) {
                elementStack.top()[p.first] += p.second * multiplier;
            }
        } else {
            int start = i++;
            while (i < n && islower(formula[i])) i++;
            string element = formula.substr(start, i - start);
            start = i;
            while (i < n && isdigit(formula[i])) i++;
            int count = (start == i) ? 1 : stoi(formula.substr(start, i - start));
            elementStack.top()[element] += count;
        }
    }
    
    elementCount = elementStack.top();
    string result;
    for (auto& p : elementCount) {
        result += p.first;
        if (p.second > 1) {
            result += to_string(p.second);
        }
    }
    return result;
    }
};