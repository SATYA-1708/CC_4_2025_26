class Solution {
public:
    void solve(int start,int target,vector<int>& nums,vector<int>& temp,vector<vector<int>>&ans) {

        if (target==0) {
            ans.push_back(temp);
            return;
        }

        for (int i=start;i<nums.size();i++) {

            if (i>start&&nums[i]==nums[i-1])
                continue;
            if (nums[i]>target)
                break;
            temp.push_back(nums[i]);
            solve(i+1,target-nums[i],nums,temp,ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>&candidates,int target) {

        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,target,candidates,temp,ans);
        return ans;
    }
};