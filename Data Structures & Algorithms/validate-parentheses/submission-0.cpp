class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(char ch : s) {

            // Opening brackets
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {

                // No opening bracket available
                if(st.empty())
                    return false;

                // Check matching bracket
                if((ch == ')' && st.top() == '(') ||
                   (ch == '}' && st.top() == '{') ||
                   (ch == ']' && st.top() == '[')) {

                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};