class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);
        vector<int> res(n, 0);
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            ans *= nums[i];
            dp1[i] = ans;
        }
        ans = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            ans *= nums[i];
            dp2[i] = ans;
        }
        res[0] = dp2[1];
        res[n - 1] = dp1[n - 2];
        for (int i = 1; i <= n - 2; i++)
        {
            res[i] = dp1[i - 1] * dp2[i + 1];
        }
        return res;
    }
};