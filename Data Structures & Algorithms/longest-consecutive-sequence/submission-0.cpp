class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());  // O(n) insertion
    
    int maxStreak = 0;

    for (int num : st) {                    // iterate over set, not array
        
        if (st.find(num - 1) == st.end()) { // num is a sequence start
            
            int currentNum = num;
            int currentStreak = 1;

            while (st.count(currentNum + 1)) {  // extend the streak
                currentNum++;
                currentStreak++;
            }

            maxStreak = max(maxStreak, currentStreak);
        }
    }

    return maxStreak;
    }
};

