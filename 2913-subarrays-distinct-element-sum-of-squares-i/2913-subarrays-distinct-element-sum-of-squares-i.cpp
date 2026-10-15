class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
    int ans = 0;
    vector<int> res;

       for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            res.clear();

            for (int k = i; k <= j; k++) {
                res.push_back(nums[k]);
            }

            sort(res.begin(), res.end());

            int cnt = unique(res.begin(), res.end()) - res.begin();

            ans += cnt * cnt;
        }
    }

    return ans;
    }
};