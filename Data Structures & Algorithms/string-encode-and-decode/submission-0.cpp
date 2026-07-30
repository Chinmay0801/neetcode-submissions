class Solution {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {

        string ans = "";

        for (string str : strs) {
            ans += to_string(str.size()) + "#" + str;
        }

        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {

        vector<string> ans;
        int i = 0;

        while (i < s.size()) {

            int j = i;

            // Find '#'
            while (s[j] != '#')
                j++;

            int len = stoi(s.substr(i, j - i));

            j++;

            ans.push_back(s.substr(j, len));

            i = j + len;
        }

        return ans;
    }
};