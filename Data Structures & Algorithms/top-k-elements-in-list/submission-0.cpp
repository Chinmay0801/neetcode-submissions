class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        // Count frequency of each element
        for (int num : nums) {
            freq[num]++;
        }

        // Bucket where index = frequency
        vector<vector<int>> bucket(nums.size() + 1);

        // Place each number into its frequency bucket
        for (auto &it : freq) {
            int number = it.first;
            int frequency = it.second;

            bucket[frequency].push_back(number);
        }

        vector<int> ans;

        // Traverse buckets from highest frequency to lowest
        for (int i = nums.size(); i >= 0; i--) {

            for (int num : bucket[i]) {
                ans.push_back(num);

                if (ans.size() == k)
                    return ans;
            }
        }

        return ans;
    }
};