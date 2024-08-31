class Solution {
public:
    string reverseParentheses(string s) {
        std::stack<std::string> st;
    std::string current;

    for (char ch : s) {
        if (ch == '(') {
            st.push(current);
            current.clear();
        } else if (ch == ')') {
            std::reverse(current.begin(), current.end());
            if (!st.empty()) {
                current = st.top() + current;
                st.pop();
            }
        } else {
            current += ch;
        }
    }

    return current;
    }
};