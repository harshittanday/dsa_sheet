void solve(int k, int n, vector<int> &nums, int ind, vector<vector<int>> &res, vector<int> &ans)
{
    if (ind == nums.size())
    {
        if (n == 0 and ans.size() == k)
        {
            res.push_back(ans);
        }
        return;
    }
    if (n >= nums[ind])
    {
        ans.push_back(nums[ind]);
        solve(k, n - nums[ind], nums, ind + 1, res, ans);
        ans.pop_back();
    }
    solve(k, n, nums, ind + 1, res, ans);
}
vector<vector<int>> combinationSum3(int k, int n)
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<vector<int>> res;
    vector<int> ans;
    solve(k, n, nums, 0, res, ans);
    return res;
}