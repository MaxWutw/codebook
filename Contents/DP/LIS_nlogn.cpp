class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            int p = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
            if(p == v.size()) v.push_back(nums[i]);
            else v[p] = nums[i];
        }
        return v.size();
    }
};